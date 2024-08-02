#include <algorithm>
#include <fstream>
#include <random>
#include <iostream>
using namespace std;

int main()
{
    ofstream ofs("/home/tom/Documents/Code/in.txt");
    mt19937 rng(random_device{}());
    uniform_int_distribution<int> unia(1, 200), unib(1, 100000);
    constexpr int n = 15, m = 200;
    ofs << n << ' ' << m << '\n';
    for (int i = 0; i < n; i++)
    {
        ofs << unia(rng) << ' ' << unib(rng) << '\n';
    }

    vector<int> a(m);
    generate_n(a.begin(), m, [&]()
        {
            return unia(rng);
        });
    sort(a.begin(), a.end());
    for (auto x : a)
    {
        ofs << x << ' ';
    }
    ofs << '\n';
}