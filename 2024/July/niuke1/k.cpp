// 2024/07/20 11:49:21
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
	vector<vector<int>> G1(n);
    vector<int> deg1(n);
	for (int i = 0; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		G1[u].emplace_back(v);
		G1[v].emplace_back(u);
		deg1[u]++;
		deg1[v]++;
	}

	int m;
	cin >> m;
	vector<vector<int>> G2(m);
	vector<int> deg2(m);
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
        u--; v--;
		G2[u].emplace_back(v);
		G2[v].emplace_back(u);
		deg2[u]++;
		deg2[v]++;
	}

	auto dfs = [&](auto&& self, int u1, int u2, int par1, int par2) -> bool
	{
		if (deg1[u1] < deg2[u2])
			return false;

		for (auto v2 : G2[u2])
		{
			if (v2 == par2)
				continue;
			for (auto v1 : G1[u1])
			{
				
            }
		}

		return true;
    };

	if (dfs(dfs, 0, 0, -1, -1))
		cout << "Yes\n";
	else
		cout << "No\n";
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