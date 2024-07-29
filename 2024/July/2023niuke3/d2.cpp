#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2010;
const int inf = 0x3f3f3f3f3f3f3f3f;
int n;
int a[N][N];
int op(int f, int num)
{
	int cnt = 0;
	int b[N][N];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			b[i][j] = a[i][j];
	}
	if (f == 1)
	{
		cnt++;
		for (int i = 1; i <= n; i++)
			b[i][1] ^= 1;
	}
	for (int i = 1; i <= n; i++)
	{
		if (b[i][1] != num)
		{
			cnt++;
			for (int j = 1; j <= n; j++)
				b[i][j] ^= 1;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (b[1][i] != num)
		{
			cnt++;
			for (int j = 1; j <= n; j++)
				b[j][i] ^= 1;
		}
	}
	int flag = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			if (b[i][j] != num) flag = 0;
	}
	if (flag == 0)
		return inf;
	else
		return cnt;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int ans = inf;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			char x;
			cin >> x;
			a[i][j] = x - '0';
		}
	}
	ans = min(ans, op(0, 0));
	ans = min(ans, op(1, 0));
	ans = min(ans, op(0, 1));
	ans = min(ans, op(1, 1));
	if (ans == inf)
		cout << -1 << '\n';
	else
		cout << ans << '\n';
	return 0;
}
