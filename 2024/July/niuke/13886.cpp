// 2024/07/24 18:00:40
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
	vector<vector<pii>> G(n + 1);
	for (int i = 0; i < n - 1; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		G[u].emplace_back(v, w);
		G[v].emplace_back(u, w);
	}
	vector<int> siz(n + 1, 1);
	i64 ans = 0;

	auto dfs = [&](auto&& self, int u, int par) -> void
	{
		for (auto [v, w] : G[u])
		{
			if (v == par)
				continue;
			self(self, v, u);
			siz[u] += siz[v];
			if (siz[v] % 2 == 1)
			{
				ans += w;
            }
        }
	};

	dfs(dfs, 1, 0);
	cout << ans << '\n';

	// for (auto x : siz)
	// {
	// 	cout << x << ' ';
	// }
	// cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    tt = 1;
    cin >> tt;
    while (tt--)
    {
        solve();
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}