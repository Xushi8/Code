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
