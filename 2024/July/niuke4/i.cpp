// 2024/07/25 12:06:02
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
	int n, m;
	cin >> n >> m;
	vector<set<int>> G(n + 1);
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		if (u > v)
			swap(u, v);
		G[u].emplace(v);
	}

	vector<int> boji(n + 1);
	for (int u = 1; u <= n; u++)
	{
		int now = u;
		for (auto v : G[u])
		{
			if (v != now + 1)
			{
				break;
			}
			now = v;
		}
		boji[u] = now;
	}

	i64 ans = 0;
	for (int i = n - 1; i >= 1; i--)
	{
		boji[i] = min(boji[i], boji[i + 1]);
	}
	for (int i = n; i >= 1; i--)
	{
		ans += (boji[i] - i + 1);
	}
	cout << ans << '\n';
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