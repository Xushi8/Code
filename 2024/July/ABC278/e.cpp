// 2024/07/22 19:08:11
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

void solve()
{
	int H, W, N, h, w;
	cin >> H >> W >> N >> h >> w;
	vector<vector<int>> a(H + 1, vector<int>(W + 1));
	map<int, int> mp;
	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j <= W; j++)
		{
			cin >> a[i][j];
			mp[a[i][j]]++;
		}
	}

	for (int i = h; i <= H; i++)
	{
		map<int, int> mp1;
		for (int j = w; j <= W; j++)
		{
			if (j == w)
			{
				for (int i1 = i - h + 1; i1 <= i; i1++)
				{
					for (int j1 = j - w + 1; j1 <= j; j1++)
					{
						mp1[a[i1][j1]]++;
					}
				}
			}
			else
			{
				for (int i1 = i - h + 1; i1 <= i; i1++)
				{
					mp1[a[i1][j - w]]--;
					mp1[a[i1][j]]++;
				}
			}

			int ans = 0;
			for (auto [val, cnt] : mp)
			{
				if (cnt - mp1[val] > 0)
					ans++;
			}
			cout << ans << ' ';
		}
		cout << '\n';
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