// 2024/07/24 14:54:10
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

bool dfs(set<array<int, 3>>& st, array<int, 3> a, int n)
{
	if (st.count(a))
		return false;
	st.emplace(a);
	for (int i = 0; i < 3; i++)
	{
		if (a[i] - 1 >= 1)
		{
			auto t = a;
			t[i] = a[i] - 1;
			if (dfs(st, t, n))
			{
				st.erase(a);
				return false;
			}
		}
		if (a[i] + 1 <= n)
		{
			auto t = a;
			t[i] = a[i] + 1;
			if (dfs(st, t, n))
			{
				st.erase(a);
				return false;
			}
		}
	}

	st.erase(a);
	return true;
}

void solve()
{
	int n;
	cin >> n;
	array<int, 3> a;
	for (int i = 0; i < 3; i++)
	{
		cin >> a[i];
	}

	set<array<int, 3>> st;
	cout << (!dfs(st, a, n) ? "Alice" : "Bob") << '\n';
	cout << flush;
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