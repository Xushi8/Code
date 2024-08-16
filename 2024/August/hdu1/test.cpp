#include <iostream>
#include <map>
#include <algorithm>
#include <numeric>
#include <vector>
#include <fmt/format.h>
#include <fmt/ranges.h>
using fmt::print;
using namespace std;

#include <cstdint>
#include <limits>
using u64 = uint64_t;
constexpr u64 MOD = 1e9 + 7;
constexpr u64 MOD1 = std::numeric_limits<u64>::max();

u64 func(u64 x)
{
    return x % MOD;
}

u64 func1(u64 x)
{
    return x % MOD;
}

int main()
{
    // // map<int, int> mp;
    // // while (auto it = mp.begin(); it != mp.end())
    // // {
    // //     if (false)
    // //         break;
    // // }

    // vector<int> a(10);
    // iota(a.begin(), a.end(), 1);
    // print("{}\n", a);

    // rotate(a.begin(), a.begin() + 2, a.end());
    // print("{}\n", a);

    // sort(a.begin(), a.end());

    // rotate(a.rbegin(), a.rbegin() + 2, a.rend());
    // print("{}\n", a);

    constexpr int n = 1000000;
    double ans = 0;
    for (int i = 1; i < 1000000; i++)
    {
        ans += 1.0 * n / i;
    }
    cout << ans << '\n';
}