// 2024/07/15 21:06:23
#ifdef LOCAL
#include <basic_std_lib.h>
#else
#include <bits/stdc++.h>
#endif
using namespace std;

using i64 = int64_t;
using u64 = uint64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 1000005;

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<vector<char>> a(n, vector<char>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}

	int b1, e1, b2, e2;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == 'C')
				b1 = i, e1 = j;
			else if (a[i][j] == 'D')
				b2 = i, e2 = j;
		}
	}

	queue<pii> q1, q2;
	q1.emplace(b1, e1);
	q2.emplace(b2, e2);
	constexpr int INF = 0x3f3f3f3f;
	vector<vector<int>> dis(n, vector<int>(m, INF)), vis(n, vector<int>(m));
	dis[b1][e1] = 0;
	dis[b2][e2] = 0;
	constexpr int dx1[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dx2[8] = {-1, -2, -1, 0, 0, 1, 2, 1};
	constexpr int dy1[8] = {-1, 0, 1, -1, 1, -1, 0, 1}, dy2[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
	while (!q1.empty() || !q2.empty())
	{
		if (!q1.empty())
		{
			auto [x, y] = q1.front();
			q1.pop();
			for (int k = 0; k < 8; k++)
			{
				int tx = x + dx1[k];
				int ty = y + dy1[k];
				if (!(0 <= tx && tx < n && 0 <= ty && ty < m && a[tx][ty] != '#'))
				{
					continue;
				}
				if (!vis[tx][ty])
				{
					vis[tx][ty] = 1;
					dis[tx][ty] = dis[x][y] + 1;
					q1.emplace(tx,ty);
				}
				else if (vis[tx][ty] == 2)
				{
                    cout << "YES\n";
					cout << max(dis[tx][ty], dis[x][y] + 1);
					return;
                }
            }
		}

		if (!q2.empty())
		{
			auto [x, y] = q2.front();
			q2.pop();
			for (int k = 0; k < 8; k++)
			{
				int tx = x + dx2[k];
				int ty = y + dy2[k];
				if (!(0 <= tx && tx < n && 0 <= ty && ty < m && a[tx][ty] != '#'))
				{
					continue;
				}
				if (!vis[tx][ty])
				{
					vis[tx][ty] = 1;
					dis[tx][ty] = dis[x][y] + 1;
					q2.emplace(tx, ty);
				}
				else if (vis[tx][ty] == 1)
				{
                    cout << "YES\n";
					cout << max(dis[tx][ty], dis[x][y] + 1);
					return;
				}
			}
		}
	}

	cout << "NO\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt;
	tt = 1;
	while (tt--)
	{
		solve();
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}