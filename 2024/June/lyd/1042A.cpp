// 2024/06/17 17:19:47
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
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	vector<i64> dp(m + 1);
	dp[0] = 1;

	for (auto val : a)
	{
		auto ndp = dp;
		for (int j = val; j <= m; j++)
		{
			ndp[j] += dp[j - val];
		}

		dp = std::move(ndp);
	}

	cout << dp[m] << '\n';
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