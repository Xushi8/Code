// 2024/04/03 16:06:26
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

int trie[N * 32][2];
int cnt;

void insert(int x)
{
	int u = 0;
	for (int i = 31; i >= 0; i--)
	{
		int bit = (x >> i) & 1;
		int& v = trie[u][bit];
		if (v == 0)
			v = ++cnt;
		u = v;
	}
}

int find(int x)
{
	int u = 0;
	int res = 0;
	for (int i = 31; i >= 0; i--)
	{
		int bit = (x >> i) & 1;
		if (trie[u][!bit] != 0)
		{
			res |= (1 << i);
			u = trie[u][!bit];
		}
		else
		{
			u = trie[u][bit];
		}
	}

	return res;
}

void dfs(int u, int par, vector<vector<pii>> const& G, vector<int>& dis)
{
	int disu = dis.back();
	for (auto [v, w] : G[u])
	{
		if (v == par)
			continue;

		dis.emplace_back(disu ^ w);
		dfs(v, u, G, dis);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<vector<pii>> G(n);
	for (int i = 0; i < n - 1; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		G[u].emplace_back(v, w);
		G[v].emplace_back(u, w);
	}

	vector<int> dis;
	dis.emplace_back(0);
	dfs(0, -1, G, dis);

	int ans = 0;
	for (auto x : dis)
	{
		insert(x);
		ans = max(ans, find(x));
	}
	cout << ans << endl;

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}