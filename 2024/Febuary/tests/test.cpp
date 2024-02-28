#include <cassert>
#include <random>
#include <chrono>
#include <fmt/std.h>
#include <fmt/core.h>
#include <fmt/format.h>
#include <numeric>
#include <cstdint>
#include <bitset>
#include <string>
#include <vector>
using namespace std;
using namespace fmt;

void func1(vector<float>& a, vector<float> const& b)
{
	#pragma omp simd
	for (size_t i = 0; i < b.size(); i++)
	{
		a[i] = b[i] + 1;
	}
}

int main()
{
	// fmt::print("{}\n", std::has_single_bit(static_cast<__int128>(8)));
	// __uint128_t x = UINT64_MAX, y = UINT64_MAX;
	// __uint128_t z = x + y;
	// for (int i = 0; i < 128; i++)
	// {
	// 	fmt::print("{}", (z >> i) & 1);
	// }
	// fmt::print("\n");
	// fmt::print("{}\n", std::__popcount(z));

	// std::string s;
	// s += "klsdkla";
	// s.append("ksdjl");

	// mt19937_64 rng(random_device{}());
	// constexpr size_t n = 100000000;
	// vector<int> arr(n);
	// for (size_t i = 0; i < n; i++)
	// {
	// 	arr[i] = std::popcount(rng());
	// }

	// print("{}\n", __cplusplus);

	// ofstream ofs("test.txt", ios::binary);
	// ofs.write(reinterpret_cast<const char*>(arr.data()), arr.size() * sizeof(int));

	// fmt::print(stderr, "Time elapsed: {}ms\n", clock() / 1000.);

}