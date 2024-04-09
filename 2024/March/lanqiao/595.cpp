// 2024/04/09 16:29:29
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

bool check(int x, vector<vector<int>> const& G)
{
	vector<int> tmp;
	set<int> st;
	for (int i = 0; i < 7; i++)
	{
		if ((x >> i) & 1)
			tmp.emplace_back(i), st.emplace(i);
	}
	vector<bool> vis(tmp.size(), 0);
	queue<int> que;
	int cnt = 0;
	for (auto y : tmp)
	{
		if (!vis[y])
		{
			vis[y] = 1;
			cnt++;
			que.emplace(y);
			while (!que.empty())
			{
				auto u = que.front();
				que.pop();
				for (int v : G[u])
				{
					if (!vis[v] && st.count(v))
					{
						vis[v] = 1;
						que.emplace(v);
                    }
                }
			}
		}
	}
	return cnt == 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<vector<int>> G(7);
	G[0].emplace_back(1);
	G[0].emplace_back(5);
	G[1].emplace_back(0);
	G[1].emplace_back(2);
	G[1].emplace_back(6);
	G[2].emplace_back(1);
	G[2].emplace_back(3);
	G[2].emplace_back(6);
	G[3].emplace_back(2);
	G[3].emplace_back(4);
	G[4].emplace_back(3);
	G[4].emplace_back(5);
	G[4].emplace_back(6);
	G[5].emplace_back(0);
	G[5].emplace_back(4);
	G[5].emplace_back(6);
	G[6].emplace_back(1);
	G[6].emplace_back(2);
	G[6].emplace_back(4);
	G[6].emplace_back(5);
	int ans = 0;

	for (int S = 0; S < (1 << 7); S++)
	{
		if (check(S, G))
		{
			ans++;
		}
	}

	cout << ans << endl;

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}