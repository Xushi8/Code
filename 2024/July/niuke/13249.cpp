// 2024/07/24 18:43:13
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
	vector<vector<int>> G(n + 1);
	for (int u = 2; u <= n; u++)
	{
		int v;
		cin >> v;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	vector<int> k(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> k[i];
	}

	int ans = 0;
	

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