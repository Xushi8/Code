// 2023/08/17 09:14:47
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <cstdint>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const int N = 10005;

bool vis[N];
int dfn[N], low[N], c[N], w[N], ans[N];
int dis[N];
vector<int> scc[N], G[N], G1[N];
stack<int> stk;
int tim, tot;

void tarjan(int u)
{
    stk.emplace(u);
    vis[u] = 1;
    dfn[u] = low[u] = ++tim;
    for (int v : G[u])
    {
        if (dfn[v] == 0)
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if(vis[v])
        {
            low[u] = min(low[u], dfn[v]);
        }
    }

    if (low[u] == dfn[u])
    {
        int v;
        do
        {
            v = stk.top(); stk.pop();
            vis[v] = 0;
            c[v] = tot;
            scc[tot].emplace_back(v);
            ans[tot] += w[v];
        } while (u != v);
        tot++;
    }
}

int func(int s)
{
    memset(dis, -0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    int res = 0;
    queue<int> que;
    vis[s] = 1;
    dis[s] = 0;
    que.emplace(s);
    while (!que.empty())
    {
        int u = que.front(); que.pop();
        vis[u] = 0;
        res = max(res, dis[u] + ans[u]);
        for (int v : G1[u])
        {
            if (dis[v] < dis[u] + ans[u])
                dis[v] = dis[u] + ans[u];
            if (vis[v])
                continue;
            que.emplace(v);
            vis[v] = 1;
        }
    }

    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].emplace_back(v);
    }

    for (int i = 0; i < n; i++)
    {
        if (dfn[i] == 0)
        {
            tarjan(i);
        }
    }

    for (int u = 0; u < n; u++)
    {
        for (int v : G[u])
        {
            if (c[u] != c[v])
            {
                G1[c[u]].emplace_back(c[v]);
            }
        }
    }

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res = max(res, func(i));
    }

    cout << res << '\n';

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}