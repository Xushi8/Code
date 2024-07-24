// 2024/07/24 14:20:05
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

void biao()
{
	for (int i = 0; i <= 1000; i++)
	{
		cout << i * i << ' ' << i << '\n';
	}
	constexpr i64 x = 998244353;
	cout << x * x << '\n';
}

void solve()
{
	i64 x;
	cin >> x;
	i64 ans = 0;
	while (x != 1)
	{
		i64 y = sqrt(x);
		x -= y * y;
		ans = stoll(to_string(ans) + to_string(y));
	}
	cout << ans << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	biao();

	int tt;
	tt = 1;
	cin >> tt;
	while (tt--)
	{
		// solve();
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}