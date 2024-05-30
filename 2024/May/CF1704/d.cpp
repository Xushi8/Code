// 2024/05/26 12:10:27
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

void solve()
{
	size_t n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}

	map<i64, int> mp;
	map<i64, int> mp1;
	for (size_t i = 0; i < n; i++)
	{
		i64 sum = 0;
		for (size_t j = 0; j < m; j++)
		{
			sum += j * a[i][j];
		}
		mp[sum]++;
		mp1[sum] = i;
	}

	auto [x, y] = *mp.begin();
	auto [ex, ey] = *--mp.end();
	if (y == 1)
	{
		cout << mp1[x] + 1 << ' ' << x - ex << '\n';
	}
	else
	{
		cout << mp1[ex] + 1 << ' ' << ex - x << '\n';
    }
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt;
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