// 2023/09/12 19:06:11
#ifndef LOCAL
#pragma GCC optimize(2)
#endif
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
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

bool vis[N][N];
char s[N][N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    while (cin >> m >> n && (n != 0 || m != 0))
    {
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
        }

        int bx, by;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (s[i][j] == '@')
                {
                    bx = i;
                    by = j;
                }
            }
        }

        int dx[] = { 0,1,0,-1 };
        int dy[] = { 1,0,-1,0 };
        queue<pii> que;
        que.push({ bx, by });
        vis[bx][by] = 1;
        while (!que.empty())
        {
            pii p = que.front(); que.pop();
            int x = p.first, y = p.second;
            for (int i = 0; i < 4; i++)
            {
                int tx = x + dx[i];
                int ty = y + dy[i];
                if (0 <= tx && tx < n && 0 <= ty && ty < m && s[tx][ty] == '.' && !vis[tx][ty])
                {
                    que.push({ tx, ty });
                    vis[tx][ty] = 1;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ans += vis[i][j];
            }
        }
        cout << ans << '\n';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}