#include <fstream>
#include <random>

using namespace std;

int main()
{
    ofstream ofs("/home/tom/Documents/Code/in.txt");
    ofs << 1 << '\n';
    constexpr int n = 2e5;
    for (int i = 0; i < n / 2; i++)
    {
        ofs << 2;
    }
    for (int i = n / 2; i < n; i++)
    {
        ofs << (i % 2);
    }
    ofs << '\n';
}