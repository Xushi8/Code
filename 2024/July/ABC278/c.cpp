// 2024/07/22 18:57:51
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
	int n, q;
	cin >> n >> q;
	// vector<set<int>> G(n);
	map<int, set<int>> G;
	while (q--)
	{
		int t, a, b;
		cin >> t >> a >> b;
        a--; b--;
		if (t == 1)
		{
			G[a].emplace(b);
		}
		else if (t == 2)
		{
			G[a].erase(b);
		}
		else
		{
			if (G[a].count(b) && G[b].count(a))
				cout << "Yes\n";
			else
				cout << "No\n";
        }
    }
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