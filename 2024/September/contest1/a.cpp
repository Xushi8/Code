// 2024/09/28 13:14:21
#ifdef LOCAL
#include <basic_std_lib.h>
#else
#include <bits/stdc++.h>
#endif
using namespace std;

void solve();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    tt = 1;
    while (tt--)
    {
        solve();
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}

using i64 = int64_t;
using u64 = uint64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 1000005;

int get_min(int a1, int a2, int k1, int k2, int n)
{
    n -= a1 * (k1 - 1) + a2 * (k2 - 1);
    if (n > 0)
        return min(n, a1 + a2);
    return 0;
}

int get_max(int a1, int a2, int k1, int k2, int n)
{
    int res = 0;
    if (k1 < k2)
    {
        int t = n / k1;
        t = min(t, a1);
        res += t;
        n -= t * k1;
        t = n / k2;
        t = min(t, a2);
        res += t;
        n -= t * k2;
    }
    else
    {
        int t = n / k2;
        t = min(t, a2);
        res += t;
        n -= t * k2;
        t = n / k1;
        t = min(t, a1);
        res += t;
        n -= t * k1;
    }

    return res;
}

void solve()
{
    int a1, a2, k1, k2, n;
    cin >> a1 >> a2 >> k1 >> k2 >> n;

    cout << get_min(a1, a2, k1, k2, n) << ' ' << get_max(a1, a2, k1, k2, n) << '\n';
}