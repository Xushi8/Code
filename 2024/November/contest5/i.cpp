// 2024/11/09 13:48:20
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
    int n, q;
    cin >> n >> q;
    vector<pii> a(n);
    for (auto& [x, y] : a)
    {
        cin >> x >> y;
    }

    vector<array<int, 3>> pass(q);
    for (auto& [x, y, z] : pass)
    {
        cin >> x >> y >> z;
    }

    vector<i64> dp(a.back().first + 1);

    for (auto [x, y] : a)
    {
        dp[x] += y;
    }
    inclusive_scan(dp.begin(), dp.end(), dp.begin());

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < q; j++)
        {
            auto [per, day, cost] = pass[j];
            i64 sum = 0;
            for (int k = 0; k < day && i + k < n && a[i + k].first < dp.size() && a[i + k].first - a[i].first < per; k++)
            {
                sum += a[i + k].second;
                dp[a[i + k].first] = min(dp[a[i + k].first], dp[a[i + k].first] - sum + cost);
            }
            // dp[a[i].first] = min(dp[a[i].first], dp[a[i].first] - a[i].second + cost);
        }
    }

    cout << dp.back() << '\n';
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
