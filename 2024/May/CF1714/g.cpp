// 2024/05/30 12:54:46
#ifdef LOCAL
#include <basic_std_lib.h>
#else
#include <bits/stdc++.h>
#endif
using namespace std;

using i64 = int64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 1000005;

void solve()
{
	int n;
	cin >> n;
	vector<vector<array<int, 3>>> G(n);
	for (int i = 1; i < n; i++)
	{
		int par, w1, w2;
		cin >> par >> w1 >> w2;
		par--;
		G[par].push_back({i, w1, w2});
	}

	
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	int tt;
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