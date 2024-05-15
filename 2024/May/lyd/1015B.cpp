// 2024/05/15 16:19:48
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

using i64 = int64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 1000005;
int minn[100];
int n, m;

constexpr int INF = 0x3f3f3f3f;
int ans = INF;

void dfs(int h, int s, int v, int last_r, int last_h)
{
	if (h == 0)
	{
		if (v == n)
		{
			ans = min(ans, s);
		}
		return;
	}

	if (v + minn[h] > n)
		return;
	if (s + (n - v) * 2 / last_r >= ans)
		return;

	for (int i = last_r - 1; i >= h; i--)
	{
		for (int j = last_h - 1; j >= h; j--)
		{
			if (h == m)
			{
				dfs(h - 1, s + 2 * i * j + i * i , v + i * i * j, i, j);
			}
			else
			{
				dfs(h - 1, s + 2 * i * j, v + i * i * j, i, j);
			}
        }
    }
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= 15; i++)
	{
		minn[i] = minn[i - 1] + i * i * i;
	}

	dfs(m, 0, 0, sqrt(n) + 1, n + 1);

	cout << (ans == INF ? -1 : ans) << endl;

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}