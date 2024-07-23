// 2024/07/22 18:52:05
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
	int h, m;
	cin >> h >> m;
	for (int tim = h * 60 + m;; tim++)
	{
		if (tim == 24 * 60)
			tim = 0;
		int h1 = tim / 60;
		int m1 = tim % 60;
		int h2 = h1 / 10 * 10 + m1 / 10;
		int m2 = h1 % 10 * 10 + m1 % 10;
		if (0 <= h2 && h2 < 24 && 0 <= m2 && m2 < 60)
		{
			cout << h1 << ' ' << m1 << '\n';
			break;
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