// 2024/06/20 20:47:55
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
	string s[8];
	for (int i = 0; i < 8; i++)
	{
		cin >> s[i];
	}

	for (int i = 0; i < 8; i++)
	{
		int cnt1 = 0;
		for (int j = 0; j < 8; j++)
		{
			if (s[i][j] == 'R')
				cnt1++;
		}
		if (cnt1 == 8)
		{
			cout << "R\n";
			return;
		}
	}

	cout << "B\n";
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