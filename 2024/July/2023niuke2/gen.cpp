#include <fstream>
#include <random>
using namespace std;

int main()
{
	ofstream ofs("/home/tom/Documents/Code/in.txt", ios::app);
	mt19937 rng(random_device{}());
	constexpr int n = 10;
	uniform_int_distribution<int> uni1(0, 9);
	uniform_int_distribution<int> uni2(0, 1);
	ofs << n << '\n';
	for (int i = 0; i < n; i++)
	{
		ofs << uni1(rng) << " \n"[i == n - 1];
	}
	for (int i = 0; i < n; i++)
	{
		ofs << uni2(rng) << " \n"[i == n - 1];
	}
	ofs << '\n';
}