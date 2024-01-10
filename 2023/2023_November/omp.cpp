// 2023/11/29 13:41:28
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdint>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <functional>
#include <iomanip>
#include <cmath>
#include <stack>
#include <array>
#include <fstream>
#include <bitset>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 1000005;

void func1(std::vector<int>& a)
{
// #pragma omp simd
    for (auto it = a.begin(); it != a.end(); it++)
    {
        *it = 13;
    }
}

void func2(int* a, size_t n)
{
#pragma omp simd
    for (size_t i = 0; i < n; i++)
    {
        a[i] = 13;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> a(N);
    int* b = new int[N];
    func1(a);
    func2(b, N);

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}