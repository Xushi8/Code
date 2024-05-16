// 2024/05/16 10:24:35
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
constexpr int N = 400;

bool vis[N][3][3][7][7][7][7];

constexpr int dx[5] = {0, 0, -1, 1, 0};
constexpr int dy[5] = {-1, 1, 0, 0, 0};

int solve(int n)
{
	vector<array<array<int, 4>, 4>> a(n + 1);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				cin >> a[i][j][k];
			}
		}
	}

	if (a[1][1][1] || a[1][1][2] || a[1][2][1] || a[1][2][2])
		return 0;
	memset(vis, 0, sizeof(vis));
	queue<array<int, 7>> que;
	que.push({1, 1, 1, 1, 1, 1, 1});
	vis[1][1][1][1][1][1][1] = 1;

	while (!que.empty())
	{
		auto [day, x, y, s0, s1, s2, s3] = que.front();
		que.pop();
		if (day == n)
			return 1;

		for (int k = 0; k < 5; k++)
		{
			for (int step = 1; step <= 2; step++)
			{
				int tx = x + dx[k] * step;
				int ty = y + dy[k] * step;
				if (!(0 <= tx && tx < 3 && 0 <= ty && ty < 3))
					continue;

				if (a[day + 1][x][y] || a[day + 1][x + 1][y] || a[day + 1][x][y + 1] || a[day + 1][x + 1][y + 1])
					continue;

				if (x == 0 && y == 0)
					s0 = 0;
				else if (++s0 == 7)
					continue;
				else if (x == 0 && y == 2)
					s1 = 0;
				else if (++s1 == 7)
					continue;
				else if (x == 2 && y == 0)
					s2 = 0;
				else if (++s2 == 7)
					continue;
				else if (x == 2 && y == 2)
					s3 = 0;
				else if (++s3 == 7)
					continue;

				if (vis[day + 1][tx][ty][s0][s1][s2][s3])
					continue;
				vis[day + 1][tx][ty][s0][s1][s2][s3] = 1;
				que.push({day + 1, tx, ty, s0, s1, s2, s3});
			}
		}
	}

	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	while (cin >> n && n)
	{
		cout << solve(n) << '\n';
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}