// 2023/08/15 13:05:31
// #pragma GCC optimize(2)
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;


const int INF = 0x3f3f3f3f;
const int N = 100005;

int n, m;
int arr[N], in[N];
int dis[N];
vector<int> G[N];

int dfs(int u)
{
    if (dis[u] != -INF)
    {
        return dis[u];
    }

    dis[u] = arr[u];

    int maxx = -INF;
    for (int i = 0; i < (int)G[u].size(); i++)
    {
        int v = G[u][i];
        maxx = max(maxx, dfs(v));
    }

    if (maxx != -INF)
    {
        dis[u] += maxx;
    }

    return dis[u];
}

inline int read()
{
    int f = 1, x = 0;char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-')f = -1;ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0';ch = getchar(); }
    return f * x;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n >> m)
    {
        for (int i = 0; i < n; i++)
        {
            dis[i] = -INF;
            G[i].clear();
            // arr[i] = read();
            // cin >> arr[i];
            scanf("%d", &arr[i]);
        }
        memset(in, 0, sizeof(in));

        for (int i = 0; i < m; i++)
        {
            int u, v;
            // u = read(); v = read();
            // cin >> u >> v;
            scanf("%d%d", &u, &v);
            u--; v--;
            G[u].push_back(v);
            in[v]++;
        }

        int ans = -INF;
        for (int i = 0; i < n; i++)
        {
            if (in[i] == 0)
                ans = max(ans, dfs(i));
        }

        cout << ans << '\n';
    }

#ifdef LOCAL
    cerr << clock() / 1000 << " ms" << endl;
#endif

    cout << flush;
    return 0;
}