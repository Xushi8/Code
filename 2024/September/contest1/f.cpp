// 2024/09/28 13:02:08
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

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<vector<i64>> dp(n + 1, vector<i64>(2));
    for (int i = 1; i <= n; i++)
    {
        if (a[i] < 0)
        {
            dp[i][0] = dp[i - 1][1];
            dp[i][1] = dp[i - 1][0] + 1;
        }
        else if (a[i] > 0)
        {
            dp[i][0] = dp[i - 1][0] + 1;
            dp[i][1] = dp[i - 1][1];
        }
        else
        {
            
        }
    }

    i64 ans;

    ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += dp[i][1];
    }
    cout << ans << ' ';

    ans = 0;
    int pre = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 0)
        {
            pre = i;
        }
        ans += pre;
    }
    cout << ans << ' ';

    ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += dp[i][0];
    }
    cout << ans << '\n';
}