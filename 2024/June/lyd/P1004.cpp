// 2024/06/18 11:22:19
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
	vector<vector<int>> a(n + 1, vector<int>(n + 1));
	int x, y, w;
	while (cin >> x >> y >> w)
	{
		a[x][y] = w;
	}

	vector<vector<vector<int>>> dp(n * 2 + 1, vector<vector<int>>(n + 1, vector<int>(n + 1)));

	for (int index = 2; index <= 2 * n; index++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (!(1 <= index - i && index - i <= n && 1 <= index - j && index - j <= n))
					continue;
				dp[index][i][j] = max({dp[index][i][j],
					dp[index - 1][i - 1][j], dp[index - 1][i][j - 1], dp[index - 1][i - 1][j - 1], dp[index - 1][i][j]});
				int val = a[i][index - i];
				if (i != j)
					val += a[j][index - j];
				dp[index][i][j] += val;
			}
		}
	}

	cout << dp[n * 2][n][n] << '\n';
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