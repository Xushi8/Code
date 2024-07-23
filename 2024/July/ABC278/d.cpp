// 2024/07/22 19:02:19
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
	int n;
	cin >> n;
	vector<i64> a(n);
	vector<int> now(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int q;
	cin >> q;
	int tim = 0;
	int base;
	while (q--)
	{
		int t;
		cin >> t;
		if (t == 1)
		{
			cin >> base;
			tim++;
		}
		else if (t == 2)
		{
			int i, x;
			cin >> i >> x;
            i--;
			if (now[i] < tim)
			{
				now[i] = tim;
				a[i] = base;
			}
			a[i] += x;
		}
		else
		{
			int i;
			cin >> i;
            i--;
			if (now[i] < tim)
			{
				now[i] = tim;
				a[i] = base;
			}
			cout << a[i] << '\n';
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