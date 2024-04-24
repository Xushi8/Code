// 2024/04/23 21:30:17
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
constexpr int INF = 0x3f3f3f3f;

int solve()
{
	int n, m;
	cin >> n >> m;
	int dx[] = {-1, -1, 1, 1};
	int dy[] = {-1, 1, -1, 1};
	int ix[] = {-1, -1, 0, 0};
	int iy[] = {-1, 0, -1, 0};
	vector<vector<char>> a(n, vector<char>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
        }
	}

	vector<vector<int>> dis(n + 1, vector<int>(m + 1, INF));
	char no_cost[] = {'\\', '/', '/', '\\'};
	deque<pii> que;
	que.emplace_front(0, 0);
	dis[0][0] = 0;
	while (!que.empty())
	{
		auto [x, y] = que.front();
		que.pop_front();
		for (int i = 0; i < 4; i++)
		{
			int tx = x + dx[i];
			int ty = y + dy[i];
			if (0 <= tx && tx <= n && 0 <= ty && ty <= m)
			{
				int nx = x + ix[i];
				int ny = y + iy[i];
				int w = (a[nx][ny] == no_cost[i] ? 0 : 1);
				if (dis[tx][ty] > dis[x][y] + w)
				{
					dis[tx][ty] = dis[x][y] + w;
					if (w == 0)
						que.emplace_front(tx, ty);
					else
						que.emplace_back(tx, ty);
                }
            }
        }
	}

	// for (int i = 0; i <= n; i++)
	// {
	// 	for (int j = 0; j <= m; j++)
	// 	{
	// 		cout << dis[i][j] << " \n"[j == m];
    //     }
    // }

	return dis[n][m];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt;
	cin >> tt;
	while (tt--)
	{
		int ret = solve();
		if (ret == INF)
			cout << "NO SOLUTION";
		else
			cout << ret;
		cout << '\n';
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}