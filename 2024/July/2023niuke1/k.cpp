// 2024/07/22 16:26:01
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
	int V, E, k;
	cin >> V >> E >> k;
	vector<vector<int>> G(V);
	vector<int> deg(V);
	for (int i = 0; i < E; i++)
	{
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
		deg[u]++;
		deg[v]++;
	}

	constexpr int INF = 0x3f3f3f3f;
	queue<int> que;
	vector<int> dis(V, INF);
	que.emplace(0);
	dis[0] = 0;
	while (!que.empty())
	{
		auto u = que.front();
		que.pop();
		for (int v : G[u])
		{
			if (dis[v] > dis[u] + 1)
			{
				dis[v] = dis[u] + 1;
				que.emplace(v);
            }
        }
	}

	i64 ans = 1;
	ans += 1ll * k * deg[0];
	for (int u = 1; u < V; u++)
	{
		if (dis[u] <= k && deg[u] >= 2)
		{
			ans += 1ll * (k - dis[u]) * (deg[u] - 2);
        }
	}
	cout << ans << '\n';
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