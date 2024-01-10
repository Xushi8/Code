// 2023/09/17 22:08:30
#ifndef LOCAL
#pragma GCC optimize(2)
#endif
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <iomanip>
#include <stack>
using namespace std;

inline int read()
{
    int x = 0, f = 1;
    int ch = getchar();
    while (ch < '0' || ch>'9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        x = x * 10 + ch - '0', ch = getchar();
    return x * f;
}

typedef long long ll;
typedef pair<int, int> pii;
const int N = 1000005;

class point
{
public:
    point(int a, int b, int c)
    {
        x = a; y = b; tim = c;
    }
    point() {}

    int x, y, tim;
};

bool cmp(const point& a, const point& b)
{
    return a.tim > b.tim;
}

int arr[305][305];

bool vis[305][305];

int dis[305][305];

int bfs()
{
    if (arr[0][0] == 0)
        return -1;
    
    queue<pii> que;
    que.push({ 0, 0 });
    vis[0][0] = 1;
    int dx[] = { 0, 1, 0, -1 };
    int dy[] = { 1, 0, -1, 0 };
    while (!que.empty())
    {
        pii p = que.front(); que.pop();
        int x = p.first, y = p.second;
        if (arr[x][y] == 0x3f3f3f3f)
            return dis[x][y];

        for (int i = 0; i < 4; i++)
        {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if (tx >= 0 && ty >= 0 && !vis[tx][ty] && arr[tx][ty] > dis[x][y] + 1)
            {
                que.push({ tx, ty });
                vis[tx][ty] = 1;
                dis[tx][ty] = dis[x][y] + 1;
            }
        }

    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<point> points;
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        points.push_back({ a, b, c });
    }

    sort(points.begin(), points.end(), cmp);

    memset(arr, 0x3f, sizeof(arr));
    int dx[] = { 0, 1, 0, -1 };
    int dy[] = { 1, 0, -1, 0 };
    for (int i = 0; i < n; i++)
    {
        arr[points[i].x][points[i].y] = points[i].tim;
        for (int j = 0; j < 4; j++)
        {
            int tx = points[i].x + dx[j];
            int ty = points[i].y + dy[j];
            if (tx >= 0 && ty >= 0)
            {
                arr[tx][ty] = points[i].tim;
            }
        }
    }

    // for (int i = 0; i < 6; i++)
    // {
    //     for (int j = 0; j < 6; j++)
    //     {
    //         cerr << arr[i][j] << " \n"[j == 5];
    //     }
    // }

    cout << bfs() << '\n';

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}