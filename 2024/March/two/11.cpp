// 2024/03/23 19:48:29
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
bool flag;

void dfs(int u, vector<vector<int>> const& G, vector<bool>& vis, vector<int> const& color)
{
	if (vis[u] || !flag)
		return;
	vis[u] = 1;
	for (int v : G[u])
	{
		if (color[u] == color[v])
		{
			flag = 0;
			return;
		}

		dfs(v, G, vis, color);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	int v, e, k;
	cin >> v >> e >> k;
	vector<vector<int>> G(v);
	vector<int> color(v);
	vector<bool> vis(v);
	for (int i = 0; i < e; i++)
	{
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		G[x].emplace_back(y);
		G[y].emplace_back(x);
	}

	int q;
	cin >> q;
	while (q--)
	{
		set<int> st;
		for (int i = 0; i < v; i++)
		{
			int x;
			cin >> x;
			x--;
			color[i] = x;
			st.emplace(x);
		}
		if (st.size() > k)
		{
			cout << "No" << '\n';
			continue;
        }
		
		flag = 1;
		for (int i = 0; i < v; i++)
		{
			vis[i] = 0;
        }

		for (int i = 0; i < v; i++)
		{
			dfs(i, G, vis, color);
		}
        cout << (flag ? "Yes" : "No") << '\n';
    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}