// 2024/06/19 16:51:14
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
	int W1, W2, n;
	cin >> W1 >> W2 >> n;
	vector<int> v1(n), v2(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v1[i] >> v2[i];
	}

	vector<vector<int>> dp(W1 + 1, vector<int>(W2));
	for (int i = 0; i < n; i++)
	{
		auto ndp = dp;
		for (int j = v1[i]; j <= W1; j++)
		{
			for (int k = v2[i]; k < W2; k++)
			{
				ndp[j][k] = max(dp[j][k], dp[j - v1[i]][k - v2[i]] + 1);
			}
		}

		dp = std::move(ndp);
	}

	int ans1 = dp[W1][W2 - 1];
	int ans2 = 1e9;
	for (int i = 0; i <= W1; i++)
	{
		for (int j = 0; j < W2; j++)
		{
			if (dp[i][j] == ans1)
			{
				ans2 = min(ans2, j);
			}
		}
	}

	cout << ans1 << ' ' << W2 - ans2 << '\n';
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