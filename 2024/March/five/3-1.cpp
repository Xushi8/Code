// 2024/04/03 20:33:18
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

int cnt[N];
bool flag;

int dfs(int u, vector<vector<int>> const& G)
{
	if (cnt[u] != 0)
		return cnt[u];
	for (int v : G[u])
	{
		dfs(v, G);
		cnt[u] += cnt[v];
	}
	if (cnt[u] == 0)
	{
		flag = 0;
	}
	return cnt[u];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> G(n);
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		G[u].emplace_back(v);
	}

	int be, ed;
	cin >> be >> ed;
	be--;
	ed--;
	cnt[ed] = 1;
	flag = 1;
	dfs(be, G);

	cout << cnt[be] << ' ' << (flag ? "Yes" : "No") << '\n';

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}