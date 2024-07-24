// 2024/07/24 22:42:14
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
    s = ' ' + s;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	vector<vector<i64>> f(n + 2, vector<i64>(2));
	auto g = f;
	for (int i = 1; i <= n; i++)
	{
		f[i][0] = f[i - 1][1] + (s[i] == '1' ? 0 : a[i]);
		f[i][1] = f[i - 1][0] + (s[i] == '0' ? 0 : a[i]);
	}
	for (int i = n; i >= 1; i--)
	{
		g[i][0] = g[i + 1][1] + (s[i] == '1' ? 0 : a[i]);
		g[i][1] = g[i + 1][0] + (s[i] == '0' ? 0 : a[i]);
	}

	i64 ans = 4e18;
	for (int i = 1; i <= n - 1; i++)
	{
		ans = min({ans, f[i][0] + g[i + 1][0], f[i][1] + g[i + 1][1]});
	}
	cout << ans << '\n';
}