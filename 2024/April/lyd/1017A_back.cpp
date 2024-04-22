// 2024/04/22 18:30:42
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

	constexpr int dx[3][4] = {
		{0, 0, -2, 1},
		{0, 0, -1, 1},
		{0, 0, -1, 2},
	};
	constexpr int dy[3][4] = {
		{-2, 1, 0, 0},
		{-1, 2, 0, 0},
		{-1, 1, 0, 0},
	};
	constexpr int dz[3][4] = {
		{1, 1, 2, 2},
		{0, 0, 1, 1},
		{2, 2, 0, 0},
	};

	int n, m;
	while (cin >> n >> m && (n || m))
	{
		vector<vector<char>> a(n, vector<char>(m));
		constexpr int INF = 0x3f3f3f3f;
		vector<vector<array<int, 3>>> dis(n, vector<array<int, 3>>(m, {INF, INF, INF}));
		queue<array<int, 3>> que;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> a[i][j];
				if (a[i][j] == 'X')
				{
					que.push({i, j, 0});
					dis[i][j][0] = 0;
				}
			}
		}

		auto valid = [&](int x, int y, int z) -> bool
		{
			if (z == 0)
			{
				if (!(0 <= x && x < n && 0 <= y && y < m))
					return false;
				return a[x][y] == '.' || a[x][y] == 'O';
			}
			else if (z == 1)
			{
				if (!(0 <= x && x < n && 0 <= y && y < m && 0 <= y + 1 && y + 1 < m))
					return false;
				return a[x][y] != '#' && a[x][y + 1] != '#';
			}
			else
			{
				if (!(0 <= x && x < n && 0 <= y && y < m && 0 <= x + 1 && x + 1 < n))
					return false;
				return a[x][y] != '#' && a[x + 1][y] != '#';
			}
		};

		int ans = INF;
		while (!que.empty())
		{
			auto [x, y, z] = que.front();
			que.pop();
			for (int i = 0; i < 4; i++)
			{
				int tx = x + dx[z][i];
				int ty = y + dy[z][i];
				int tz = dz[z][i];
				if (!valid(tx, ty, tz))
					continue;
				if (dis[tx][ty][tz] > dis[x][y][z] + 1)
				{
					dis[tx][ty][tz] = dis[x][y][z] + 1;
					que.push({tx, ty, tz});
					if (tz == 0 && a[tx][ty] == 'O')
					{
						ans = min(ans, dis[tx][ty][tz]);
					}
				}
			}
		}

		if (ans == INF)
			cout << "Impossible" << '\n';
		else
			cout << ans << '\n';
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}