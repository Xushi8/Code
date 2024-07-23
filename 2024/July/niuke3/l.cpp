// 2024/07/23 12:05:31
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
	constexpr int n = 9, m = 9;
	vector<string> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == '9')
			{
				a[i][j] = '*';
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (i == 0 || i == 8)
		{
			if (a[i][0] > '3')
				a[i][0] = '*';
			if (a[i][8] > '3')
				a[i][8] = '*';
		}
		else
		{
			if (a[i][0] > '5')
				a[i][0] = '*';
			if (a[i][8] > '5')
				a[i][8] = '*';
		}
	}

	for (int j = 0; j < m; j++)
	{
		if (j == 0 || j == 8)
		{
			if (a[0][j] > '3')
				a[0][j] = '*';
			if (a[8][j] > '3')
				a[8][j] = '*';
		}
		else
		{
			if (a[0][j] > '5')
				a[0][j] = '*';
			if (a[8][j] > '5')
				a[8][j] = '*';
		}
	}

	int tx, ty;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == '8')
			{
				tx = i;
				ty = j;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i == tx && j == ty)
			{
				cout << '8';
			}
			else
			{
				cout << '*';
			}
		}
		cout << '\n';
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