// 2024/06/21 23:21:56
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
	if (n < 8)
	{
		cout << "-1\n";
	}
	else
	{
		for (int i = 5; i <= n; i++)
		{
			cout << i  << ' ';
		}
		if (n % 2 == 1)
		{
			cout << "2 1 4 3\n";
		}
		else
		{
			cout << "1 2 3 4\n";
        }
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