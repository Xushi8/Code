// 2024/10/16 15:43:47
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
    string s;
    cin >> s;

    auto win = [](char a, char b)
    {
        if (a == 'S')
        {
            return b == 'P';
        }
        else if (a == 'R')
        {
            return b == 'S';
        }
        else
        {
            return b == 'R';
        }
    };

    vector<vector<int>> dp(n, vector<int>(2));
    dp[0][0] = 0;
    dp[0][1] = 1;
    for (int i = 1; i < n; i++)
    {
        if (s[i] == s[i - 1])
        {
            dp[i][0] = dp[i - 1][1];
            dp[i][1] = dp[i - 1][0] + 1;
        }
        else if (win(s[i - 1], s[i]))
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][1] + 1;
        }
        else
        {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + 1;
        }
    }

    // for (auto const& vec : dp)
    // {
    //     cout << vec.front() << ' ' << vec.back() << '\n';
    // }

    cout << max(dp[n - 1][0], dp[n - 1][1]) << '\n';

    // int ans = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     ans++;
    //     int j;
    //     for (j = i + 1; j < n && s[i] == s[j]; j++) {}

    //     int cnt = j - i;
    //     ans += (cnt - 1) / 2;

    //     if (cnt > 1 && cnt % 2 == 1 && j < n)
    //     {

    //     }

    //     i = j;
    // }

    // cout << ans << '\n';
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
