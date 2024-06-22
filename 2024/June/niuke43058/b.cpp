// 2024/06/21 19:31:35
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
constexpr int MOD = 451 * 4;

constexpr i64 fpow(i64 a, size_t n)
{
	i64 b = 1;
	while (n)
	{
		if (n & 1)
		{
			b *= a;
			b %= MOD;
		}
		a *= a;
		a %= MOD;
		n /= 2;
	}
	return b;
}

i64 inv(i64 x)
{
	return fpow(x, MOD - 2);
}

void solve()
{
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (inv((fpow(i, 11) - i) * (fpow(i, 451) - fpow(i, 4))) == inv((fpow(i, 11) - fpow(i, 4)) * (fpow(i, 11) - i)))
		{
			ans++;
		}
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