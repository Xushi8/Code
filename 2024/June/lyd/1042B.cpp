// 2024/06/17 17:24:18
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
	vector<int> a(n);
	iota(a.begin(), a.end(), 1);
	vector<i64> dp(n + 1);
	dp[0] = 1;

	constexpr i64 MOD = 2147483648;
	for (auto val : a)
	{
		auto ndp = dp;
		for (int j = val; j <= n; j++)
		{
			ndp[j] += ndp[j - val];
			ndp[j] %= MOD;
		}

		dp = std::move(ndp);
	}

	cout << dp[n] - 1 << '\n';
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