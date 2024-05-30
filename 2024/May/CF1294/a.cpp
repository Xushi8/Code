// 2024/05/27 17:38:18
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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt;
	cin >> tt;
	while (tt--)
	{
		int a[3];
		cin >> a[0] >> a[1] >> a[2];
		sort(a, a + 3);
		int n;
		cin >> n;
		int sum = 0;
		sum += (a[2] - a[0]) + (a[2] - a[1]);
		if (n < sum || (n - sum) % 3 != 0)
			cout << "NO\n";
		else
			cout << "YES\n";
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}