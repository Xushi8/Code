#include <fstream>
#include <random>
#include <iostream>
using namespace std;

int main()
{
    ofstream ofs("/home/tom/Documents/Code/in.txt");
    mt19937 rng(random_device{}());
    uniform_int_distribution<int> unia(1, 1000000), unib(1, 1000000), unic(0, 100000000);
    constexpr int N = 200000;
    ofs << N << '\n';
    for (int i = 0; i < N; i++)
    {
        // int x = unia(rng);
        int x = 10;
        ofs << x << ' ' << x - 1 << ' ' << unic(rng) << '\n';
    }
}