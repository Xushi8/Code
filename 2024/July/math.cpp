#include <random>
#include <vector>
#include <fmt/format.h>
#include <numeric>
#include <execution>
using fmt::print;
using namespace std;

int main()
{
	mt19937 rng(random_device{}());
	uniform_real_distribution<double> unf(0, 1);

	auto func = [&]()
	{
		double x = 0;
		double y;
		while (x < 1.0)
		{
			y = x;
			x += unf(rng);
		}
		return y;
	};

	constexpr size_t n = 100000000;
	vector<double> arr(n);
	for_each(std::execution::par_unseq, arr.begin(), arr.end(), [&](double& val)
		{
			val = func();
		});

	double sum = reduce(std::execution::par_unseq, arr.begin(), arr.end());
	print("Average: {}\n", sum / n);
	return 0;
}