// 2024/07/22 15:36:42
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
	const int n = 2;
	int m;
	cin >> m;
	vector<vector<int>> a(n, vector<int>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}

	vector<pii> dec(m);
	for (int j = 0; j < m; j++)
	{
		dec[j] = {a[0][j] - a[1][j], j};
	}

	sort(dec.begin(), dec.end());
	if (dec.front().first * dec.back().first < 0)
	{
		swap(a[0][dec.front().second], a[0][dec.back().second]);
	}
	i64 sum = 0;
	for (int j = 0; j < m; j++)
	{
		sum += abs(a[0][j] - a[1][j]);
	}
	cout << sum << '\n';
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