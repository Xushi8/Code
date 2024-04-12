// // 2024/04/10 14:16:23
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <cstdint>
// #include <vector>
// #include <string>
// #include <set>
// #include <map>
// #include <unordered_map>
// #include <unordered_set>
// #include <queue>
// #include <functional>
// #include <iomanip>
// #include <cmath>
// #include <stack>
// #include <array>
// #include <fstream>
// #include <bitset>
// #include <numeric>
// using namespace std;

// using ll = long long;
// using pii = pair<int, int>;
// using pll = pair<ll, ll>;
// constexpr int N = 1000005;

// constexpr int INF = 0x3f3f3f3f;

// int main()
// {
// 	ios::sync_with_stdio(false);
// 	cin.tie(0);

// 	int n, m;
// 	cin >> n >> m;
// 	vector<vector<int>> G(n + 1);

// 	int start;
// 	for (int i = 1; i <= n; i++)
// 	{
// 		int x;
// 		cin >> x;
// 		if (x == -1)
// 		{
// 			start = i;
// 			continue;
// 		}
// 		G[x].emplace_back(i);
// 		G[i].emplace_back(x);
// 	}

// 	map<int, int> mp;
// 	vector<int> mp1(m), ans(m);
// 	for (int i = 0; i < m; i++)
// 	{
// 		int x;
// 		cin >> x;
// 		if (!mp.count(x))
// 		{
// 			mp[x] = i;
// 			mp1[i] = x;
// 		}
// 	}
// 	int last = -1;

// 	set<int> st;
// 	vector<int> dis(n + 1, INF);
// 	dis[start] = 0;
// 	queue<int> que;
// 	que.emplace(start);
// 	while (!que.empty())
// 	{
// 		auto u = que.front();
// 		que.pop();
// 		for (int v : G[u])
// 		{
// 			if (dis[v] > dis[u] + 1)
// 			{
// 				dis[v] = dis[u] + 1;
// 				que.emplace(v);
// 				st.emplace(v);
// 				auto it = mp.find(v);
// 				if (it != mp.end())
// 				{
// 					int index = it->second;
// 					if (index == last + 1)
// 					{
// 						ans[index] = dis[v];
// 					}
// 				}
// 			}
// 		}
// 	}

// #ifdef LOCAL
// 	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
// #endif
// 	return 0;
// }

// 2024/04/10 16:43:34
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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;
	vector<vector<int>> G(n + 1);
	vector<int> par(n + 1);
	int root;
	for (int i = 1; i <= n; i++)
	{
		int tmp;
		cin >> tmp;
		if (tmp == -1)
		{
			root = i;
			continue;
		}
		par[i] = tmp;
		G[i].emplace_back(tmp);
		G[tmp].emplace_back(i);
	}

	constexpr int INF = 0x3f3f3f3f;
	vector<int> dis(n + 1, INF);

	queue<int> que;
	que.emplace(root);
	dis[root] = 0;
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

	int num = 0, maxx = 0;
	vector<int> vis(n + 1, 0);
	vis[root] = 1;
	while (q--)
	{
		int u;
		cin >> u;
		int chalu = u;
		while (!vis[chalu])
		{
			vis[chalu] = 1;
			chalu = par[chalu];
		}

		num += dis[u] - dis[chalu];
		maxx = max(maxx, dis[u]);
		cout << num * 2 - maxx << '\n';
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}