// 2024/07/24 13:01:57
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
	vector<i64> a(n + 4), b(n + 4);
	for (int i = 2; i <= n + 1; i++)
	{
		cin >> a[i];
	}
	for (int i = 2; i <= n + 1; i++)
	{
		cin >> b[i];
	}

	vector<vector<i64>> dp(n + 4, vector<i64>(3));
	for (int i = 2; i <= n + 1; i++)
	{
		if (b[i] == 1)
		{
			dp[i][0] = max({
				dp[i - 2][0] + a[i - 1],
				dp[i - 2][1] + a[i - 1],
				dp[i - 1][0] + a[i - 1],
				dp[i - 1][1],
			});
			dp[i][1] = max({
				dp[i - 2][0] + a[i],
				dp[i - 2][1] + a[i],
				dp[i - 2][2] + a[i],
				dp[i - 1][0] + a[i],
				dp[i - 1][1] + a[i],
				dp[i - 1][2],
			});
			dp[i][2] = max({
				dp[i - 2][0] + a[i + 1],
				dp[i - 2][1] + a[i + 1],
				dp[i - 2][2] + a[i + 1],
				dp[i - 1][0] + a[i + 1],
				dp[i - 1][1] + a[i + 1],
				dp[i - 1][2] + a[i + 1],
			});
		}
		else
		{
			dp[i][0] = max({
				dp[i - 2][0],
				dp[i - 2][1],
				dp[i - 1][0],
				dp[i - 1][1],
			});
			dp[i][1] = max({
				dp[i - 2][0],
				dp[i - 2][1],
				dp[i - 2][2],
				dp[i - 1][0],
				dp[i - 1][1],
				dp[i - 1][2],
			});
			dp[i][2] = max({
				dp[i - 2][0],
				dp[i - 2][1],
				dp[i - 2][2],
				dp[i - 1][0],
				dp[i - 1][1],
				dp[i - 1][2],
			});
		}
	}

	cout << max({dp[n + 1][0], dp[n + 1][1], dp[n + 2][2]}) << '\n';
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