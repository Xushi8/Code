#include <iostream>
#include <fmt/format.h>
#include <execution>
#include <vector>
#include <random>
#include <tbb/parallel_sort.h>
#include <tbb/tick_count.h>
using namespace std;

void test_par()
{
	random_device rd;
	mt19937 rng(rd());
	constexpr size_t N = 1e8;
	std::vector<int> a(N);

	auto first = tbb::tick_count::now();

	std::generate(execution::par_unseq, a.begin(), a.end(), rng);
	vector<int> b = a;

	auto last = tbb::tick_count::now();
	fmt::print("Time elapsed of generating: {:.3f}s\n", (last - first).seconds());

	first = tbb::tick_count::now();

	tbb::parallel_sort(a.begin(), a.end());

	last = tbb::tick_count::now();
	fmt::print("Time elapsed of parallel sort: {:.3f}s\n", (last - first).seconds());

	first = tbb::tick_count::now();

	std::sort(execution::par, b.begin(), b.end(), less<>());

	last = tbb::tick_count::now();
	fmt::print("Time elapsed of std::sort with execution::par: {:.3f}s\n", (last - first).seconds());

	fmt::print("\n");
}

int main()
{
	test_par();
	
	return 0;
}