#include <fstream>
#include <cstddef>
#include <vector>
#include <cstdint>
using namespace std;

int main()
{
	ofstream ofs("/media/tom/Data/test.txt");
	constexpr size_t n = 1000000000;
	vector<size_t> a(n, 0x3f3f3f3f3f3f3f3f);
	// for (int i = 0; i < 10; i++)
	// {
	ofs.write(reinterpret_cast<const char*>(a.data()), a.size() * sizeof(size_t));
	// }


	return 0;
}