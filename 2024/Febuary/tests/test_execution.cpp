#include <iostream>
#include <fmt/format.h>
#include <execution>
#include <vector>
#include <random>
using namespace std;

int main()
{
	random_device rd;
	mt19937 rng(rd());
	uniform_int_distribution<int> uni(-100000, 100000);
	constexpr size_t n = 100000000;
	vector<int> a(n);
	for (auto& x : a)
	{
		x = uni(rng);
    }

	sort(execution::par, a.begin(), a.end());
	
	return 0;
}