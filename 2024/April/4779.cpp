// 2024/04/24 11:08:20
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
using pii = pair<int, int>;
using pll = pair<ll, ll>;
constexpr int N = 1000005;
constexpr int INF = 0x3f3f3f3f;

vector<int> dijkstra(int s, vector<vector<pii>> const& G)
{
	vector<int> dis(G.size(), INF);
	priority_queue<pii, vector<pii>, greater<>> que;
	que.emplace(0, s);
	dis[s] = 0;
	while (!que.empty())
	{
		auto [wei, u] = que.top();
		que.pop();
		if (dis[u] < wei)
			continue;
		for (auto [v, w] : G[u])
		{
			if (dis[v] > dis[u] + w)
			{
				dis[v] = dis[u] + w;
				que.emplace(dis[v], v);
			}
		}
	}
	return dis;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	int n, m, s;
	cin >> n >> m >> s;
	s--;
	vector<vector<pii>> G(n);
	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		u--;
		v--;
		G[u].emplace_back(v, w);
	}

	auto dis = dijkstra(s, G);
	for (auto x : dis)
	{
		cout << x << ' ';
    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}