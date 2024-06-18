// 2024/06/17 17:36:17
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
	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	vector<i64> sum(n + 1);
	for (int i = 0; i < n; i++)
	{
		sum[i + 1] = sum[i] + a[i];
	}

	constexpr i64 INF = 9e18;
	vector<vector<i64>> dp(n + 1, vector<i64>(n + 1, INF));
	for (int i = 0; i <= n; i++)
	{
		dp[i][i] = 0;
	}
	for (int len = 2; len <= n; len++)
	{
		for (int l = 1; l + len - 1 <= n; l++)
		{
			int r = l + len - 1;
			for (int j = l; j + 1 <= r; j++)
			{
				dp[l][r] = min(dp[l][r], dp[l][j] + dp[j + 1][r]);
			}
			dp[l][r] += sum[r] - sum[l - 1];
		}
	}

	cout << dp[1][n] << '\n';
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