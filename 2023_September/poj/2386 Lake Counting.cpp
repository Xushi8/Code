// 2023/09/12 18:57:41
#ifndef LOCAL
#pragma GCC optimize(2)
#endif
#include <iostream>
#include <cstdio>
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

int dx[8] = { -1,-1,-1,0,1,1,1,0 };
int dy[8] = { -1,0,1,1,1,0,-1,-1 };
int n, m;
vector<string> a(105);

void dfs(int x, int y)
{
    for (int i = 0; i < 8; i++)
    {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (0 <= tx && tx < n && 0 <= ty && ty < m)
        {
            if (a[tx][ty] == 'W')
            {
                a[tx][ty] = '.';
                dfs(tx, ty);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int ans = 0;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 'W')
            {
                ans++;
                a[i][j] = '.';
                dfs(i, j);
            }
        }
    }

    cout << ans << '\n';

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}