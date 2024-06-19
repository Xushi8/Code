// 2024/06/19 17:47:35
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
	vector<i64> v1(n), w1(n), c1(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v1[i] >> w1[i] >> c1[i];
	}
	vector<i64> v2, w2;
	v2.reserve(15000);
	w2.reserve(15000);
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= c1[i]; j *= 2)
		{
			v2.emplace_back(v1[i] * j);
			w2.emplace_back(w1[i] * j);
			c1[i] -= j;
		}
		if (c1[i] != 0)
		{
			int j = c1[i];
			v2.emplace_back(v1[i] * j);
			w2.emplace_back(w1[i] * j);
			c1[i] -= j;
		}
	}

	swap(v2, w2);
	vector<i64> dp(W + 1);
	for (size_t i = 0; i < v2.size(); i++)
	{
		auto ndp = dp;
		for (int j = w2[i]; j <= W; j++)
		{
			ndp[j] = max(dp[j], dp[j - w2[i]] + v2[i]);
		}
		dp = std::move(ndp);
	}

	cout << *max_element(dp.begin(), dp.end()) << '\n';
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