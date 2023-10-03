// 2023/10/03 13:45:25
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
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 105;
constexpr int INF = 0x3f3f3f3f;

char s[N][N][N];
int dis[N][N][N];

int dx[] = { 0, 1, 0, -1, 0, 0 };
int dy[] = { 1, 0, -1, 0, 0, 0 };
int dz[] = { 0, 0, 0, 0, 1, -1 };

void solve(int n, int m, int h)
{
    memset(dis, 0x3f, sizeof(dis));
    queue<array<int, 3>> que;
    int ex, ey, ez;
    for (int k = 0; k < h; k++)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> s[k][i];
            for (int j = 0; j < m; j++)
            {
                if (s[k][i][j] == 'S')
                {
                    que.push({ k, i, j });
                    dis[k][i][j] = 0;
                }
                else if (s[k][i][j] == 'E')
                {
                    ex = i, ey = j, ez = k;
                }
            }
        }
    }

    while (!que.empty())
    {
        auto [z, x, y] = que.front(); que.pop();
        for (int i = 0; i < 4; i++)
        {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if (0 <= tx && tx < n && 0 <= ty && ty < m && s[z][tx][ty] != '#' && dis[z][tx][ty] > dis[z][x][y])
            {
                dis[z][tx][ty] = dis[z][x][y] + 1;
                que.push({ z, tx, ty });
            }
        }

        if (s[z][x][y] == '-')
        {
            for (int i = 4; i < 6; i++)
            {
                int tz = z + dz[i];
                if (0 <= tz && tz < h && s[tz][x][y] == '-' && dis[tz][x][y] > dis[z][x][y])
                {
                    dis[tz][x][y] = dis[z][x][y] + 1;
                    que.push({ tz, x, y });
                }
            }
        }
    }

    cout << (dis[ez][ex][ey] == INF ? -1 : dis[ez][ex][ey]) << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, h;
    while (cin >> n >> m >> h && (n || m || h))
    {
        solve(n, m, h);
    }


#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}