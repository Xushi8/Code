// 2024/07/22 19:29:54
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
	vector<string> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	vector<vector<int>> G(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				continue;
			if (a[i].back() == a[j].front())
			{
				G[i].emplace_back(j);
			}
		}
	}

	array<int, 16> vis;
	auto dfs = [&](auto&& self, int u) -> bool
	{
		if (vis[u])
			return false;
		vis[u] = 1;
		for (auto v : G[u])
		{
			if (self(self, v))
				return false;
		}
		return true;
	};

	bool ok = false;
	for (int i = 0; i < n; i++)
	{
		vis.fill(0);
		ok |= dfs(dfs, i);
	}

	cout << (ok ? "First" : "Second") << '\n';
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