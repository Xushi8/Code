#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

void solve()
{
	int cnt = 14;
	int now = 0;
	int val;
	while (1)
	{
		if (now == 99)
		{
			cout << "? 100" << endl;
			cin >> val;
			if (val == 1)
				cout << "! 99" << endl;
			else
				cout << "! 100" << endl;
			return;
		}
		cout << "? " << now + cnt << endl;
		cin >> val;
		if (val == 0)
		{
			now += cnt--;
		}
		else
		{
			for (int i = 1; i < cnt; i++)
			{
				cout << "? " << now + i << endl;
				cin >> val;
				if (val == 1)
				{
					cout << "! " << now + i - 1 << endl;
					return;
				}
			}

			cout << "! " << now + cnt - 1 << endl;
			return;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
}