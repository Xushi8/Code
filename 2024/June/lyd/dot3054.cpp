// 2024/06/18 11:40:44
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
	vector<vector<int>> w(n + 1, vector<int>(m + 1));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> w[i][j];
		}
	}

	constexpr int INF = 0x3f3f3f3f;
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, INF));

	// for (int i = 0; i <= n; i++)
	// {
	// 	dp[i][0] = 0;
	// }
	// for (int j = 0; j <= m; j++)
	// {
	// 	dp[0][j] = 0;
	// }

	dp[1][1] = w[1][1];
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (i == 1 && j == 1)
				continue;
			dp[i][j] = w[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
        }
	}

	// for (int i = 1; i <= n; i++)
	// {
	// 	for (int j = 1; j <= m; j++)
	// 	{
	// 		cout << dp[i][j] << ' ';
	// 	}
	// 	cout << '\n';
    // }


	cout << dp[n][m] << '\n';
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