// 2024/07/28 15:46:11
#ifdef LOCAL
#include <basic_std_lib.h>
#else
#include <bits/stdc++.h>
#endif
using namespace std;


void solve();

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

using i64 = int64_t;
using u64 = uint64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 1000005;

void solve()
{
	i64 x;
	cin >> x;
	i64 y = sqrt(x);
	i64 ans = x + 2;
	for (i64 i = max(y - 100, i64(2)); i <= y + 100; i++)
	{
		if (x % 2 == 1 && i % 2 == 1)
			continue;
		i64 z = (x - 1) / (i - 1) + 1;
		if (z * (i - 1) % 2 != x % 2)
			z++;
		ans = min(ans, z + i);
	}
	cout << ans << '\n';
}