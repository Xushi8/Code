#include <algorithm>
#include <fstream>
#include <random>
#include <iostream>
using namespace std;

int main()
{
    ofstream ofs("/home/tom/Documents/Code/in.txt");
    mt19937 rng(random_device{}());
    uniform_int_distribution<int64_t> uni(1, 1000000000);
    constexpr int n = 1000;
    ofs << n << '\n';
    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a.emplace_back(i, j);
        }
    }

    std::shuffle(a.begin(), a.end(), rng);
    for (auto [x, y] : a)
    {
        ofs << x + 1 << ' ' << y + 1 << '\n';
    }
}