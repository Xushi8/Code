#include <random>
#include <fstream>
#include <vector>
#include <algorithm>
#include <execution>
using namespace std;

int main()
{
	constexpr size_t n = 1e9;
	ofstream ofs("/home/tom/Documents/Code/in.txt", ios::binary);
	mt19937 rng(random_device{}());
	uniform_real_distribution<double> unf(0, 100);
	// ofs << n << '\n';
	// for (size_t i = 0; i < n; i++)
	// {
	// 	ofs << unf(rng) << ' ';
	// }

	vector<double> a(n);
	generate_n(std::execution::par_unseq, a.begin(), n, [&]{
		return unf(rng);
	});

	ofs.write((const char*)a.data(), a.size() * sizeof(double));
    
	return 0;
}