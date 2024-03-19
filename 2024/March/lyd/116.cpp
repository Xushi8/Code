// 2024/03/19 14:39:53
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

void flip(int x, int y, array<array<bool, 4>, 4>& a)
{
	for (int i = 0; i < 4; i++)
	{
		a[x][i] = !a[x][i];
	}
	for (int i = 0; i < 4; i++)
	{
		a[i][y] = !a[i][y];
	}
	a[x][y] = !a[x][y];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	array<array<bool, 4>, 4> a;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			char ch;
			cin >> ch;
			if (ch == '+')
				a[i][j] = 0;
			else
				a[i][j] = 1;
		}
	}

	int ans = 999, ans_num = 0x7fffffff;
	for (int S = 0; S < (1 << 16); S++)
	{
		auto tmp = a;
		for (int i = 0; i < 16; i++)
		{
			if ((S >> i) & 1)
			{
				int x = i / 4, y = i % 4;
				flip(x, y, tmp);
			}
		}
		int sum = 0;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				sum += tmp[i][j];
            }
		}
		if (sum == 16)
		{
			if (__builtin_popcount(S) < ans)
			{
				ans = __builtin_popcount(S);
				ans_num = S;
			}
		}
	}

	cout << ans << '\n';
	for (int i = 0; i < 16; i++)
	{
		if ((ans_num >> i) & 1)
		{
			int x = i / 4, y = i % 4;
			cout << x + 1 << ' ' << y + 1 << '\n';
		}
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}