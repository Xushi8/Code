#include <fstream>
#include <cstddef>
#include <vector>
using namespace std;

int main()
{
	ofstream ofs("test.txt");
	constexpr size_t n = 1000000000;
	vector<size_t> a(n, 0x3f3f3f3f3f3f3f3f);
	ofs.write(reinterpret_cast<const char*>(a.data()), a.size() * sizeof(size_t));
    
	return 0;
}