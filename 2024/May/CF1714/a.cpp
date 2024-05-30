// 2024/05/29 22:30:04
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
		int n, h, m;
		cin >> n >> h >> m;
		int t1 = h * 60 + m;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
		{
			int x, y;
			cin >> x >> y;
			a[i] = x * 60 + y;
		}

		sort(a.begin(), a.end());

		auto it = lower_bound(a.begin(), a.end(), t1);
		int tim;
		if (it == a.end())
		{
			tim = 60 * 24 - t1;
			tim += a.front();
		}
		else
		{
			tim = *it - t1;
		}
		cout << tim / 60 << ' ' << tim % 60 << '\n';
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}