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

int main()
{
	auto vec = read_vec();
	auto t_begin = tick_count::now();
	auto t_end = tick_count::now();
	auto a = func_a(vec);
	t_end = tick_count::now();
	print("a = {}\npar reduce use: {}s\n", a, (t_end - t_begin).seconds());

	t_begin = tick_count::now();
	auto b = func_b(vec);
	t_end = tick_count::now();
	print("b = {}\nparallel_reduce use: {}s\n", b, (t_end - t_begin).seconds());

	t_begin = tick_count::now();
	auto c = func_c(vec);
	t_end = tick_count::now();
	print("c = {}\nreduce use: {}s\n", c, (t_end - t_begin).seconds());

	return 0;
}