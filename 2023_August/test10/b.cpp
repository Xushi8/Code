// 2023/08/17 17:07:44
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
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const int N = 100005;

int tim, tot, out[N], dfn[N], low[N], c[N], sum[N];
bool vis[N];
stack<int> stk;
vector<int> G[N];

void tarjan(int u)
{
    stk.emplace(u);
    vis[u] = 1;
    low[u] = dfn[u] = ++tim;
    for (int v : G[u])
    {
        if (dfn[v] == 0)
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (vis[v])
        {
            low[u] = min(low[u], dfn[v]);
        }
    }

    if (dfn[u] == low[u])
    {
        int v;
        do
        {
            v = stk.top(); stk.pop();
            vis[v] = 0;
            c[v] = tot;
            sum[tot]++;
        } while (u != v);
        tot++;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
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
                out[c[u]]++;
            }
        }
    }

    int index = -1;
    for (int i = 0; i < tot; i++)
    {
        if (out[i] == 0)
        {
            if (index == -1)
            {
                index = i;
            }
            else
            {
                cout << 0 << endl;
                return 0;
            }
        }
    }

    cout << sum[index] << '\n';

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}