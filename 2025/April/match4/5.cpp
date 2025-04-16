// 2025/04/16 19:44:53
#ifdef LOCAL
#include <basic_std_lib.h>
#else
#include <bits/stdc++.h>
#endif
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 1e6 + 6;

void solve()
{
    constexpr int n = 24;
    array<int, n> a;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int q;
    while (cin >> q)
    {
        if (0 <= q && q < n)
        {
            cout << a[q] << ' ' << (a[q] > 50 ? "Yes" : "No") << '\n';
        }
    }
}

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
