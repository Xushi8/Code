// 2024/07/26 12:00:23
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

i64 toll(string_view s)
{
	i64 res = 0;
	for (size_t i = s.size(), j = 0; i--; j++)
	{
		if (s[i] == '1')
		{
			res |= 1ll << j;
		}
	}
	return res;
}

i64 toll(string_view s, int)
{
	string t(s.rbegin(), s.rend());
	i64 res = 0;
	for (size_t i = 0; i < s.size(); i++)
	{
		if (t[i] == '1')
		{
			res |= 1ll << i;
		}
	}
	return res;
}

void solve()
{
	string s, t;
	cin >> s >> t;
	// i64 a = stoll(s, 0, 2);
	// i64 b = stoll(t, 0, 2);
	i64 a = toll(s);
	i64 b = toll(t);
	// i64 a = toll(s, 1);
	// i64 b = toll(t, 1);
	// i64 a = 0, b = 0;
	// reverse(s.begin(), s.end());
	// reverse(t.begin(), t.end());
	// for (size_t i = 0; i < s.size(); i++)
	// {
	// 	if (s[i] == '1')
	// 	{
	// 		a |= 1ll << i;
	// 	}
	// 	if (t[i] == '1')
	// 	{
	// 		b |= 1ll << i;
	// 	}
	// }
	// cout << a << ' ' << b << '\n';
	if (a == 0 && b != 0)
	{
		cout << -1 << '\n';
		return;
	}
	cout << abs(a - b) << '\n';
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