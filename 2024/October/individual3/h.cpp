// 2024/10/16 14:31:19
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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    vector<i64> sum(n + 1);
    for (int i = 0; i < n; i++)
    {
        sum[i + 1] = sum[i] + a[i];
    }

    // dp[i] 在 i 出发的车积累的全部等待时间
    vector<i64> dp(a.back() + 1);
    for (int i = 0; i < m; i++)
    {
        // for (int j = 0; j < n && a[j] <= i; j++)
        // {
        //     dp[i] += i - a[j];
        // }
        auto it1 = lower_bound(a.begin(), a.end(), i - m);
        auto it2 = upper_bound(a.begin(), a.end(), i);
        size_t i1 = it1 - a.begin();
        size_t cnt = it2 - it1;
        dp[i] += cnt * i - (sum[i1 + cnt] - sum[i1]);
    }

    for (int i = m; i <= a.back(); i++)
    {
        // auto it1 = lower_bound(a.begin(), a.end(), i - m);
        auto it2 = lower_bound(a.begin(), a.end(), i);
        auto it1 = upper_bound(a.begin(), a.end(), i - m);
        size_t i1 = it1 - a.begin();
        size_t cnt = it2 - it1;
        i64 val = cnt * i - (sum[i1 + cnt] - sum[i1]);
        dp[i] = val + dp[i - m];
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
