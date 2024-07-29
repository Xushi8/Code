#include <algorithm>
#include <iostream>
#include <random>
#include <fstream>
#include <array>
#include <bitset>

using namespace std;
using i64 = int64_t;

int main()
{
	mt19937 rng(random_device{}());
	uniform_int_distribution<int64_t> uni(1, int64_t(9e18));
	constexpr int N = 10000000;

	ofstream ofs("/home/tom/Documents/Code/in.txt");
	ofs << N << '\n';
	for (int i = 0; i < N; i++)
	{
		ofs << bitset<60>(uni(rng)) << ' ';
    }
}