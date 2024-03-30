// 2024/03/30 19:58:25
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

int dis[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	int n;
	cin >> n;
	vector<vector<int>> G(n + 1);
	for (int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		G[i].reserve(k);
		for (int j = 0; j < k; j++)
		{
			int x;
			cin >> x;
			G[i].emplace_back(x);
        }
	}

	memset(dis, 0x3f, sizeof(dis));

	queue<int> que;
	que.emplace(1);
	dis[1] = 0;
	while (!que.empty())
	{
		auto u = que.front();
		que.pop();
		for (auto v : G[u])
		{
			if (dis[v] > dis[u] + 1)
			{
				dis[v] = dis[u] + 1;
				que.emplace(v);
            }
        }
	}

	cout << (max_element(dis + 1, dis + n + 1) - dis) << endl;
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}