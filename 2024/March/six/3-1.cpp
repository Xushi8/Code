// 2024/04/06 16:06:46
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdint>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <functional>
#include <iomanip>
#include <cmath>
#include <stack>
#include <array>
#include <fstream>
#include <bitset>
#include <numeric>
using namespace std;

using ll = long long;
using pii = pair<ll, int>;
using pll = pair<ll, ll>;
constexpr int N = 1000005;

struct A
{
	ll to;
	int w1, w2;
	A(ll to_, int w1_, int w2_) :
		to(to_), w1(w1_), w2(w2_) {}
};

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;

void dijkstra1(int s, vector<ll>& dis, vector<vector<A>> const& G)
{
	fill(dis.begin(), dis.end(), INF);
	dis[s] = 0;
	priority_queue<pii, vector<pii>, greater<>> que;
	que.emplace(0, s);
	while (!que.empty())
	{
		auto [val, u] = que.top();
		que.pop();
		if (dis[u] < val) continue;
		for (auto [v, w1, w2] : G[u])
		{
			if (dis[v] > dis[u] + w1)
			{
				dis[v] = dis[u] + w1;
				que.emplace(dis[v], v);
			}
		}
	}
}

void dijkstra2(int s, vector<ll>& dis, vector<vector<A>> const& G)
{
	fill(dis.begin(), dis.end(), INF);
	dis[s] = 0;
	priority_queue<pii, vector<pii>, greater<>> que;
	que.emplace(0, s);
	while (!que.empty())
	{
		auto [val, u] = que.top();
		que.pop();
		if (dis[u] < val) continue;
		for (auto [v, w1, w2] : G[u])
		{
			if (dis[v] > dis[u] + w2)
			{
				dis[v] = dis[u] + w2;
				que.emplace(dis[v], v);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, q;
	cin >> n >> m >> q;
	vector<vector<A>> G1(n), G2(n);
	for (int i = 0; i < m; i++)
	{
		int u, v, w1, w2;
		cin >> u >> v >> w1 >> w2;
		if (u == v)
			continue;
		u--;
		v--;
		G1[u].emplace_back(v, w1, w2);
		G2[v].emplace_back(u, w1, w2);
	}

	vector<ll> dis1(n), dis2(n);
	dijkstra1(0, dis1, G1);
	dijkstra2(n - 1, dis2, G2);

	vector<ll> val(n);
	for (int i = 0; i < n; i++)
	{
		cin >> val[i];
	}

	multiset<ll> st;
	for (int i = 0; i < n; i++)
	{
		if (dis1[i] != INF && dis2[i] != INF)
		{
			st.emplace(dis1[i] + (dis2[i] + val[i] - 1) / val[i]);
		}
	}

	while (q--)
	{
		int x, y;
		cin >> x >> y;
		x--;
		if (dis1[x] != INF && dis2[x] != INF)
		{
			st.erase(st.find(dis1[x] + (dis2[x] + val[x] - 1) / val[x]));
			val[x] = y;
			st.emplace(dis1[x] + (dis2[x] + val[x] - 1) / val[x]);
		}
		cout << *st.begin() << '\n';
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}