// 2024/03/27 14:00:23
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

int deep[N];

int maxn;

void dfs(int u, int now, vector<vector<int>> const& G)
{
	deep[u] = now;
	maxn = max(maxn, now);
	for (int v : G[u])
	{
		dfs(v, now + 1, G);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<vector<int>> G(n + 1);
	int root;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		if (x == -1)
		{
			root = i;
		}
		else
		{
			G[x].emplace_back(i);
		}
	}

	dfs(root, 0, G);

	cout << maxn + 1 << '\n';
	vector<int> ans;
	for (int i = 1; i <= n; i++)
	{
		if (deep[i] == maxn)
			ans.emplace_back(i);
	}

	for (int i = 0; i < ans.size(); i++)
	{
		if (i != 0)
			cout << ' ';
		cout << ans[i];
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}