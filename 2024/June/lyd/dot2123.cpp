// 2024/06/19 15:07:40
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
	vector<int> a;
	{
		int x;
		while (cin >> x)
		{
			a.push_back(x);
		}
	}
	reverse(a.begin(), a.end());

	constexpr int INF = 1e9;
	vector<int> t(a.size() + 1, INF);
	for (auto x : a)
	{
		*upper_bound(t.begin(), t.end(), x) = x;
	}

	cout << lower_bound(t.begin(), t.end(), INF) - t.begin() << '\n';

	t.assign(a.size() + 1, INF);
	reverse(a.begin(), a.end());
	for (auto x : a)
	{
		*lower_bound(t.begin(), t.end(), x) = x;
	}

	cout << lower_bound(t.begin(), t.end(), INF) - t.begin() << '\n';
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