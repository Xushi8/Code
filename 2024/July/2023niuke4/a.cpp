// 2024/07/29 14:53:20
#ifdef LOCAL
#include <basic_std_lib.h>
#else
#include <bits/stdc++.h>
#endif
using namespace std;


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

using i64 = int64_t;
using u64 = uint64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 1000005;

void solve()
{
	int n;
	string s;
	cin >> n >> s;
	string ans = s + string(n, '0') + s;

	auto t = ans.substr(1);
	auto pos = t.find(s);
	if (pos != t.size() - s.size())
	{
		// ans = s + string(n, '1') + s;
		ans = string(n, '1');
	}
	else
	{
		ans = string(n, '0');
    }
	cout << ans << '\n';
}