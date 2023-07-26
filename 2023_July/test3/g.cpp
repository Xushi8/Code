// 2023/07/26 19:51:34
#pragma GCC optimize(2)
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
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const int N = 1005;

struct Point
{
    int x, y, dis;
    Point() {}
    Point(int x_, int y_, int dis_)
    {
        x = x_;
        y = y_;
        dis = dis_;
    }
};

bool vis[N][N];

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            vis[i][j] = 0;

    vector<string> s(n);
    vector<vector<int>> arr(n, vector<int>(m, INF));
    for (int i = 0; i < n; i++)
        cin >> s[i];

    int bx, by;
    vector<pii> fire;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == 'J')
                bx = i, by = j;
            if (s[i][j] == 'F')
                fire.emplace_back(i, j);
        }

    int dx[] = { 0, 1, 0, -1 };
    int dy[] = { 1, 0, -1, 0 };
    queue<Point> que;
    for (size_t i = 0; i < fire.size(); i++)
    {
        que.emplace(fire[i].first, fire[i].second, 0);
        arr[fire[i].first][fire[i].second] = 0;
    }

    while (!que.empty())
    {
        Point p = que.front(); que.pop();
        for (int i = 0; i < 4; i++)
        {
            int tx = p.x + dx[i];
            int ty = p.y + dy[i];
            if (0 <= tx && tx < n && 0 <= ty && ty < m)
            {

                if (s[tx][ty] == '#')
                    continue;

                if (p.dis + 1 < arr[tx][ty])
                {
                    que.emplace(tx, ty, p.dis + 1);
                    arr[tx][ty] = p.dis + 1;
                }
            }
        }
    }

    que.emplace(bx, by, 0);
    while (!que.empty())
    {
        Point p = que.front(); que.pop();
        for (int i = 0; i < 4; i++)
        {
            int tx = p.x + dx[i];
            int ty = p.y + dy[i];
            if (0 <= tx && tx < n && 0 <= ty && ty < m)
            {
                if (vis[tx][ty])
                    continue;

                if (s[tx][ty] == '#')
                    continue;

                if (arr[tx][ty] != -1 && arr[tx][ty] <= p.dis + 1)
                    continue;

                que.emplace(tx, ty, p.dis + 1);
                vis[tx][ty] = 1;
            }
            else
            {
                cout << p.dis + 1 << '\n';
                return;
            }
        }
    }

    cout << "IMPOSSIBLE\n";
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

    cout << flush;
    return 0;
}