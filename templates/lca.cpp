#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int V;
	vector<vector<int>> G(V);

	vector<int> dep(V + 1); // 加一是为了将根节点的par设置为V

	// 这里__lg(V) 不加一会RE, 因为__lg是下取整
	// 必须初始化为-1
	vector<vector<int>> far(V, vector<int>(__lg(V) + 1, -1));

	auto dfs = [&](auto&& self, int u, int par) -> void
	{
		dep[u] = dep[par] + 1;
		far[u][0] = par;
		for (int i = 1; i <= __lg(dep[u]); i++) // 递推
		{
			far[u][i] = far[far[u][i - 1]][i - 1];
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
			if (dep[far[x][i]] >= dep[y])
				x = far[x][i];
			if (x == y)
				return x;
		}
		for (int i = __lg(dep[x]); i >= 0; i--)
		{
			if (far[x][i] != far[y][i])
			{
				x = far[x][i];
				y = far[y][i];
			}
		}
		return far[x][0];
	};

	dfs(dfs, S, V);
}

// 这里提供下标从1开始的代码, 同时次数设置为常量22
void solve1()
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

// 重链
void solve2()
{
	int n, q, S;
	cin >> n >> q >> S;
	vector<vector<int>> G(n + 1);
	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}

	vector<int> par(n + 1), dep(n + 1), top(n + 1), siz(n + 1, 1), son(n + 1);

	auto dfs1 = [&](auto&& self, int u) -> void
	{
		dep[u] = dep[par[u]] + 1;
		for (auto v : G[u])
		{
			if (v == par[u])
				continue;
			par[v] = u;
			self(self, v);
			siz[u] += siz[v];
			if (siz[v] > siz[son[u]])
				son[u] = v;
		}
	};

	auto dfs2 = [&](auto&& self, int u, int h) -> void
	{
		top[u] = h;
		if (son[u])
			self(self, son[u], h);
		for (auto v : G[u])
		{
			if (v == par[u] || v == son[u])
				continue;
			self(self, v, v);
		}
	};

	auto lca = [&](int x, int y) -> int
	{
		while (top[x] != top[y])
		{
			if (dep[top[x]] > dep[top[y]])
				x = par[top[x]];
			else
				y = par[top[y]];
		}
		return dep[x] < dep[y] ? x : y;
	};

	par[S] = 0;
	dfs1(dfs1, S);
	dfs2(dfs2, S, S);
	while (q--)
	{
		int x, y;
		cin >> x >> y;
		cout << lca(x, y) << '\n';
	}
}