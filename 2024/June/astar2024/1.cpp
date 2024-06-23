// 2024/06/23 12:48:14
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
	int n, s;
	cin >> n >> s;
	vector<pii> a(n);
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		a[i] = {x, y};
	}

	sort(a.begin(), a.end(), [](pii const& l, pii const& r)
		{
			return l.first + l.second < r.first + r.second;
		});

	int i = 0;
	int ans = 0;
	for (; i < n; i++)
	{
		if (s >= a[i].first + a[i].second)
		{
			s -= a[i].first + a[i].second;
			ans++;
		}
		else
		{
			break;
		}
	}

	sort(a.begin() + i, a.end(), [](pii const& l, pii const& r)
		{
			return l.first / 2 + l.second < r.first / 2 + r.second;
		});

	for (; i < n; i++)
	{
		if (s >= a[i].first / 2 + a[i].second)
		{
			s -= a[i].first / 2 + a[i].second;
			ans++;
		}
		else
		{
			break;
		}
	}

#if __cplusplus >= 201703L
	cout << ans << '\n';
#endif
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