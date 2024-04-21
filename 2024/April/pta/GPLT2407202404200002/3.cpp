#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b;
	cin >> a >> b;
	if (a == 2)
	{
		cout << '-' << '\n';
		cout << "stop\n";
	}
	else
	{
		if (a == 0)
		{
			if (b == 1)
			{
				cout << "-\n";
			}
			else
			{
				cout << "biii\n";
			}
			cout << "stop\n";
		}
		else
		{
			if (b == 1)
			{
				cout << "-\n";
			}
			else
			{
				cout << "dudu\n";
			}
			cout << "move\n";
		}
	}

	return 0;
}
