// 2024/07/25 12:08:20
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

long double dis(long double x1, long double y1, long double x2, long double y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void solve()
{
	long double x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	if (x1 > x2)
	{
		swap(x1, x2);
		swap(y1, y2);
	}
	long double ans = 1e30;
	ans = min({ans, dis(-x1, y1, x2, y2), dis(x1, y1, x2, -y2)});
	cout << ans << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << setprecision(20) << fixed;

	// cout << 2 * sqrt(5) << endl;

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