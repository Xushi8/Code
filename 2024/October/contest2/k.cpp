// 2024/10/13 18:24:00
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
    int n;
    cin >> n;
    vector<pll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }

    sort(a.begin(), a.end(), [](pll const& lhs, pll const& rhs)
        {
            auto [x1, y1] = lhs;
            auto [x2, y2] = rhs;
            return x1 * x1 + y1 * y1 > x2 * x2 + y2 * y2;
            // return lhs.first * lhs.first + lhs.second + lhs.second > rhs.first * rhs.first + rhs.second * rhs.second;
        });

    cout << "YES\n";
    for (int i = 0; i < n - 1; i++)
    {
        cout << a[i].first << ' ' << a[i].second << '\n';
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
