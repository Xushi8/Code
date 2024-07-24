#include <fstream>
#include <random>
#include <array>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
	ofstream ofs("/home/tom/Documents/Code/in.txt");
	mt19937 rng(random_device{}());
	constexpr int n = 3;
	uniform_int_distribution<int> uni1(1, n);
	// uniform_int_distribution<int> uni2(0, 1);
	constexpr int tt = 10;
	ofs << tt << '\n';
	for (int i = 0; i < tt; i++)
	{
		ofs << n;
		for (int j = 0; j < 3; j++)
		{
			ofs << ' ' << uni1(rng);
		}
		ofs << '\n';
	}
	ofs << '\n';
}