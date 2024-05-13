// 2024/05/13 20:36:23
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

using i64 = int64_t;
using pii = pair<int, int>;
constexpr int N = 1000005;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> price(n);
	for (auto& x : price)
		cin >> x;
	vector<vector<pii>> G(n);
	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		G[u].emplace_back(v, w);
		G[v].emplace_back(u, w);
	}

	int q;
	cin >> q;
	while (q--)
	{
		int maxx, be, ed;
		cin >> maxx >> be >> ed;
        bool flag = 0;
		// 当前的花费, u, fuel
		priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> que;
		que.emplace(0, be, 0);
		vector<vector<bool>> vis(n, vector<bool>(maxx + 1, false));
		while (!que.empty())
		{
			auto [cost, u, fuel] = que.top();
			que.pop();
			if (fuel > maxx)
				continue;
			if (vis[u][fuel])
				continue;
			vis[u][fuel] = 1;
			que.emplace(cost + price[u], u, fuel + 1);
			if (u == ed)
			{
                flag = 1;
				cout << cost << '\n';
				break;
			}

			for (auto [v, w] : G[u])
			{
				if (fuel >= w)
				{
					que.emplace(cost, v, fuel - w);
                }
            }
		}

		if (!flag)
		{
			cout << "impossible\n";
		}
	}
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}