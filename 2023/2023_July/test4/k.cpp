// 2023/07/28 19:57:57
#ifndef DEBUG
#pragma GCC optimize(2)
#endif
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
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 10007;
const int N = 10020;

int sum[N];

int pow(int a, int n, int mod)
{
    int res = 1;
    while (n > 0)
    {
        if (n & 1)
            res = res * a % mod;
        a = a * a % mod;
        n /= 2;
    }

    return res;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= MOD; i++)
    {
        sum[i] = (sum[i - 1] + pow(i, k, MOD)) % MOD;
    }
    int ans = (sum[MOD] * n / MOD) % MOD;
    ans = (ans + sum[n % MOD]) % MOD;
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tt;
    cin >> tt;
    while (tt--)
    {
        solve();
    }

    cout << endl;
    return 0;
}