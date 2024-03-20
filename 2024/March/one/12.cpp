// 2024/03/20 14:42:06
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
constexpr int N = 100005;

char sex[N];
vector<vector<int>> par;

bool vis[N];
bool flag;

void dfs(int deep, int u)
{
	if (deep == 4 || !flag)
		return;
	for (auto v : par[u])
	{
		if (!vis[v])
		{
			vis[v] = 1;
			dfs(deep + 1, v);
		}
		else
		{
			flag = 0;
			return;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	par.resize(N);
	for (int i = 0; i < n; i++)
	{
		int id;
		char ch;
		int fa, ma;
		cin >> id >> ch >> fa >> ma;
		sex[id] = ch;
		if (fa != -1)
		{
			sex[fa] = 'M';
			par[id].emplace_back(fa);
		}
		if (ma != -1)
		{
			sex[ma] = 'F';
			par[id].emplace_back(ma);
		}
	}

	int q;
	cin >> q;
	while (q--)
	{
		int u, v;
		cin >> u >> v;
		if (sex[u] == sex[v])
			cout << "Never Mind" << '\n';
		else
		{
			flag = 1;
			memset(vis, 0, sizeof(vis));
			vis[u] = 1;
			vis[v] = 1;
			dfs(0, u);
			dfs(0, v);
			cout << (flag ? "Yes" : "No") << '\n';
		}
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}