#include <fmt/core.h>
#include <execution>
#include <numeric>
#include <vector>
#include <tbb/tbb.h>
#include <fstream>
using fmt::print;
using namespace std;
using namespace tbb;

vector<double> read_vec()
{
	// vector<double> res(n);
	// for (size_t i = 0; i < n; i++)
	// {
	// 	cin >> res[i];
	// }

	ifstream ifs("/home/tom/Documents/Code/in.txt", ios::binary);
	ifs.seekg(0, std::ios::end);
	const size_t n = ifs.tellg() / sizeof(double);
	print("n = {}\n", n);
	ifs.seekg(0);
	vector<double> res(n);
	ifs.read((char*)res.data(), sizeof(double) * n);

	return res;
}

double func_a(vector<double> const& vec)
{
	return reduce(execution::par, vec.begin(), vec.end());
}

double func_b(vector<double> const& vec)
{
	return parallel_reduce(blocked_range<size_t>(0, vec.size()), 0.0, [&](blocked_range<size_t> const& r, double val)
		{
			for (size_t i = r.begin(); i != r.end(); i++)
			{
				val += vec[i];
			}
			return val;
		},
		plus<>());
}

double func_c(vector<double> const& vec)
{
	return reduce(vec.begin(), vec.end());
}

double func_d(vector<double> const& vec) {
	double sum = 0;
	#pragma omp simd
	for(size_t i = 0; i < vec.size(); i++) {
		sum += vec[i];
	}
	return sum;
}

template <typename F>
std::chrono::duration<double, std::milli> time_test(F&& f)
{
	auto first = std::chrono::steady_clock::now();
	f();
	auto last = std::chrono::steady_clock::now();
	return last - first;
}

int main()
{
	auto vec = read_vec();
	double res;
	auto time_use = time_test([&]{
		res = func_a(vec);
	});
	print("res = {}, std::par:\t {}ms\n", res, time_use.count());

	time_use = time_test([&]{
		res = func_b(vec);
	});
	print("res = {}, tbb:\t\t {}ms\n", res, time_use.count());

	time_use = time_test([&]{
		res = func_c(vec);
	});
	print("res = {}, std::seq:\t {}ms\n", res, time_use.count());

	time_use = time_test([&]{
		res = func_d(vec);
	});
	print("res = {}, brute force:\t {}ms\n", res, time_use.count());

	return 0;
}