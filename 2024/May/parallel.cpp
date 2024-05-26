#include <tbb/parallel_for.h>
#include <tbb/parallel_for_each.h>
#include <tbb/tick_count.h>
#include <vector>
#include <cstdint>
#include <execution>
#include <iostream>
#include <fmt/core.h>
using namespace std;
using fmt::print;
using u32 = uint32_t;

void no_use(vector<u32>& a);

void func(vector<u32>& a)
{
	for (auto& x : a)
	{
		x = ~x;
	}
}

void func_std(vector<u32>& a)
{
	for_each(std::execution::par, a.begin(), a.end(), [&](u32& x)
		{
			x = ~x;
		});
}

void func_std1(vector<u32>& a)
{
	for_each(std::execution::unseq, a.begin(), a.end(), [&](u32& x)
		{
			x = ~x;
		});
}

void func_for(vector<u32>& a)
{
	tbb::parallel_for(tbb::blocked_range<size_t>(0, a.size()), [&](tbb::blocked_range<size_t> const& r)
		{
			for (size_t i = r.begin(); i != r.end(); i++)
			{
				a[i] = ~a[i];
			}
		});
}

void func_for_each(vector<u32>& a)
{
	tbb::parallel_for_each(a.begin(), a.end(), [&](u32& x)
		{
			x = ~x;
		});
}

int main()
{
	size_t n;
	u32 val;
	cin >> n >> val;
	vector<u32> a(n, val);
	auto t_begin = tbb::tick_count::now();
	auto t_end = tbb::tick_count::now();

	t_begin = tbb::tick_count::now();
	func(a);
	no_use(a);
	t_end = tbb::tick_count::now();
	print("func: {}s\n", (t_end - t_begin).seconds());

	t_begin = tbb::tick_count::now();
	func_std(a);
	no_use(a);
	t_end = tbb::tick_count::now();
	print("func_std: {}s\n", (t_end - t_begin).seconds());

	t_begin = tbb::tick_count::now();
	func_std1(a);
	no_use(a);
	t_end = tbb::tick_count::now();
	print("func_std1: {}s\n", (t_end - t_begin).seconds());

	t_begin = tbb::tick_count::now();
	func_for(a);
	no_use(a);
	t_end = tbb::tick_count::now();
	print("func_for: {}s\n", (t_end - t_begin).seconds());

	t_begin = tbb::tick_count::now();
	func_for_each(a);
	no_use(a);
	t_end = tbb::tick_count::now();
	print("func_for_each: {}s\n", (t_end - t_begin).seconds());

	return 0;
}