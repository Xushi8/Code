// 2024/06/20 14:55:19
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
	vector<int> v1(n), w1(n), c1(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v1[i] >> w1[i] >> c1[i];
		if (c1[i] == -1)
			c1[i] = 1;
	}

	vector<int> v, w, c;
	for (int i = 0; i < n; i++)
	{
		if (c1[i] > 0)
		{
			for (int j = 1; j <= c1[i]; j *= 2)
			{
				v.emplace_back(j * v1[i]);
				w.emplace_back(j * w1[i]);
                c.emplace_back(0);
				c1[i] -= j;
			}
			if (c1[i])
			{
				int j = c1[i];
				v.emplace_back(j * v1[i]);
				w.emplace_back(j * w1[i]);
                c.emplace_back(0);
				c1[i] -= j;
			}
		}
		else
		{
			v.emplace_back(v1[i]);
			w.emplace_back(w1[i]);
			c.emplace_back(-1);
        }
	}

	swap(v, w);
	vector<int> dp(W + 1);
	for (int i = 0; i < v.size(); i++)
	{
		auto ndp = dp;
		if (c[i] == -1)
		{
			for (int j = w[i]; j <= W; j++)
			{
                ndp[j] = max(dp[j], ndp[j - w[i]] + v[i]);
            }
		}
		else
		{
			for (int j = w[i]; j <= W; j++)
			{
				ndp[j] = max(dp[j], dp[j - w[i]] + v[i]);
			}
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