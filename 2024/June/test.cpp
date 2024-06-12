#include <chrono>
#include <fmt/core.h>
using fmt::print;

int main()
{
	auto t_begin = std::chrono::steady_clock::now();

	for (int b = 10; b < 100; b++)
	{
		for (int c = 1000; c < 10000; c++)
		{
			if (c / 100 % 10 == 8)
			{
				int a = b * c;
				if (100000 <= a && a < 1000000)
				{
					print("a = {}, b = {}, c = {}\n", a, b, c);
				}
			}
		}
	}

	auto t_end = std::chrono::steady_clock::now();
	print("Time elapsed: {}s\n", std::chrono::duration_cast<std::chrono::nanoseconds>(t_end - t_begin).count() / 1e9);

	print("{}\n", std::chrono::duration_cast<std::chrono::nanoseconds>(t_begin.time_since_epoch()).count());
	print("{}\n", t_end.time_since_epoch().count());

	using a = std::ratio<1, 7>;
	using b = std::ratio<1, 6>;
	using c = std::ratio_add<a, b>::type;
	return 0;
}