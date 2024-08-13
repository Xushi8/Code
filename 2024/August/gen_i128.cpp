#include <fstream>
#include <random>
#include <iostream>
using namespace std;

int main()
{
    ofstream ofs("/home/tom/Documents/Code/in.txt");
    mt19937 rng(random_device{}());
    uniform_int_distribution<int64_t> uni(1, int64_t(9e18));
    constexpr int n = 10;
    ofs << n << '\n';
    for (int i = 0; i < n; i++)
    {
        ofs << uni(rng) << uni(rng) << '\n';
    }
}