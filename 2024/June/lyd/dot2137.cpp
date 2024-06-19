// 2024/06/19 17:42:43
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
	int n, W;
	cin >> n >> W;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	vector<i64> dp(W + 1);
	dp[0] = 1;
	for (int i = 0; i < n; i++)
	{
		auto ndp = dp;
		for (int j = v[i]; j <= W; j++)
		{
			ndp[j] += ndp[j - v[i]];
		}
		dp = std::move(ndp);
	}

	cout << dp.back() << '\n';
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