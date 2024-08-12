#include <fstream>
#include <random>
#include <iostream>
using namespace std;

int main()
{
    ofstream ofs("/home/tom/Documents/Code/in.txt");
    mt19937 rng(random_device{}());
    uniform_int_distribution<int64_t> uni(1, 1000000000000);
    constexpr int n = 100;
    ofs << n << '\n';
    for (int i = 0; i < n; i++)
    {
        ofs << uni(rng) << '\n';
    }
}