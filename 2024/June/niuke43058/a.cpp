// 2024/06/21 19:16:12
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
	int n, m, k;
	cin >> n >> m >> k;
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	vector<pll> yang;
	for (int i = 0; i < k; i++)
	{
		int x, y;
        cin >> x >> y;
        yang.emplace_back(x, y);
	}
	yang.emplace_back(a, b);
	yang.emplace_back(c - 1, d - 1);

	constexpr int INF = 2e9;
	i64 minx = INF, miny = INF, maxx = -INF, maxy = -INF;

	for (auto [x, y] : yang)
	{
		minx = min(minx, x);
		maxx = max(maxx, x + 1);
		miny = min(miny, y);
		maxy = max(maxy, y + 1);
	}

	i64 ans = ((maxx - minx) + (maxy - miny)) * 2;
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