// 2024/06/21 22:43:44
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
constexpr int N = 100005;

int yinzi_count(int val)
{
	map<int, int> mp;
	for (int i = 2; i * i <= val; i++)
	{
		while (val % i == 0)
		{
			mp[i]++;
			val /= i;
		}
	}
	if (val != 1)
	{
		mp[val]++;
	}
	int res = 1;
	for (auto [x, y] : mp)
	{
		res *= (y + 1);
	}
	return res;
}

void solve()
{
	// vector<int> yinzi(N);
	// for (int i = 1; i < N; i++)
	// {
	// 	for (int j = i; j < N; j += i)
	// 	{
	// 		yinzi[j]++;
	// 	}
	// }

	int n, q;
	cin >> n >> q;

	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		// a[i] = yinzi[x];
		a[i] = yinzi_count(x);
	}

	map<int, vector<int>> mp;
	for (int i = 0; i < n; i++)
	{
		mp[a[i]].emplace_back(i);
	}

	while (q--)
	{
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		i64 ans = 0;
		for (auto const& [t, vec] : mp) // log
		{
			i64 cnt = 0;
			cnt = upper_bound(vec.begin(), vec.end(), r) - lower_bound(vec.begin(), vec.end(), l); // 2 * log
			if (cnt >= 2)
			{
				ans += cnt * (cnt - 1) / 2;
			}
		}
		cout << ans << '\n';
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