// 2023/07/30 13:34:45
#ifndef DEBUG
// #pragma GCC optimize(2)
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
const int MOD = (int)(1e4 + 7);
const int N = 1005;

int C[N][N];
ll fact[N], infact[N];

ll qmi(ll a, ll n, ll mod)
{
    ll res = 1;
    a %= mod;
    while (n > 0)
    {
        if (n & 1)
            res = res * a % mod;
        a = a * a % mod;
        n /= 2;
    }

    return res;
}


void init()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0)
                C[i][j] = 1;
            else
                C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
        }
    }
}

void init1()
{
    fact[0] = infact[0] = 1;
    for (int i = 1; i < N; i++)
    {
        fact[i] = fact[i - 1] * i % MOD;
        infact[i] = infact[i - 1] * qmi(i, MOD - 2, MOD) % MOD;
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    init1();
    ll a, b, k, n, m;
    cin >> a >> b >> k >> n >> m;
    a %= MOD;
    b %= MOD;

    ll ans = qmi(a, n, MOD) * qmi(b, m, MOD) % MOD * fact[k] % MOD * infact[n] % MOD * infact[k - n] % MOD;
    cout << ans << '\n';


    cout << endl;
    return 0;
}