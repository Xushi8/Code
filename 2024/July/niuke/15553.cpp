// 2024/07/23 20:09:32
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

void solve();

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt;
	tt = 1;
	cin >> tt;
	while (tt--)
	{
		solve();
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}

void solve()
{
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector<i64> sum(n + 1);
	for (int i = 0; i < n; i++)
	{
		sum[i + 1] = sum[i] + a[i];
	}
	vector<i64> f1(n + 1, -9e18), f2(n + 1, -9e18);
	for (int i = k; i < n - k + 1; i++)
	{
		f1[i] = max(f1[i - 1], sum[i] - sum[i - k]);
	}

	for (int i = n - k + 1; i >= k + 1; i--)
	{
		f2[i] = max(f2[i + 1], sum[i + k - 1] - sum[i - 1]);
	}

	i64 ans = -9e18;
	for (int i = k; i + k <= n; i++)
	{
		ans = max(ans, f1[i] + f2[i + 1]);
	}

	cout << ans << '\n';
}