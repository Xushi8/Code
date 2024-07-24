// 2024/07/24 17:21:44
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
	int n, m, S;
	cin >> n >> m >> S;
	vector<vector<pii>> G(n + 1);
	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		G[u].emplace_back(v, w);
		G[v].emplace_back(u, w);
	}

	vector<int> dp(n + 1);
	constexpr int INF = 0x3f3f3f3f;

	auto dfs = [&](auto&& self, int u, int p) -> void
	{
		if (G[u].size() == 1 && G[u][0].first == p)
		{
			dp[u] = INF;
		}
		for (auto [v, w] : G[u])
		{
			if (v == p)
				continue;
			self(self, v, u);
			dp[u] += min(w, dp[v]);
		}
	};

	dfs(dfs, S, 0);
	cout << dp[S] << '\n';
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