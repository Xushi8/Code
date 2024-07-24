// 2024/07/24 17:32:38
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
	s = ' ' + s;
	vector<vector<int>> nex(s.size() + 1, vector<int>(26));
	for (int i = int(s.size()) - 1; i >= 1; i--)
	{
		nex[i - 1] = nex[i];
		nex[i - 1][s[i] - 'a'] = i;
	}
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string t;
		cin >> t;
		bool ok = true;
		int now = 0;
		for (auto ch : t)
		{
			if (nex[now][ch - 'a'] != 0)
			{
				now = nex[now][ch - 'a'];
			}
			else
			{
				ok = false;
				break;
			}
		}
		cout << (ok ? "Yes" : "No") << '\n';
	}
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