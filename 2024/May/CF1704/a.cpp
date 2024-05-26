// 2024/05/20 14:04:46
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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt;
	cin >> tt;
	while (tt--)
	{
		int n, m;
		cin >> n >> m;
		string s, t;
		cin >> s >> t;
		if (string_view(s.end() - (t.size() - 1), s.end()) == string_view(t.end() - (t.size() - 1), t.end()) && count(s.begin(), s.end() - (t.size() - 1), t.front()) > 0)
			cout << "YES\n";
		else
			cout <<"NO\n";
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}