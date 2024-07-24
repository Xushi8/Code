// 2024/07/24 23:04:45
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
	int H, W, q;
	cin >> H >> W >> q;
	set<int> row, col;
	vector<array<int, 3>> queries(q);
	for (int i = 0; i < q; i++)
	{
		int t, index, x;
		cin >> t >> index >> x;
		queries[i] = {t, index, x};
	}
	reverse(queries.begin(), queries.end());
	map<int, i64> mp;
	i64 sum = 0;
	for (auto [t, index, x] : queries)
	{
		if (t == 1)
		{
			if (row.count(index))
				continue;
			mp[x] += W - col.size();
			if (x != 0)
			{
				sum += W - col.size();
			}
			row.emplace(index);
		}
		else
		{
			if (col.count(index))
				continue;
			mp[x] += H - row.size();
			if (x != 0)
			{
				sum += H - row.size();
			}
			col.emplace(index);
		}
	}
	mp[0] = i64(H) * W - sum;
	vector<pll> ans(mp.begin(), mp.end());
	ans.erase(remove_if(ans.begin(), ans.end(), [](pii const& val)
				  {
					  return val.second == 0;
				  }),
		ans.end());
	cout << ans.size() << '\n';
	for (auto [x, y] : ans)
	{
		cout << x << ' ' << y << '\n';
	}
}