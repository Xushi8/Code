// 2024/06/05 19:30:31
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
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	int index = max_element(a.begin(), a.end()) - a.begin();

	for (int i = index; i + 1 < n; i++)
	{
		if (a[i + 1] > a[i])
		{
			cout << "NO\n";
			return;
		}
	}

	for (int i = index; i - 1 >= 0; i--)
	{
		if (a[i - 1] > a[i])
		{
			cout << "NO\n";
			return;
		}
	}

	cout << "YES\n";
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