// 2024/07/22 20:49:01
#ifdef LOCAL
#include <basic_std_lib.h>
#else
#include <bits/stdc++.h>
#endif
using namespace std;

using i64 = int64_t;
using u64 = uint64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 1000005;

void solve()
{
	int n;
	cin >> n;
	map<int, vector<int>> G;
	for (int i = 0; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}

	set<int> vis;
	queue<int> que;
	que.emplace(1);
	vis.emplace(1);
	while (!que.empty())
	{
		auto u = que.front();
		que.pop();
		for (int v : G[u])
		{
			if (!vis.count(v))
			{
				vis.emplace(v);
				que.emplace(v);
			}
		}
	}

	cout << *--vis.end() << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt;
	tt = 1;
	while (tt--)
	{
		solve();
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}