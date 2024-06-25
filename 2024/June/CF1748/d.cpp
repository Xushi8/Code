// 2024/06/25 22:28:12
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
	u64 a, b, d;
	cin >> a >> b >> d;
	i64 ans = 0;
	int k = countr_zero(d);
	for (int i = 0; i < 32; i++)
	{
		if ((((a | b) >> i) & 1) && ((ans >> i) & 1) == 0)
		{
			if (i < k)
			{
				ans = -1;
				break;
			}
			ans += d << (i - k); // 将该位加上d的最低位的1变为1
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