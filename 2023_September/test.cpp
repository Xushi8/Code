#include <iostream>
#include <algorithm>
#include <utility>
#include <format>
#include <memory>
#include <vector>
#include <cstring>
using namespace std;

int add(int a, int b)
{
    return a + b;
}

void func1(vector<int>& arr, int n)
{
    int* a = arr.data();
    a = std::assume_aligned<16>(a);
    n = n / 16 * 16;
#pragma omp simd
    for (int i = 0; i < n; i++)
    {
        a[i] = 0;
    }
}

void func2(int* a)
{
    memset(a, 0, 1024 * 4);
}

int main() {
    // int sum = add(1, 2);
    // std::cout << sum << std::endl;
    // std::cout << std::format("{} {} {}", 34, 234, 234432) << '\n';

    // cout << (make_pair(1, 5) > make_pair(1, (int)1e9 + 5) ? "YES\n" : "NO\n");

    return 0;
}
