#include <xxhash.hpp>
#include <iostream>
#include <cstdint>
#include <fstream>
#include <fmt/core.h>
using fmt::print;
using i64 = int64_t;
using u64 = uint64_t;
using namespace std;

/**
 * @brief
 *
 * @tparam bit_mode
 * @param file_name
 * @return xxh::hash_t<bit_mode>
 * if bit_mode == 64 than return type is uint64_t
 * otherwise bit_mode == 128 and return type is xxh::uint128_t
 */
template <size_t bit_mode = 64>
xxh::hash_t<bit_mode> hash_from_file(string_view file_name)
{
	static_assert(bit_mode == 64 || bit_mode == 128, "xxhash3 can only be used in 64 and 128 bit modes.");
	xxh::hash3_state_t<bit_mode> hash_stream;
	ifstream ifs(file_name.data());
	if (ifs.fail())
	{
		print(stderr, "Open file error!\n");
		perror("hash_from_file");
		return {};
	}
	ifs.seekg(0, std::ios::end);
	const size_t n = ifs.tellg() / sizeof(char);
	ifs.seekg(0);
	size_t now_siz = 0;
	array<char, 32 * 1024> buf;
	while (now_siz < n)
	{
		size_t adds = min(n - now_siz, size_t(32) * 1024);
		now_siz += adds;
		ifs.read(buf.data(), adds);
		hash_stream.update(buf);
	}
	return hash_stream.digest();
}

int main()
{
	// standalone hash
	std::array<i64, 5> input{322, 2137, 42069, 65536, 2147483648};
	xxh::hash_t<64> hash = xxh::xxhash3<64>(input);
	cout << hash << endl;

	// hash streaming
	u64 final_hash = hash_from_file("test.txt");
	static_assert(is_same_v<u64, xxh::hash_t<64>>);
	cout << final_hash << endl;

	return 0;
}