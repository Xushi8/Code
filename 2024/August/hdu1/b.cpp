// 2024/08/16 12:03:35
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
    cin >> tt;
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
    vector<array<int, 4>> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3];
    }

    constexpr i64 INF = 0x3f3f3f3f3f3f3f3f;
    vector<i64> dp(m + 4, INF);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        auto ndp = dp;
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                ndp[j + k + 1] = min(ndp[j + k + 1], dp[j] + arr[i][k]);
            }
        }
        dp = std::move(ndp);
    }

    cout << dp[m] << '\n';
}