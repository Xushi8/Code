#include <iostream>
#include <vector>
#include <string_view>
#include <algorithm>
#include <cstdint>
// #include <tbb/parallel_invoke.h>
using i64 = int64_t;
using namespace std;

void print(string_view name, vector<double> const& val)
{
	cout << name << '\n';
	for (auto x : val)
	{
		// print("{}\n", x);
		cout << x << ' ';
	}
	cout << '\n' << '\n';
}

// 列主元高斯消去法
vector<double> Gauss(vector<vector<double>> const& val)
{
	auto a = val;
	vector<double> b(a.size(), 1.0);
	const size_t n = a.size();
	for (size_t j = 0; j < n; j++)
	{
		// 获得最大的主元并交换
		double maxx = abs(a[j][j]);
		size_t index = j;
		for (size_t i = j + 1; i < n; i++)
		{
			if (maxx < abs(a[i][j]))
			{
				maxx = abs(a[i][j]);
				index = i;
			}
		}
		if (j != index)
		{
			swap(a[j], a[index]);
			swap(b[j], b[index]);
		}

		// 消去
		for (size_t i = j + 1; i < n; i++)
		{
			const double num = a[i][j] / a[j][j];
			for (size_t k = j; k < n; k++)
			{
				a[i][k] -= a[j][k] * num;
			}
			b[i] -= b[j] * num;
		}
	}

	// 得到精确解
	vector<double> res(n);
	for (i64 i = n - 1; i >= 0; i--)
	{
		for (size_t j = i + 1; j < n; j++)
		{
			b[i] -= res[j] * a[i][j];
		}
		res[i] = b[i] / a[i][i];
	}

	return res;
}

vector<double> J(vector<vector<double>> const& val, const size_t count, const bool do_print = false)
{
	auto a = val;
	const size_t n = a.size();
	vector<double> b(n, 1.0);
	vector<double> x(n, 0);

	for (size_t cnt = 0; cnt < count; cnt++)
	{
		auto tx = x;
		for (size_t i = 0; i < n; i++)
		{
			double num = b[i];
			for (size_t j = 0; j < n; j++)
			{
				if (j == i)
					continue;
				num -= a[i][j] * tx[j];
			}
			x[i] = (1.0 / a[i][i]) * num;
		}
		x = std::move(tx);
		if (do_print) [[unlikely]]
		{
			print("J", x);
		}
	}

	return x;
}

vector<double> GS(vector<vector<double>> const& val, const size_t count, const bool do_print = false)
{
	auto a = val;
	const size_t n = a.size();
	vector<double> b(n, 1.0);
	vector<double> x(n, 0);

	for (size_t cnt = 0; cnt < count; cnt++)
	{
		auto& tx = x;
		for (size_t i = 0; i < n; i++)
		{
			double num = b[i];
			for (size_t j = 0; j < n; j++)
			{
				if (j == i)
					continue;
				num -= a[i][j] * tx[j];
			}
			x[i] = (1.0 / a[i][i]) * num;
		}

		if (do_print) [[unlikely]]
		{
			print("GS", x);
		}
	}

	return x;
}

vector<double> SOR(vector<vector<double>> const& val, const double ω, const size_t count, const bool do_print = false)
{
	auto a = val;
	const size_t n = a.size();
	vector<double> b(n, 1.0);
	vector<double> x(n, 0);

	for (size_t cnt = 0; cnt < count; cnt++)
	{
		auto& tx = x;
		for (size_t i = 0; i < n; i++)
		{
			double num = b[i];
			for (size_t j = 0; j < n; j++)
			{
				if (j == i)
					continue;
				num -= a[i][j] * tx[j];
			}
			x[i] = (ω / a[i][i]) * num;
		}

		if (do_print) [[unlikely]]
		{
			print("SOR, ω = " + to_string(ω), x);
		}
	}

	return x;
}

int main()
{
	constexpr size_t weidu = 6;
	vector<vector<double>> arr(weidu, vector<double>(weidu));
	for (size_t i = 0; i < weidu; i++)
	{
		for (size_t j = 0; j < weidu; j++)
		{
			arr[i][j] = 1.0 / ((i + 1) + (j + 1) - 1);
		}
	}

	constexpr size_t count = 1000000; // 迭代次数

	print("Gauss", Gauss(arr));

	print("J", J(arr, count));

	print("GS", GS(arr, count));

	print("SOR, ω = " + to_string(0.8), SOR(arr, 0.8, count));
	print("SOR, ω = " + to_string(0.99), SOR(arr, 0.95, count));
	print("SOR, ω = " + to_string(1.01), SOR(arr, 1.01, count));

	// tbb::parallel_invoke([&]
	// 	{
	// 		print("Gauss", Gauss(arr));
	// 	},
	// 	[&]
	// 	{
	// 		print("J", J(arr, count));
	// 	},
	// 	[&]
	// 	{
	// 		print("GS", GS(arr, count));
	// 	},
	// 	[&]
	// 	{
	// 		print("SOR, ω = " + to_string(0.8), SOR(arr, 0.8, count));
	// 	},
	// 	[&]
	// 	{
	// 		print("SOR, ω = " + to_string(0.99), SOR(arr, 0.95, count));
	// 	},
	// 	[&]
	// 	{
	// 		print("SOR, ω = " + to_string(1.01), SOR(arr, 1.01, count));
	// 	});
}