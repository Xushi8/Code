#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using pii = pair<int, int>;

constexpr int MOD = 998244353;
int qpow(i64 a, size_t n)
{
    i64 b = 1;
    while (n)
    {
        if (n & 1)
            b = b * a % MOD;
        a = a * a % MOD;
        n /= 2;
    }
    return b;
}

vector<int> fac, inv, inv_fac;

void init_inv(int n)
{
    fac.resize(n + 1);
    inv.resize(n + 1);
    inv_fac.resize(n + 1);
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        fac[i] = i64(fac[i - 1]) * i % MOD;
    }
    inv_fac.back() = qpow(fac.back(), MOD - 2);
    for (int i = n; i > 0; i--)
    {
        inv_fac[i - 1] = i64(inv_fac[i]) * i % MOD;
        inv[i] = inv_fac[i] * fac[i - 1];
    }
}

void solve()
{
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solve();
    }

    return 0;
}