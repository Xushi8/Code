// 2024/05/15 22:09:28
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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	int bx, by;
	cin >> m >> n >> by >> bx;
	bx = n - bx;
	by--;
	vector<string> a(n);
	for (auto& s : a)
		cin >> s;

	queue<pii> que;
	que.emplace(bx, by);
	constexpr int dx[8] = {0, 0, -1, -1, 1, 1, -1, 1};
	constexpr int dy[8] = {-1, 1, -1, 1, -1, 1, 0, 0};
	constexpr int INF = 0x3f3f3f3f;
	vector<vector<int>> dis(n, vector<int>(m, INF));
	dis[bx][by] = 0;
	while (!que.empty())
	{
		auto [x, y] = que.front();
		que.pop();
		for (int k = 0; k < 8; k++)
		{
			int tx = x + dx[k];
			int ty = y + dy[k];
			if (0 <= tx && tx < n && 0 <= ty && ty < m && a[tx][ty] != '*')
			{
				if (dis[tx][ty] > dis[x][y] + 1)
				{
					dis[tx][ty] = dis[x][y] + 1;
					que.emplace(tx, ty);
				}
			}
		}
	}

	int maxx = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] != '*')
				maxx = max(maxx, dis[i][j]);
		}
	}

	cout << maxx << endl;

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}