// 2024/06/21 22:33:28
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
	string s;
	cin >> s;
	reverse(s.begin(), s.end());

	int ans = 0;
	int jinwei = 0;
	for (size_t i = 0; i < s.size() - 1; i++)
	{
		int val = s[i] - '0' + jinwei;
		if (val == 10)
			jinwei = 1;
		else if (val != 0)
			jinwei = 1, ans += 10 - val;
		else
			jinwei = 0;
	}

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