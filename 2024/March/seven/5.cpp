// 2024/04/10 13:04:38
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

void print(array<int, 6> a)
{
	for (int i = 0; i < 6; i++)
	{
		if (i != 0)
			cout << ' ';
		cout << a[i] + 1;
	}
	cout << '\n';
}

bool vis[6][6];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	array<int, 6> a;
	for (int i = 0; i < 6; i++)
	{
		cin >> a[i];
		a[i]--;
		vis[i][a[i]] = 1;
	}
	int cnt;
	cin >> cnt;
	for (int i = 0; i < cnt; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			for (int k = 5; k >= 0; k--)
			{
				if (!vis[j][k])
				{
					vis[j][k] = 1;
					a[j] = k;
					break;
				}
			}
		}
		// print(a);
	}

	print(a);

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}