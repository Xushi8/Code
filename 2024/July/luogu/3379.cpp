// 2024/07/23 22:01:53
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

void solve();

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

void solve1()
{
	int V, q, S;
	cin >> V >> q >> S;
	S--;
	vector<vector<int>> G(V);
	for (int i = 0; i < V - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		if (u == v)
			continue;
		u--;
		v--;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}

	vector<int> dep(V + 1);
	vector<vector<int>> f(V, vector<int>(__lg(V) + 1, -1));
	auto dfs = [&](auto&& self, int u, int par) -> void
	{
		dep[u] = dep[par] + 1;
		f[u][0] = par;
		for (int i = 1; i <= __lg(dep[u]); i++)
		{
			f[u][i] = f[f[u][i - 1]][i - 1];
		}
		for (auto v : G[u])
		{
			if (v == par)
				continue;
			self(self, v, u);
		}
	};

	auto lca = [&](int x, int y)
	{
		if (dep[x] < dep[y])
			swap(x, y);
		for (int i = __lg(dep[x]); i >= 0; i--)
		{
			if (dep[f[x][i]] >= dep[y])
				x = f[x][i];
			if (x == y)
				return x;
		}
		for (int i = __lg(dep[x]); i >= 0; i--)
		{
			if (f[x][i] != f[y][i])
			{
				x = f[x][i];
				y = f[y][i];
			}
		}
		return f[x][0];
	};

	dfs(dfs, S, V);

	while (q--)
	{
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		cout << lca(x, y) + 1 << '\n';
	}
}

void solve()
{
	int V, q, S;
	cin >> V >> q >> S;
	vector<vector<int>> G(V + 1);
	for (int i = 0; i < V - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		if (u == v)
			continue;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}

	vector<int> dep(V + 1);
	vector<vector<int>> f(V + 1, vector<int>(22));
	auto dfs = [&](auto&& self, int u, int par) -> void
	{
		dep[u] = dep[par] + 1;
		f[u][0] = par;
		for (int i = 1; i <= 21; i++)
		{
			f[u][i] = f[f[u][i - 1]][i - 1];
		}
		for (auto v : G[u])
		{
			if (v == par)
				continue;
			self(self, v, u);
		}
	};

	auto lca = [&](int x, int y)
	{
		if (dep[x] < dep[y])
			swap(x, y);
		for (int i = 21; i >= 0; i--)
		{
			if (dep[f[x][i]] >= dep[y])
				x = f[x][i];
			if (x == y)
				return x;
		}
		for (int i = 21; i >= 0; i--)
		{
			if (f[x][i] != f[y][i])
			{
				x = f[x][i];
				y = f[y][i];
			}
		}
		return f[x][0];
	};

	dfs(dfs, S, 0);

	while (q--)
	{
		int x, y;
		cin >> x >> y;
		cout << lca(x, y) << '\n';
	}
}