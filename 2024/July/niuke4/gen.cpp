#include <algorithm>
#include <iostream>
#include <random>
#include <fstream>
#include <array>

using namespace std;
using i64 = int64_t;

int main()
{
	mt19937 rng(random_device{}());
	uniform_int_distribution<int64_t> uni(1, int64_t(23));
	constexpr int N = 10;


	ofstream ofs("/home/tom/Documents/Code/in.txt");
	vector<i64> a(N);
	for (int i = 0; i < N; i++)
	{
		a[i] = uni(rng);
	}
	ofs << 1 << '\n';
	ofs << N << '\n';
	for (auto x : a)
	{
		ofs << x << ' ';
	}
	ofs << '\n';
}