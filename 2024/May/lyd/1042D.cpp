// 2024/05/31 16:34:43
#ifdef LOCAL
#include <basic_std_lib.h>
#else
#include <bits/stdc++.h>
#endif
using namespace std;

using i64 = int64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 1000005;

void solve(int n, int m)
{
	vector<int> a(n), cnt(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> cnt[i];

	vector<int> arr;
	arr.reserve(10 * n);

	for (int i = 0; i < n; i++)
	{
		for (int k = 1; k < cnt[i]; k *= 2)
		{
			arr.emplace_back(a[i] * k);
			cnt[i] -= k;
		}
		if (cnt[i] > 0)
		{
			arr.emplace_back(a[i] * cnt[i]);
		}
	}

	int tot = arr.size();
	arr.insert(arr.begin(), 0);

	vector<vector<i64>> dp(2, vector<i64>(m + 1));
	dp[0][0] = 1;

	for (int i = 1; i <= tot; i++)
	{
		dp[i & 1] = dp[(i - 1) & 1];
		for (int j = arr[i]; j <= m; j++)
		{
			dp[i & 1][j] += dp[(i - 1) & 1][j - arr[i]];
		}
	}

	cout << m - count(dp[tot & 1].begin(), dp[tot & 1].end(), 0) << '\n';
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