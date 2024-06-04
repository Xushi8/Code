// 2024/06/03 21:17:48
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
constexpr int MOD = 998244353;

void solve()
{
	int n, k;
	cin >> n >> k;
	vector<i64> dp(n + 1);
	dp[0] = 1;

	vector<i64> ans(n + 1);
	int buchang = 0;
	while (buchang <= n)
	{
		vector<i64> tmp(n + 1);
		for (int i = 0; i + k <= n; i++)
		{
			tmp[i + k] += dp[i];
			tmp[i + k] %= MOD;
		}

		for (int i = 0; i + k <= n; i++)
		{
			tmp[i + k] += tmp[i];
			tmp[i + k] %= MOD;
		}

		buchang += k;
		k++;
		dp = std::move(tmp);
		for (int i = 1; i <= n; i++)
		{
			ans[i] += dp[i];
			ans[i] %= MOD;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		cout << ans[i] << ' ';
	}
	cout << '\n';
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