#include <random>
#include <fstream>

using namespace std;

int main()
{
	std::ofstream ofs("/home/tom/Documents/Code/in.txt");
	mt19937 rng(random_device{}());
	char arr[4] = {'A', 'W', 'S', 'D'};
	uniform_int_distribution<int> uni(-100000, 100000);
	const int n = rng() % 200000 + 1;
	ofs << n << ' ' << uni(rng) << ' ' << uni(rng) << '\n';
	for (int i = 0; i < n; i++)
	{
		ofs << arr[rng() % 4];
    }
}