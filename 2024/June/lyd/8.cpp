// 2024/06/20 15:07:36
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
	int n, W1, W2;
	cin >> n >> W1 >> W2;
	vector<int> w1(n), w2(n), v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> w1[i] >> w2[i] >> v[i];
	}

	vector<vector<int>> dp(W1 + 1, vector<int>(W2 + 1));
	for (int i = 0; i < n; i++)
	{
		auto ndp = dp;
		for (int j = w1[i]; j <= W1; j++)
		{
			for (int k = w2[i]; k <= W2; k++)
			{
				ndp[j][k] = max(dp[j][k], dp[j - w1[i]][k - w2[i]] + v[i]);
			}
		}
		dp = std::move(ndp);
	}

	cout << dp.back().back() << '\n';
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