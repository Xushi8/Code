// 2024/05/13 20:56:09
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
constexpr int N = 1000005;

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	for (auto& x : a)
		cin >> x;

	queue<pii> q1, q2;
	pii z1{-1, -1}, z2{-1, -1};
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == 'M')
			{
				q1.emplace(i, j);
			}
			else if (a[i][j] == 'G')
			{
				q2.emplace(i, j);
			}
			else if (a[i][j] == 'Z')
			{
				if (z1.first == -1)
				{
					z1 = {i, j};
				}
				else
				{
					z2 = {i, j};
				}
			}
		}
	}

	vector<vector<int>> vis(n, vector<int>(m));
	vis[q1.front().first][q1.front().second] = 1;
	vis[q2.front().first][q2.front().second] = 2;
	int tim = 0;
	constexpr int dx[4] = {0, 0, -1, 1};
	constexpr int dy[4] = {-1, 1, 0, 0};

	auto valid = [&](int x, int y)
	{
		if (!(0 <= x && x < n && 0 <= y && y < m && a[x][y] != 'X'))
			return 0;
		int d1 = abs(x - z1.first) + abs(y - z1.second);
		int d2 = abs(x - z2.first) + abs(y - z2.second);
		if (d1 <= tim * 2 || d2 <= tim * 2)
			return 0;
		return 1;
    };
	while (!q1.empty() && !q2.empty())
	{
		tim++;

		for (int t = 0, cnt = q2.size(); t < cnt; t++)
		{
			auto [x, y] = q2.front();
			q2.pop();
			if (!valid(x, y))
				continue;
			for (int k = 0; k < 4; k++)
			{
				int tx = x + dx[k];
				int ty = y + dy[k];
				if (valid(tx, ty) && vis[tx][ty] != vis[x][y])
				{
					if (vis[tx][ty] + vis[x][y] == 3)
					{
						cout << tim << '\n';
						return;
					}
					q2.emplace(tx, ty);
					vis[tx][ty] = vis[x][y];
                }
            }
		}

		for (int ttt = 0; ttt < 3; ttt++)
		{
			for (int t = 0, cnt = q1.size(); t < cnt; t++)
			{
				auto [x, y] = q1.front();
				q1.pop();
				if (!valid(x, y))
					continue;
				for (int k = 0; k < 4; k++)
				{
					int tx = x + dx[k];
					int ty = y + dy[k];
					if (valid(tx, ty) && vis[tx][ty] != vis[x][y])
					{
						if (vis[tx][ty] + vis[x][y] == 3)
						{
							cout << tim << '\n';
							return;
						}
						q1.emplace(tx, ty);
						vis[tx][ty] = vis[x][y];
					}
				}
			}
        }
	}

	cout << "-1\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt;
	cin >> tt;
	while (tt--)
	{
		solve();
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}