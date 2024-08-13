#include <fstream>
#include <random>
#include <iostream>
using namespace std;

int main()
{
    ofstream ofs("/home/tom/Documents/Code/in.txt");
    mt19937 rng(random_device{}());
    uniform_int_distribution<uint64_t> uni(0, UINT64_MAX);
    constexpr int n = 100000 / 2;
    for (int i = 0; i < n; i++)
    {
        ofs << uni(rng);
    }
    ofs << '\n';
    for (int i = 0; i < n; i++)
    {
        ofs << uni(rng);
    }
    ofs << '\n';
}