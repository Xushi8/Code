// 2024/05/27 22:11:51
#ifdef LOCAL
#include <basic_std_lib.h>
#else
#include <bits/stdc++.h>
#endif
using namespace std;

using i64 = int64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 1005;

constexpr int mod = 998244353;

i64 dfs(int u, vector<i64>& dp, vector<int> const& val, vector<vector<int>> const& G)
{
	if (dp[u] != -1)
	{
		return dp[u];
	}
	i64 sum = val[u];
	for (int v : G[u])
	{
		sum += dfs(v, dp, val, G);
		sum %= mod;
	}

	return dp[u] = sum % mod;
}

void solve()
{
	size_t n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (size_t i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	vector<vector<int>> G(n), RG(n);
	for (size_t i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		G[u].emplace_back(v);
		RG[v].emplace_back(u);
	}
	int ed;
	for (size_t i = 0; ; i++)
	{
		if (G[i].size() == 0)
		{
			ed = i;
			break;
		}
	}

	vector<i64> dp(n, -1);
	i64 sum = dfs(ed, dp, a, RG);

	for (size_t cnt = 0; cnt < n; cnt++)
	{
		vector<int> dec;
		for (size_t i = 0; i < n; i++)
		{
			if (a[i] > 0)
			{
				a[i]--;
				dec.emplace_back(i);
			}
		}

		if (dec.empty())
			break;

		bool has_ed = 0;
		for (auto u : dec)
		{
			if (u == ed)
				has_ed = 1;
			for (int v : G[u])
			{
				a[v]++;
			}
		}

		if (!has_ed)
			sum++;
	}

	cout << sum % mod << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt;
	cin >> tt;
	while (tt--)
	{
		solve();
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}