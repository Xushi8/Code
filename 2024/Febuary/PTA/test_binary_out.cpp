#include <iostream>
#include <fstream>
#include <chrono>
#include <fmt/os.h>
#include <vector>
using namespace std::chrono;
using namespace std;
using namespace fmt;
constexpr size_t n = 100000000;

void binary_out()
{
    std::ofstream fout("filename.data", std::ios::out | std::ios::binary);

    vector<double> tmp(n);
    for (size_t i = 0; i < n; i++)
    {
        tmp[i] = rand() / 1000000.0;
    }
    fout.write(reinterpret_cast<const char*>(tmp.data()), sizeof(tmp[0]) * tmp.size());

    // for (auto x : tmp)
    // {
    //     cout << x << '\n';
    // }
}

void fmt_out()
{
    auto out = output_file("filename.txt", fmt::buffer_size = 8192);

    out.print("{}", n);
    for (size_t i = 0; i < n; i++)
    {
        double x = rand() / 2.0;
        out.print("{}", x);
    }
}

int main()
{
    srand((unsigned)time(nullptr));
    binary_out();
    // fmt_out();
    return 0;
}