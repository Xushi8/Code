#include <iostream>
#include <vector>
#include <gmpxx.h>
using namespace std;
using big_int = mpz_class;

vector<vector<big_int>> operator*(vector<vector<big_int>> const& a, vector<vector<big_int>> const& b)
{
	vector<vector<big_int>> c(a.size(), vector<big_int>(b[0].size(), 0));
	for (size_t i = 0; i < a.size(); i++)
	{
		for (size_t j = 0; j < b[0].size(); j++)
		{
			for (size_t k = 0; k < a[0].size(); k++)
			{
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	return c;
}

vector<vector<big_int>> fast_pow(vector<vector<big_int>> a, size_t n)
{
	vector<vector<big_int>> b(a.size(), vector<big_int>(a.size()));
	for (size_t i = 0; i < b.size(); i++)
	{
		b[i][i] = 1;
	}
	while (n)
	{
		if (n & 1) b = b * a;
		a = a * a;
		n /= 2;
	}
	return b;
}

big_int fib(size_t n)
{
	if (n == 0 || n == 1 || n == 2)
	{
		return 1;
	}

	vector<vector<big_int>> a = {
		{1, 1},
		{1, 0},
	};

	a = fast_pow(a, n - 1);
	vector<vector<big_int>> b = {
		{1},
		{0},
	};

	auto c = a * b;
	return c[0][0];
}

int main()
{
	// string s;
	// vector<int> a;
	// // s.assign(a.begin(), a.end());
	// s.assign(a.data(), a.data() + a.size());

	int n;
	cin >> n;

	// cout << mpz_class::fibonacci(n) << endl;
	cout << fib(n) << endl;

	return 0;
}