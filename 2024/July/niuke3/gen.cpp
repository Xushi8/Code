#include <algorithm>
#include <iostream>
#include <random>
#include <fstream>

using namespace std;

int main()
{
	mt19937 rng(random_device{}());
	uniform_int_distribution<int64_t> uni(1, int64_t(1e18));
	constexpr int N = 100;
	// char arr[N];
	// iota(arr, arr + N, 'A');
	// shuffle(arr, arr + N, rng);
	// for (int i = 0; i < N; i++)
	// {
	// 	cout << arr[i];
	// }
	// cout << endl;

	ofstream ofs("/home/tom/Documents/Code/in.txt");
	ofs << N << ' ' << uni(rng) << '\n';
	for (int i = 0; i < N; i++)
	{
		ofs << uni(rng) << '\n';
	}
}