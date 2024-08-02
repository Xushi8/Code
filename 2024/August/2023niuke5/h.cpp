// 2024/08/02 14:22:21
#ifdef LOCAL
#include <basic_std_lib.h>
#else
#include <bits/stdc++.h>
#endif

#include <chrono>
#include <thread>
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

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<array<int, 2>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i][0] >> a[i][1];
    }
    vector<int> bag(m);
    for (int i = 0; i < m; i++)
    {
        cin >> bag[i];
    }
    if (m > n)
    {
        bag.erase(bag.begin(), bag.end() - n);
    }
    m = bag.size();

    // int ans = 0;
    // auto dfs = [&](auto&& self, int now_i, int last, int now_ans) -> void
    // {
    //     // cout << now_i << ' ' << ans << ' ' << last << '\n';
    //     if (now_i == m || last == n - 1)
    //     {
    //         ans = max(ans, now_ans);
    //         return;
    //     }
    //     int W = bag[now_i];
    //     vector<int> dp(W + 1);
    //     for (int to = last; to < n; to++)
    //     {
    //         // 01 背包
    //         if (to != last)
    //         {
    //             auto [wei, val] = a[to];
    //             auto ndp = dp;
    //             for (int j = wei; j <= W; j++)
    //             {
    //                 ndp[j] = max(dp[j], dp[j - wei] + val);
    //             }
    //             dp = std::move(ndp);
    //         }

    //         self(self, now_i + 1, to, now_ans + dp.back());
    //     }
    // };

    // dfs(dfs, 0, -1, 0);
    // cout << ans << '\n';

    vector<vector<int>> dp(m, vector<int>(bag.back() + 1));

    for (auto [wei, val] : a)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = bag[j]; k >= wei; k--)
            {
                dp[j][k] = max(dp[j][k], dp[j][k  - wei] + val);
            }
        }

        for (int j = 0; j < m - 1; j++)
        {
            for (int k = 0; k <= bag[j]; k++)
            {
                dp[j + 1][0] = max(dp[j + 1][0], dp[j][k]);
            }
        }
    }

    cout << *max_element(dp.back().begin(), dp.back().end()) << '\n';
}