// 2024/06/20 21:13:36
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
	int q;
	cin >> q;
	vector<vector<i64>> cnt(2, vector<i64>(26));
	cnt[0][0] = cnt[1][0] = 1;
	while (q--)
	{
		int d, k;
		string s;
		cin >> d >> k >> s;
		d--;
		for (auto ch : s)
		{
			cnt[d][ch - 'a'] += k;
		}

		bool flag = 0;
		for (int i = 1; i < 26; i++)
		{
			if (cnt[1][i] > 0)
			{
				flag = 1;
				break;
			}
		}
		if (flag)
		{
			cout << "YES" << '\n';
			continue;
		}

		flag = 1;
		if (cnt[0][0] >= cnt[1][0])
		{
			flag = 0;
		}

		for (int i = 1; i < 26; i++)
		{
			if (cnt[0][i] > 0)
			{
				flag = 0;
				break;
			}
		}

		cout << (flag ? "YES" : "NO") << '\n';
	}
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