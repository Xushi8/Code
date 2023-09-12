// 2023/09/12 19:29:27
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
const int N = 25;

int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

int a[N][N];
int dis[N][N];
bool vis[N][N];

int solve(int m, int n)
{
    memset(dis, 0, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    int bx, by, ex, ey;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 2)
            {
                bx = i;
                by = j;
            }
            if (a[i][j] == 3)
            {
                ex = i;
                ey = j;
            }
        }
    }
    queue<pii> que;
    que.push({ bx, by });
    vis[bx][by] = 1;
    

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    while (cin >> n >> m && (n || m))
    {
        cout << solve(n, m) << '\n';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}