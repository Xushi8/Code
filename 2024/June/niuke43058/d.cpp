// 2024/06/21 20:00:06
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
	int V, E, S, T, k;
	cin >> V >> E >> S >> T >> k;
	S--;
	T--;
	vector<vector<array<int, 3>>> G(V);
	for (int i = 0; i < E; i++)
	{
		int u, v, w1;
		cin >> u >> v >> w1;
		u--;
		v--;
		int w2 = (114LL * w1 + 513) / 514;
		G[u].push_back({v, w1, w2});
		G[v].push_back({u, w1, w2});
	}

	auto check = [&](int val) -> bool
	{
		constexpr int INF = 0x3f3f3f3f;
		vector<int> dis(V, INF);
		vector<bool> vis(V);
		deque<int> que;
		que.emplace_back(S);
		dis[S] = 0;
		while (!que.empty())
		{
			auto u = que.front();
			que.pop_front();
			if (vis[u])
				continue;
			vis[u] = 1;
			if (u == T)
			{
				return dis[u] <= k;
			}

			for (auto [v, w1, w2] : G[u])
			{
				if (w1 <= val)
				{
					que.emplace_front(v);
					dis[v] = min(dis[u], dis[v]);
				}
				else if (w2 <= val)
				{
					que.emplace_back(v);
					dis[v] = min(dis[u] + 1, dis[v]);
				}
			}
		}

		return false;
	};

	int l = 0, r = 1e9, ans = -1;
	while (l <= r)
	{
		int mid = l + (r - l) / 2;
		if (check(mid))
			ans = mid, r = mid - 1;
		else
			l = mid + 1;
	}
	if (ans == -1)
		cout << "I really need TS1's time machine again!\n";
	else
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