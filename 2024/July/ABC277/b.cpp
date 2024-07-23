// 2024/07/22 20:42:07
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
bool check(string_view s)
{
	set<char> a{'H', 'D', 'C', 'S'};
	set<char> b{'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
	if (!a.count(s[0]) || !b.count(s[1]) || s[0] == s[1])
		return false;
	return true;
}

void solve()
{
	size_t n;
	cin >> n;
	string s;
	bool ok = true;
	set<string> st;
	for (size_t i = 0; i < n; i++)
	{
		cin >> s;
		st.emplace(s);
		ok &= check(s);
	}
	ok &= (st.size() == n);
	cout << (ok ? "Yes" : "No") << '\n';
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