// 2024/06/19 17:14:02
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
	int W;
	cin >> W;
	if (W == 0)
	{
		cout << 0 << '\n';
		return;
	}
	vector<int> v = {0, 10, 20, 50, 100};

	vector<i64> dp(W + 1);
	dp[0] = 1;
	for (size_t i = 1; i < v.size(); i++)
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