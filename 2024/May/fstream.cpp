#include <fstream>
#include <fmt/core.h>
#include <array>
using fmt::print;
using namespace std;

int main()
{
	ifstream ifs("test.txt");
	if (ifs.fail())
	{
		print(stderr, "open file error!\n");
		perror("main");
		exit(1);
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
		print("{}\n", buf.data());
	}
	
	return 0;
}