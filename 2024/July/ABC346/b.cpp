// 2024/07/24 22:13:54
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
	string s = "wbwbwwbwbwbw";
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < s.size(); i++)
	{
		int c[2] = {};
		for (int j = i; c[0] <= n && c[1] <= m; j = (j + 1) % s.size())
		{
			if (s[j] == 'w')
				c[0]++;
			else
				c[1]++;
			if (c[0] == n && c[1] == m)
			{
				cout << "Yes\n";
				return;
            }
        }
    }

	cout << "No\n";
}