// 2024/06/17 17:30:38
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

void solve(int n, int m)
{
	vector<int> a(n), cnt(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> cnt[i];
	}

	vector<int> all;
	for (int i = 0; i < n; i++)
	{
		int val = a[i];
		int count = cnt[i];
		for (int j = 1; j <= count; j *= 2)
		{
			all.emplace_back(val * j);
			count -= j;
		}
		if (count != 0)
		{
			all.emplace_back(val * count);
		}
	}

	vector<i64> dp(m + 1);
	dp[0] = 1;

	for (auto val : all)
	{
		auto ndp = dp;
		for (int j = val; j <= m; j++)
		{
			ndp[j] += dp[j - val];
		}
		dp = std::move(ndp);
	}

	cout << m - std::count(dp.begin(), dp.end(), 0) << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	while (cin >> n >> m && (n || m))
	{
		solve(n, m);
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}