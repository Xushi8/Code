#include <fmt/os.h>
#include <random>
using namespace std;
using namespace fmt;

int main()
{
	constexpr size_t n = 100;
	random_device rd;
	mt19937 rng(rd());
	uniform_real_distribution<double> und(0, 134897134.2148990);

	auto out = output_file("/home/tom/Documents/Code/in.txt", buffer_size = 8192);
	out.print("{}\n", n);
	for (size_t i = 0; i < n; i++)
	{
		out.print("{}{}", und(rng), " \n"[i + 1 == n]);
	}
	out.print("{}\n", n);
	for (size_t i = 0; i < n; i++)
	{
		out.print("{}{}", und(rng), " \n"[i + 1 == n]);
	}
	return 0;
}