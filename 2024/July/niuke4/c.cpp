// 2024/07/25 12:34:14
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
	vector<int> a(n + 1);
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		cnt += (a[i] != i);
	}
	if (cnt == 0)
	{
		cout << 0 << '\n';
		return;
	}
	if (cnt <= 4)
	{
		cout << 1 << '\n';
		return;
	}
	vector<int> siz;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] != i)
		{
			set<int> st;
			st.emplace(i);
			int now = a[i];
			while (!st.count(now))
			{
				st.emplace(now);
				now = a[now];
			}
			siz.emplace_back(st.size());
			for (auto x : st)
			{
				a[x] = x;
			}
		}
	}
	int ans = 0;
	for (auto& x : siz)
	{
		// cout << x << ' ';
		while (x > 4)
		{
			ans++;
			x -= 3;
        }
    }
	sort(siz.begin(), siz.end());
	auto it1 = lower_bound(siz.begin(), siz.end(), 2);
	auto it2 = upper_bound(siz.begin(), siz.end(), 2);
	ans += (it2 - it1 + 1) / 2;
	ans += siz.end() - it2;
	
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