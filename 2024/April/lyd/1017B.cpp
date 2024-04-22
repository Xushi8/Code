// 2024/04/22 18:42:36
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

	int n, m;
	cin >> n >> m;
	vector<vector<char>> a(n, vector<char>(m));
	constexpr int INF = 0x3f3f3f3f;
	vector<vector<int>> dis(n, vector<int>(m, INF));
	queue<pii> que;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == '1')
			{
				que.emplace(i, j);
				dis[i][j] = 0;
            }
        }
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
			if (0 <= tx && tx < n && 0 <= ty && ty < m)
			{
				if (dis[tx][ty] > dis[x][y] + 1)
				{
					dis[tx][ty] = dis[x][y] + 1;
					que.emplace(tx, ty);
                }
            }
        }
    }

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << dis[i][j] << ' ';
		}
		cout << '\n';
    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}