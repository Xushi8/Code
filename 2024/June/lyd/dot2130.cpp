// 2024/06/20 15:49:05
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
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n + 1, vector<int>(m + 1));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
		}
	}

	vector<vector<int>> dp(n + 1, vector<int>(m + 1));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				dp[i][j] = max(dp[i][j], dp[i - 1][j - k] + a[i][k]);
			}
		}
	}

	cout << dp.back().back() << '\n';

	vector<int> path;
	const function<void(int, int)> dfs = [&](int i, int j)
	{
		if (i == 0)
			return;
		for (int k = 0; k <= j; k++)
		{
			if (dp[i][j] == dp[i - 1][j - k] + a[i][k])
			{
				path.emplace_back(k);
				return dfs(i - 1, j - k);
			}
		}
	};

	dfs(n, m);
	reverse(path.begin(), path.end());

	for (size_t i = 0; i < path.size(); i++)
	{
		cout << i + 1 << ' ' << path[i] << '\n';
	}
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