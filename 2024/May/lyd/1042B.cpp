// 2024/05/31 16:25:30
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

constexpr i64 MOD = 2147483648;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<vector<i64>> dp(2, vector<i64>(n + 1));
	dp[0][0] = 1;

	for (int i = 1; i <= n; i++)
	{
		dp[i & 1] = dp[(i - 1) & 1];
		for (int j = i; j <= n; j++)
		{
			dp[i & 1][j] += dp[i & 1][j - i];
			dp[i & 1][j] %= MOD;
		}
	}

	cout << dp[n & 1][n] - 1 << '\n';

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}