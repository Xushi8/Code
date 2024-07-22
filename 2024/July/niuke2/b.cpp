// #include <bits/stdc++.h>

// using namespace std;

// const int N = 2e5 + 5;
// const int INF = 0x3f3f3f3f;
// #define int long long

// int n, m, q, t, k;
// int p[N];
// set<int> Set;

// struct Edge
// {
// 	int a, b, w;
// } edges[N];

// bool cmp(Edge u, Edge p)
// {
// 	return u.w < p.w;
// }

// int find(int x)
// {
// 	if (x != p[x]) return p[x] = find(p[x]);
// 	return p[x];
// }

// int kruskal()
// {
// 	// sort(edges, edges + m, cmp);
// 	int res = 0, cnt = 0;
// 	for (int i = 0; i < m; i++)
// 	{
// 		int a = edges[i].a, b = edges[i].b, w = edges[i].w;
// 		if (Set.count(a) && Set.count(b))
// 		{
// 			a = find(a), b = find(b);
// 			if (a != b)
// 			{
// 				p[a] = b;
// 				cnt++;
// 				res += w;
// 				if (cnt == Set.size())
// 				{
// 					return res;
//                 }
// 			}
// 		}
// 	}
// 	if (cnt < Set.size() - 1) return INF;
// 	return res;
// }

// void solve()
// {
// 	cin >> n >> m >> q;

// 	for (int i = 0; i < m; i++)
// 	{
// 		int a, b, w;
// 		cin >> a >> b >> w;
// 		edges[i] = {a, b, w};
// 	}
// 	// sort(edges, edges + m, cmp);

// 	while (q--)
// 	{
// 		Set.clear();
// 		for (int i = 1; i <= n; i++)
// 			p[i] = i;
// 		cin >> k;
// 		for (int i = 0; i < k; i++)
// 		{
// 			int x;
// 			cin >> x;
// 			Set.insert(x);
// 		}

// 		int ans = kruskal();
// 		if (ans == INF)
// 			cout << "-1\n";
// 		else
// 			cout << ans << "\n";
// 	}
// }

// signed main()
// {
// 	ios::sync_with_stdio(false);
// 	cin.tie(0);

// 	t = 1;
// 	while (t--)
// 		solve();

// 	return 0;
// }

// 2024/07/21 18:42:52
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

int par[N];

int find(int x)
{
	if (x == par[x])
		return x;
	else
		return par[x] = find(par[x]);
}

void unite(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x != y)
		par[x] = y;
}

bool same(int x, int y)
{
	return find(x) == find(y);
}

struct edge
{
	int u, v, w;
};

void solve()
{
	int V, E, q;
	cin >> V >> E >> q;
	vector<edge> all_edge(E);
	vector<map<int, int>> mp(V);
	for (int i = 0; i < E; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		u--;
		v--;
		if (u > v)
			swap(u, v);
		all_edge[i] = {u, v, w};
		mp[u].emplace(v, w);
	}

	while (q--)
	{
		int n;
		cin >> n;
		set<int> ver;
		vector<edge> edges;
		edges.reserve(E);
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			x--;
			par[x] = x;
			ver.emplace(x);
		}


		if (n < 1000)
		{
			for (auto u : ver)
			{
				for (auto v : ver)
				{
					if (mp[u].count(v))
					{
						edges.push_back({u, v, mp[u][v]});
                    }
                }
			}
		}
		else
		{
			for (auto [u, v, w] : all_edge)
			{
				if (ver.count(u) && ver.count(v))
				{
					edges.push_back({u, v, w});
                }
            }
        }
		

		// kruskal
		sort(edges.begin(), edges.end(), [](edge const& l, edge const& r)
			{
				return l.w < r.w;
			});

		i64 val = 0, cnt = 0;
		for (auto [u, v, w] : edges)
		{
			if (!same(u, v))
			{
				unite(u, v);
				cnt++;
				val += w;
            }
		}
		if (cnt + 1 < i64(ver.size()))
			cout << "-1\n";
		else
			cout << val << '\n';
	}
}

// void solve()
// {
// 	int V, E, q;
// 	cin >> V >> E >> q;
// 	vector<vector<pii>> G(V);
// 	for (int i = 0; i < E; i++)
// 	{
// 		int u, v, w;
// 		cin >> u >> v >> w;
// 		u--;
// 		v--;
// 		G[u].emplace_back(v, w);
// 		G[v].emplace_back(u, w);
// 	}

// 	constexpr i64 INF = 0x3f3f3f3f3f3f3f3f;
// 	while (q--)
// 	{
// 		map<int, i64> dis;
// 		int n;
// 		cin >> n;
// 		for (int i = 0; i < n; i++)
// 		{
// 			int x;
// 			cin >> x;
// 			x--;
// 			dis.emplace(x, INF);
// 		}

// 		priority_queue<pll, vector<pll>, greater<>> que;
// 		que.emplace(0, dis.begin()->first);
// 		dis.begin()->second = 0;
// 		i64 sum = 0;
// 		int cnt = 0;
// 		while (!que.empty())
// 		{
// 			auto [wu, u] = que.top();
// 			que.pop();
// 			if (dis[u] < wu)
// 				continue;
// 			cnt++;
// 			for (auto [v, w] : G[u])
// 			{
// 				if (!dis.count(v))
// 					continue;
// 				if (dis[v] > dis[u] + w)
// 				{
// 					dis[v] = dis[u] + w;
// 					que.emplace(dis[v], v);
// 					sum += w;
//                 }
//             }
// 		}
// 		if (cnt == n)
// 			cout << sum << '\n';
// 		else
// 			cout << "-1\n";
//     }
// }

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