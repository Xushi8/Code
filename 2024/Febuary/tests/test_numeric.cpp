#include <fmt/format.h>
#include <numeric>
#include <vector>
#include <tbb/parallel_reduce.h>
#include <tbb/blocked_range.h>
#include <tbb/tick_count.h>
#include <cstdint>
#include <iostream>
#include <execution>
using namespace std;
using namespace fmt;
using namespace tbb;

void test_reduce()
{
	size_t n;
	double val;
	cin >> n >> val;
	vector<double> a(n, val);

	auto first = tick_count::now();
	double res = reduce(execution::par_unseq, a.begin(), a.end(), 0.0);
	// double res = 0;
	// for (auto x : a)
	// {
	// 	res += x;
	// }
	auto last = tick_count::now();
	print("res = {}\nTime elapsed of res: {}s\n", res, (last - first).seconds());
	vector<double>().swap(a);

	cin >> n >> val;
	vector<double> b(n, val);
	first = tick_count::now();
	double res1 = parallel_reduce(
		blocked_range<vector<double>::iterator>(b.begin(), b.end()), double(0), [](blocked_range<vector<double>::iterator> const& r, double local_res)
		{
			return reduce(execution::par, r.begin(), r.end(), local_res);
		},
		plus<>());
	last = tick_count::now();

	print("res1 = {}\nTime elapsed of res1: {}s\n", res1, (last - first).seconds());
}

void test_transform_reduce()
{
	size_t n;
	cin >> n;
	vector<double> a(n);
	for (size_t i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	auto first = tick_count::now();
	double res = transform_reduce(execution::par, a.begin(), a.end(), 0.0, plus<>(), [](double x)
		{
			return x * x;
		});
	auto last = tick_count::now();
	print("res = {}\nTime elapsed of res: {}s\n", res, (last - first).seconds());

	cin >> n;
	vector<double> b(n);
	for (size_t i = 0; i < n; i++)
	{
		cin >> b[i];
	}
	first = tick_count::now();
	double res1 = parallel_reduce(
		blocked_range<vector<double>::iterator>(b.begin(), b.end()), 0.0, [](blocked_range<vector<double>::iterator> const& r, double local_res)
		{
			return transform_reduce(execution::par, r.begin(), r.end(), local_res, plus<>(), [](double x)
				{
					return x * x;
				});
		},
		plus<>());
	last = tick_count::now();
	print("res1 = {}\n, Time elapsed of res1: {}s\n", res1, (last - first).seconds());
}

void test_partial_sum()
{
	size_t n;
	int val;
	cin >> n >> val;
	vector<int> a(n, val);
	partial_sum(a.cbegin(), a.cend(), ostream_iterator<int>(cout, " "));
	cout << '\n';

	partial_sum(a.begin(), a.end(), a.begin(), multiplies<>());
	cout << '\n';
}

void test_inclusive_scan()
{
	size_t n;
	int val;
	cin >> n >> val;
	vector<int> a(n, val);
	inclusive_scan(execution::par, a.begin(), a.end(), a.begin());
	for (auto x : a)
	{
		cout << x << ' ';
	}
	cout << '\n';
}

int main()
{
	test_reduce();
	// test_transform_reduce();
	// test_partial_sum();
	// test_inclusive_scan();
	return 0;
}