// 2024/06/20 14:49:18
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
	vector<int> v(n), w(n), c(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i] >> w[i] >> c[i];
	}

	vector<int> v2, w2;
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= c[i]; j *= 2)
		{
			v2.emplace_back(v[i] * j);
			w2.emplace_back(w[i] * j);
			c[i] -= j;
		}
		if (c[i])
		{
			int j = c[i];
			v2.emplace_back(v[i] * j);
			w2.emplace_back(w[i] * j);
			c[i] -= j;
		}
	}

	swap(v2, w2);
    vector<int> dp(W + 1);
	for (int i = 0; i < v2.size(); i++)
	{
		auto ndp = dp;
		for (int j = w2[i]; j <= W; j++)
		{
			ndp[j] = max(dp[j], dp[j - w2[i]] + v2[i]);
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