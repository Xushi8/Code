// 2024/07/23 19:53:56
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
constexpr int N = 55;

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

void solve()
{
	string s, t;
	cin >> s >> t;
	const int n = s.size(), m = t.size();
	s = ' ' + s;
	t = ' ' + t;
	static bool dp[N][N][N][N];

	int ans = 0;
	for (int len1 = 0; len1 <= n; len1++)
	{
		for (int len2 = 0; len2 <= m; len2++)
		{
			for (int l1 = 1; l1 + len1 - 1 <= n; l1++)
			{
				for (int l2 = 1; l2 + len2 - 1 <= m; l2++)
				{
					int r1 = l1 + len1 - 1;
					int r2 = l2 + len2 - 1;
					if (len1 + len2 < 2) // 单个字母
					{
						dp[l1][r1][l2][r2] = true;
					}
					else
					{
						bool& val = dp[l1][r1][l2][r2];
						val = 0;
						if (s[l1] == s[r1])
							val |= dp[l1 + 1][r1 - 1][l2][r2];
						if (t[l2] == t[r2])
							val |= dp[l1][r1][l2 + 1][r2 - 1];
						if (s[l1] == t[r2])
							val |= dp[l1 + 1][r1][l2][r2 - 1];
						if (t[l2] == s[r1])
							val |= dp[l1][r1 - 1][l2 + 1][r2];
					}
					if (dp[l1][r1][l2][r2])
						ans = max(ans, len1 + len2);
				}
			}
		}
	}
	cout << ans << '\n';
}