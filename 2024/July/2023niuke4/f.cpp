// 2024/07/29 12:44:33
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
	int n;
	cin >> n;
	deque<pii> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first;
		a[i].second = i + 1;
	}
	sort(a.begin(), a.end());

	auto check = [&](int val, int r) -> bool
	{
        return a[val].first - a[0].first > a[r].first - a[val].first;
    };

	while (a.size() > 1)
	{
		int l = 0, r = a.size() - 1;
		int ans = 0;
		while (l <= r)
		{
			int mid = l + (r - l) / 2;
			if (check(mid, r))
			{
				ans = mid;
				r = mid - 1;
			}
			else
			{
				l = mid + 1;
			}
		}

		int cnt2 = ans;
		int cnt1 = a.size() - cnt2;
		if (cnt1 > cnt2)
		{
            // cerr << a.front().first << ' ';
			a.pop_front();
		}
		else
		{
            // cerr << a.back().first << ' ';
			a.pop_back();
        }
	}
	cout << a.back().second << '\n';
}