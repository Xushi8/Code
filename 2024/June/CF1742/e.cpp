// 2024/06/20 20:55:23
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
	int n, q;
	cin >> n >> q;
	vector<i64> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	vector<i64> sum(n + 1);
	for (int i = 0; i < n; i++)
	{
		sum[i + 1] = sum[i] + a[i];
	}

	vector<i64> maxx(n + 1);
	
	for (int i = 1; i <= n; i++)
	{
		maxx[i] = max(maxx[i - 1], a[i - 1]);
	}

	while (q--)
	{
		i64 x;
		cin >> x;
		size_t index = upper_bound(maxx.begin(), maxx.end(), x) - 1 - maxx.begin();
		cout << sum[index] << ' ';
	}
	cout << '\n';
}

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