#include<bits/stdc++.h>
using namespace std;
int n, m;


string str[25];
string dst[1000005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		getline(cin, str[i]);
	}
	for (int i = 0; i < m; i++)
	{
		getline(cin, dst[i]);
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (str[i] == dst[j])
			{
				ans++;
				break;
			}
		}
	}
	cout << ans << endl;
	
	system("pause");
	return 0;
}
