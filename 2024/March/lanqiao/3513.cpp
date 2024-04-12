// 2024/04/12 13:42:00
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

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int d8x[] = {0, 0, -1, -1, 1, 1, -1, 1};
int d8y[] = {-1, 1, -1, 1, -1, 1, 0, 0};

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n + 2, vector<int>(m + 2));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			char ch;
			cin >> ch;
			a[i][j] = ch - '0';
		}
	}

	auto bfs = [&](int bx, int by, int tar)
	{
		a[bx][by] = tar;
		queue<pii> que;
		que.emplace(bx, by);
		while (!que.empty())
		{
			auto [x, y] = que.front();
			que.pop();
			for (int i = 0; i < 4; i++)
			{
				int tx = x + dx[i];
				int ty = y + dy[i];
				if (1 <= tx && tx <= n && 1 <= ty && ty <= m && a[tx][ty] == 1)
				{
					a[tx][ty] = tar;
					que.emplace(tx, ty);
				}
			}
		}
	};

	int tot = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (a[i][j] == 1)
			{
				tot++;
				bfs(i, j, tot);
			}
		}
	}

	set<int> st;
	vector<vector<int>> vis(n + 2, vector<int>(m + 2, 0));
	queue<pii> que;
	for (int j = 0; j < m + 2; j++)
	{
		vis[0][j] = vis[n + 1][j] = 1;
		que.emplace(0, j);
		que.emplace(n + 1, j);
	}
	for (int i = 0; i < n + 2; i++)
	{
		vis[i][0] = vis[i][m + 1] = 1;
		que.emplace(i, 0);
		que.emplace(i, m + 1);
	}

	while (!que.empty())
	{
		auto [x, y] = que.front();
		que.pop();
		for (int i = 0; i < 8; i++)
		{
			int tx = x + d8x[i];
			int ty = y + d8y[i];
			if (1 <= tx && tx <= n && 1 <= ty && ty <= m)
			{
				if (vis[tx][ty] == 0)
				{
					vis[tx][ty] = 1;
					if (a[tx][ty] == 0)
						que.emplace(tx, ty);
					else
						st.emplace(a[tx][ty]);
				}
			}
		}
	}

	cout << st.size() << '\n';
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