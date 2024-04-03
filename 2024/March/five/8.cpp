// 2024/04/03 18:58:01
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdint>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <functional>
#include <iomanip>
#include <cmath>
#include <stack>
#include <array>
#include <fstream>
#include <bitset>
#include <numeric>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
constexpr int N = 1000005;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a[3][3];
	bool vis[3][3] = {false};
	int bx, by;
	set<int> st;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 0)
			{
				vis[i][j] = 1;
				bx = i;
				by = j;
			}
			else
			{
				st.emplace(a[i][j]);
			}
		}
	}

	for (int i = 1; i <= 9; i++)
	{
		if (!st.count(i))
		{
			a[bx][by] = i;
			break;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		vis[x][y] = 1;
		cout << a[x][y] << '\n';
	}

	int t;
	cin >> t;
	int ans = 0;
	if (t <= 3)
	{
		for (int i = 0; i < 3; i++)
		{
			vis[t - 1][i] = 1;
			ans += a[t - 1][i];
		}
	}
	else if (t <= 6)
	{
		for (int i = 0; i < 3; i++)
		{
			vis[i][t - 4] = 1;
			ans += vis[i][t - 4];
        }
	}
	else
	{
		if (t == 7)
		{
			for (int i = 0, j = 0; i < 3; i++, j++)
			{
				vis[i][j] = 1;
				ans += a[i][j];
            }
		}
		else
		{
			for (int i = 0, j = 2; i < 3; i++, j--)
			{
				vis[i][j] = 1;
				ans += a[i][j];
            }
        }
	}


	map<int, int> mp = {
		{6, 10000}, {7, 36}, {8, 720}, {9, 360}, {10, 80}, {11, 252}, {12, 108}, {13, 72}, {14, 54}, {15, 180}, {16, 72}, {17, 180}, {18, 119}, {19, 36}, {20, 306}, {21, 1080}, {22, 144}, {23, 1800}, {24, 3600}};

	cout << mp[ans] << endl;

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}