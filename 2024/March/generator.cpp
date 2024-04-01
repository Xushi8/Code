#include <iostream>
#include <fstream>
#include <random>
using std::cin;

int main()
{
	std::mt19937 rng(std::random_device{}());
	std::uniform_int_distribution<int64_t> uni;
	std::uniform_real_distribution<double> unf;
	std::ofstream ofs("b.txt");
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		ofs << uni(rng) << ' ' << unf(rng) << '\n';
    }
}