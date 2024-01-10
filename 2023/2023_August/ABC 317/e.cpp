// 2023/08/31 21:00:10
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
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
constexpr int N = 2005;

bool vis[N][N];
int dis[N][N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    queue<pii> que;
    memset(dis, 0x3f, sizeof(dis));
    int endx, endy;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == '<')
            {
                vis[i][j] = 1;
                for (int k = j - 1; k >= 0; k--)
                {
                    if (s[i][k] == '.')
                        vis[i][k] = 1;
                    else
                        break;
                }
            }
            else if (s[i][j] == '>')
            {
                vis[i][j] = 1;
                for (int k = j + 1; k < m; k++)
                {
                    if (s[i][k] == '.')
                        vis[i][k] = 1;
                    else
                        break;
                }
            }
            else if (s[i][j] == '^')
            {
                vis[i][j] = 1;
                for (int k = i - 1; k >= 0; k--)
                {
                    if (s[k][j] == '.')
                        vis[k][j] = 1;
                    else
                        break;
                }
            }
            else if(s[i][j] == 'v')
            {
                vis[i][j] = 1;
                for (int k = i + 1; k < n; k++)
                {
                    if (s[k][j] == '.')
                        vis[k][j] = 1;
                    else
                        break;
                }
            }
            else if (s[i][j] == 'S')
            {
                dis[i][j] = 0;
                que.emplace(i, j);
            }
            else if (s[i][j] == 'G')
            {
                endx = i, endy = j;
            }
            else if (s[i][j] == '#')
            {
                vis[i][j] = 1;
            }
        }
    }

    int dx[] = { 0, 1, 0, -1 }, dy[] = { 1, 0, -1, 0 };
    while (!que.empty())
    {
        auto [x, y] = que.front(); que.pop();
        vis[x][y] = 1;
        for (int i = 0; i < 4; i++)
        {
            int tx = x + dx[i], ty = y + dy[i];
            if (0 <= tx && tx < n && 0 <= ty && ty < m && !vis[tx][ty])
            {
                vis[tx][ty] = 1;
                que.emplace(tx, ty);
                dis[tx][ty] = dis[x][y] + 1;
                if (tx == endx && ty == endy)
                    break;
            }
        }
    }

    cout << (dis[endx][endy] == 0x3f3f3f3f ? -1 : dis[endx][endy]) << '\n';

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}