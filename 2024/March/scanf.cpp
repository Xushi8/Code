#include <iostream>
#include <cstdio>
#include <chrono>

extern void no_use(int64_t* a, double* b) noexcept;

int main()
{
	int64_t a(0);
	double b(0.0);

	auto start = std::chrono::high_resolution_clock::now();
	while (~scanf("%ld %lf", &a, &b))
	{
		no_use(&a, &b);
	}
	auto end = std::chrono::high_resolution_clock::now();

	auto take_time =
		std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	std::cout << take_time.count() << " us\n";

	return 0;
}