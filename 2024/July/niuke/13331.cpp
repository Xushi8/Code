// 2024/07/24 16:05:15
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
	int n, q;
	cin >> n >> q;
	vector<int> val(n + q + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> val[i];
	}

	vector<vector<int>> G(n + q + 1);
	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}

	vector<int> target(q + 1);
	for (int i = 1; i <= q; i++)
	{
		int u, v, c;
		cin >> u >> v >> c;
		G[u].emplace_back(n + i);
		G[n + i].emplace_back(u);
		val[n + i] = c;
		target[i] = v;
	}

	vector<int> dep(n + q + 1);
	vector<vector<int>> f(n + q + 1, vector<int>(22));

	auto dfs = [&](auto&& self, int u, int p) -> void
	{
		dep[u] = dep[p] + 1;
		if (val[u] < val[p])
		{
			f[u][0] = p;
		}
		else
		{
			int x = p;
			for (int i = 21; i >= 0; i--)
			{
				if (f[x][i] != 0 && val[u] >= val[f[x][i]])
					x = f[x][i];
			}
			f[u][0] = f[x][0];
		}

		for (int i = 1; i <= 21; i++)
		{
			f[u][i] = f[f[u][i - 1]][i - 1];
		}

		for (int v : G[u])
		{
			if (v == p)
				continue;
			self(self, v, u);
        }
    };

	dfs(dfs, 1, 0);
	for (int i = 1; i <= q; i++)
	{
		int u = n + i;
		int v = target[i];
		i64 ans = 0;
		for (int j = 21; j >= 0; j--)
		{
			if (dep[f[u][j]] >= dep[v])
			{
				u = f[u][j];
				ans += (1 << j);
            }
		}
		cout << ans << '\n';
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