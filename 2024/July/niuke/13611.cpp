// 2024/07/24 18:30:53
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
	int n, k;
	cin >> n >> k;
	vector<vector<int>> G(n + 1);
	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}

	vector<vector<i64>> dp(n + 1, vector<i64>(k + 1));
	dp[0][0] = 1;
	constexpr i64 MOD = 1e9 + 7;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= min(i, k); j++)
		{
			dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1] * (k - (j - 1));
			dp[i][j] %= MOD;
        }
	}

	i64 ans = 0;
	for (int j = 1; j <= k; j++)
	{
		ans += dp[n][j];
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