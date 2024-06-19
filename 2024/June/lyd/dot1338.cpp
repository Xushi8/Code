// 2024/06/19 15:33:45
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

void solve()
{
	int n;
	cin >> n;
	int m = n;
	vector<int> a(n + 1), b(m + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int j = 1; j <= m; j++)
	{
		cin >> b[j];
	}

	vector<vector<int>> dp(n + 1, vector<int>(m + 1));

	for (int i = 1; i <= n; i++)
	{
		int val = 0;
		for (int j = 1; j <= m; j++)
		{
			if (a[i] == b[j])
			{
				dp[i][j] = max(dp[i][j] , val + 1);
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}

			if (b[j] < a[i])
				val = max(val, dp[i - 1][j]);
        }
	}

	int ans = 0;
	for (int j = 0; j <= m; j++)
	{
		ans = max(ans, dp[n][j]);
	}
	cout << ans << '\n';
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