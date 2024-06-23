// 2024/06/22 11:01:48
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
	string s;
	cin >> s;
	i64 ans = 0;
	for (int i = 0; i < n; i++)
	{
		array<int, 10> cnt;
		cnt.fill(0);
		int diff = 0;
		int maxx = 0;
		for (int j = 0; i + j < n && j < 200; j++)
		{
			int val = s[i + j] - '0';
			if (++cnt[val] == 1)
				diff++;
			maxx = max(maxx, cnt[val]);
			if (maxx <= diff)
				ans++;
        }
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