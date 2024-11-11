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

int the_inv(int x)
{
    return qpow(x, MOD - 2);
}

void dfs(int x, int y, int p0, int p1, i64 &ans, int a0, int a1, int b, i64 sna)
{
    ans += MOD;
    ans %= MOD;
    sna += MOD;
    sna %= MOD;
    if (x == 0 || y == 0)
    {
        return;
    }
    if (x > y)
    {
        // ans *= (1 - qpow(p1, x / y));
        i64 tmp = qpow(b, x / y) - qpow(a1, x / y);
        tmp *= the_inv(qpow(b, x / y));
        tmp %= MOD;
        ans += (tmp * sna) % MOD;
        ans %= MOD;
        sna *= qpow(p1, x / y);
        sna %= MOD;
        x = x % y;
        dfs(x, y, p0, p1, ans, a0, a1, b, sna);
    }
    else if (x < y)
    {
        sna *= qpow(p0, y / x);
        sna %= MOD;
        ans += sna;
        ans %= MOD;
        y = y % x;
        dfs(x, y, p0, p1, ans, a0, a1, b, sna);
    }
    else
    {
        ans += (p0 * sna) % MOD;
        ans %= MOD;
    }
    ans += MOD;
    ans %= MOD;
}

void solve()
{
    int x, y;
    cin >> x >> y;
    int a0, a1, b;
    cin >> a0 >> a1 >> b;
    int p0 = a0 * the_inv(a0 + a1) % MOD;
    int p1 = a1 * the_inv(a0 + a1) % MOD;

    i64 ans = 0;
    i64 sna = 1;
    dfs(x, y, p0, p1, ans, a0, a1, a0 + a1, sna);
    // cout << p0 << ' ' << i64(p0) * 2 % MOD << '\n';
    cout << ans << '\n';
    // cout << ans * 125 * 125 % MOD << '\n';
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