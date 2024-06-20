// 2024/06/20 17:00:28
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
	int W, n;
	cin >> W >> n;
	vector<int> v(n), w(n);
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v[i] = x * y;
		w[i] = x;
	}

	vector<int> dp(W + 1);
	for (int i = 0; i < n; i++)
	{
		auto ndp = dp;
		for (int j = w[i]; j <= W; j++)
		{
			ndp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
        dp = std::move(ndp);
	}

	cout << dp[W] << '\n';
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