// 2024/07/29 12:12:42
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
	int n, m, q;
	cin >> n >> m >> q;
	vector<array<int, 3>> query(q);
	for (int i = 0; i < q; i++)
	{
		string s1, s2;
		int index;
		cin >> s1 >> index >> s2;
		int a1, a2;
		a1 = s1 != "row";
		a2 = s2 != "off";
		query[i] = {a1, index, a2};
	}
	reverse(query.begin(), query.end());
	i64 ans = 0;
	set<int> row_in, row_off, col_in, col_off;
	for (auto [is_col, index, op] : query)
	{
		if (!is_col) // row
		{
			if (op == 0)
			{
				if (!row_in.count(index))
				{
					row_off.emplace(index);
				}
			}
			else
			{
				if (!row_off.count(index))
				{
					auto [it, ok] = row_in.emplace(index);
					if (ok)
						ans += m - col_off.size() - col_in.size();
				}
			}
		}
		else // col
		{
			if (op == 0)
			{
				if (!col_in.count(index))
				{
					col_off.emplace(index);
				}
			}
			else
			{
				if (!col_off.count(index))
				{
					auto [it, ok] = col_in.emplace(index);
					if (ok)
						ans += n - row_in.size() - row_off.size();
				}
			}
		}
	}

	cout << ans << '\n';
}