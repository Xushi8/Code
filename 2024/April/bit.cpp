#include <bit>
#include <fmt/core.h>
using fmt::print;

int my_lg(unsigned x)
{
	return 8 * sizeof(x) - 1 - std::countl_zero(x);
}

int main()
{
	if constexpr (std::endian::native == std::endian::big)
		print("big-endian\n");
	else if constexpr (std::endian::native == std::endian::little)
		print("little-endian\n");
	else
		print("mixed-endian\n");

	for (unsigned i = 1; i < 100; i++)
	{
		print("{0} {0:b} {1} {2} \n", i, std::__lg(i), my_lg(i));
	}
}