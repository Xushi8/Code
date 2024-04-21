#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int a[9][9];

bool check(int x, int y)
{
	set<int> st;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			st.emplace(a[x + i][y + j]);
		}
	}
	return st.size() == 9;
}

bool checkr(int x)
{
	set<int> st;
	for (int i = 0; i < 9; i++)
	{
		st.emplace(a[x][i]);
	}
	return st.size() == 9;
}

bool checkc(int y)
{
	set<int> st;
	for (int i = 0; i < 9; i++)
	{
		st.emplace(a[i][y]);
	}
	return st.size() == 9;
}

void solve()
{
	bool flag = 1;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> a[i][j];
			if (a[i][j] > 9 || a[i][j] < 1)
			{
				flag = 0;
			}
		}
	}

	for (int i = 0; i < 9; i += 3)
	{
		for (int j = 0; j < 9; j += 3)
		{
			if (!check(i, j))
			{
				flag = 0;
			}
		}
	}

	for (int i = 0; i < 9; i++)
	{
		if (!checkr(i) || !checkc(i))
		{
			flag = 0;
		}
	}

	cout << flag << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	while (n--)
	{
		solve();
	}

	return 0;
}
