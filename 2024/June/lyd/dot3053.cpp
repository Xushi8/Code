// 2024/06/18 13:33:02
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

// void solve()
// {
// 	int n;
// 	cin >> n;
// 	vector<int> a(n);
// 	for (int i = 0; i < n; i++)
// 	{
// 		cin >> a[i];
// 	}

// 	constexpr int INF = 1e9;
// 	vector<int> vec(n + 1, -INF);
// 	for (int i = 0; i < n; i++)
// 	{
// 		auto it = upper_bound(vec.begin(), vec.end(), a[i], greater<>());
// 		*it = a[i];
// 	}

// 	int ans;
// 	ans = lower_bound(vec.begin(), vec.end(), -INF, greater<>()) - vec.begin();

// 	vec.assign(n, -INF);
// 	for (int i = n - 1; i >= 0; i--)
// 	{
// 		auto it = upper_bound(vec.begin(), vec.end(), a[i], greater<>());
// 		*it = a[i];
// 	}
// 	int t = lower_bound(vec.begin(), vec.end(), -INF, greater<>()) - vec.begin();
// 	ans = max(ans, t);

// 	cout << ans << '\n';
// }

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	constexpr int INF = 1e9;
	vector<int> vec(n + 1, INF);
	for (int i = 0; i < n; i++)
	{
		auto it = upper_bound(vec.begin(), vec.end(), a[i]);
		*it = a[i];
	}

	int ans;
	ans = lower_bound(vec.begin(), vec.end(), INF) - vec.begin();

	vec.assign(n, INF);
	for (int i = n - 1; i >= 0; i--)
	{
		auto it = upper_bound(vec.begin(), vec.end(), a[i]);
		*it = a[i];
	}
	int t = lower_bound(vec.begin(), vec.end(), INF) - vec.begin();
	ans = max(ans, t);

	cout << ans << '\n';
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