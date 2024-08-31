#include <fstream>
#include <random>
using namespace std;

int main()
{
    ofstream ofs("/home/tom/Documents/Code/in.txt");
    mt19937 rng(random_device{}());
    uniform_int_distribution<uint32_t> uni(0, 1e9);
    constexpr size_t n = 10000000;
    ofs << n << '\n';
    for (size_t i = 0; i < n; i++)
    {
        ofs << uni(rng) << ' ';
    }
}
