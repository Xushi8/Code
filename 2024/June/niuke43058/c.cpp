// 2024/06/21 22:05:03
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
constexpr int N = 1000005;

constexpr int MOD = 1e9 + 7;

void solve()
{
	string s;
	cin >> s;
	vector<vector<i64>> dp(s.size(), vector<i64>(8)), sum(10, vector<i64>(8));

	i64 ans = 0;
	for (int i = 0; i < s.size(); i++)
	{
		size_t val = s[i] - '0';
		for (int j = 1; j <= 7; j++)
		{
			if (j == 1)
			{
				dp[i][j] = 1;
			}
			else if (j == 2 || j == 4)
			{
				for (size_t k = 0; k < val; k++)
				{
					dp[i][j] += sum[k][j - 1];
                }
			}
			else
			{
				for (size_t k = val + 1; k < 10; k++)
				{
					dp[i][j] += sum[k][j - 1];
				}
			}

			sum[val][j] += dp[i][j];
			sum[val][j] %= MOD;
		}
		ans += dp[i][7];
	}

	cout << ans % MOD << '\n';
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