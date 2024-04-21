#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	queue<pii> que;
	vector<vector<int>> a(n, vector<int>(m));
	constexpr int INF = 0x3f3f3f3f;
	vector<vector<int>> dis(n, vector<int>(m, INF));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 2)
			{
				que.emplace(i, j);
				dis[i][j] = 0;
			}
		}
	}

	int q;
	cin >> q;
	vector<array<int, 3>> teams;
	for (int i = 0; i < q; i++)
	{
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		swap(x, y);
		if (x < 0 || x >= n || y < 0 || y >= m)
			continue;
		teams.push_back({x, y, i});
	}

	int dx[] = {0, 0, -1, 1};
	int dy[] = {-1, 1, 0, 0};

	while (!que.empty())
	{
		auto [x, y] = que.front();
		que.pop();
		for (int i = 0; i < 4; i++)
		{
			int tx = x + dx[i];
			int ty = y + dy[i];
			if (0 <= tx && tx < n && 0 <= ty && ty < m && a[tx][ty] != 0)
			{
				if (dis[tx][ty] == INF)
				{
					dis[tx][ty] = dis[x][y] + 1;
					que.emplace(tx, ty);
				}
			}
		}
	}

	// for (auto x : dis)
	// {
	// 	for (auto y : x)
	// 	{
	// 		cout << y << ' ';
	// 	}
	// 	cout << '\n';
	// }

	map<int, vector<array<int, 3>>> mp;
	for (auto [x, y, id] : teams)
	{
		if (dis[x][y] != INF)
			mp[dis[x][y]].push_back({x, y, id});
	}

	bool flag = 0;
	for (auto const& [x, y] : mp)
	{
		if (y.size() == 1)
		{
			flag = 1;
			cout << y[0][2] + 1 << ' ' << dis[y[0][0]][y[0][1]] << '\n';
			break;
		}
	}

	if (!flag)
	{
		cout << "No winner." << endl;
	}

	return 0;
}
