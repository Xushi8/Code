// 2024/06/20 15:31:09
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
	int tar1, tar2;
	cin >> tar1 >> tar2;
	int n;
	cin >> n;
	vector<int> w1(n), w2(n), v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> w1[i] >> w2[i] >> v[i];
    }
	constexpr int INF = 1e9;
	// int W1 = accumulate(w1.begin(), w1.end(), 0);
	// int W2 = accumulate(w2.begin(), w2.end(), 0);
	// vector<vector<int>> dp(W1 + 1, vector<int>(W2 + 1, INF));
	// dp[0][0] = 0;

	// for (int i = 0; i < n; i++)
	// {
	// 	auto ndp = dp;
	// 	for (int j = w1[i]; j <= W1; j++)
	// 	{
	// 		for (int k = w2[i]; k <= W2; k++)
	// 		{
	// 			ndp[j][k] = min(dp[j][k], dp[j - w1[i]][k - w2[i]] + v[i]);
    //         }
	// 	}
	// 	dp = std::move(ndp);
	// }

	// int ans = INF;
	// for (int i = tar1; i <= W1; i++)
	// {
	// 	for (int j = tar2; j <= W2; j++)
	// 	{
	// 		ans = min(ans, dp[i][j]);
	//     }
	// }
	// cout << ans << '\n';

	vector<vector<int>> dp(tar1 + 1, vector<int>(tar2 + 1, INF));
    dp[0][0] = 0;
	for (int i = 0; i < n; i++)
	{
		auto ndp = dp;
		for (int j = 0; j <= tar1; j++)
		{
			for (int k = 0; k <= tar2; k++)
			{
				ndp[j][k] = min(dp[j][k], dp[max(j - w1[i], 0)][max(k - w2[i], 0)] + v[i]);
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