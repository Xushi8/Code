// 2024/03/23 19:09:33
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

using vector2d = vector<vector<int>>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int x, y;
	cin >> x >> y;
	vector2d a(x, vector<int>(y));
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cin >> a[i][j];
		}
	}

	cin >> x >> y;
	vector2d b(x, vector<int>(y));
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cin >> b[i][j];
		}
	}

	if (a[0].size() != b.size())
	{
		cout << "Error: " << a[0].size() << " != " << b.size() << '\n';
	}
	else
	{
		vector2d c(a.size(), vector<int>(b[0].size(), 0));
		for (int i = 0; i < a.size(); i++)
		{
			for (int j = 0; j < b[0].size(); j++)
			{
				for (int k = 0; k < a[0].size(); k++)
				{
					c[i][j] += a[i][k] * b[k][j];
				}
			}
		}
		cout << c.size() << ' ' << c[0].size() << '\n';

		for (int i = 0; i < c.size(); i++)
		{
			for (int j = 0; j < c[i].size(); j++)
			{
				if (j != 0)
					cout << ' ';
				cout << c[i][j];
			}
			cout << '\n';
		}
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}