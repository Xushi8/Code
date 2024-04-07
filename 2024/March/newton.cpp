#include <fmt/format.h>
using fmt::print;

long double func(long double val)
{
	return val - (val * (val * val) - val - 1) / (3 * (val * val) - 1);
}


int main()
{
	long double x = 1.5L;
	for (int i = 0; i < 10; i++)
	{
		x = func(x);
		print("{} ", x);
	}
	print("\n");

	x = 0.6L;
	for (int i = 0; i < 10; i++)
	{
		x = func(x);
		print("{} ", x);
	}
	print("\n");
}