// 2023/08/17 16:18:36
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
const int N = 1000005;

bool vis[2 * N];
int dfn[2 * N], low[N * 2], c[N * 2];
vector<int> scc[N * 2], G[N * 2];
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
        else if (vis[v])
        {
            low[u] = min(low[u], low[v]);
        }
    }

    if (low[u] == dfn[u])
    {
        do
        {
            c[u] = tot;
            u = stk.top(); stk.pop();
            vis[u] = 0;
            scc[tot].emplace_back(u);
        } while (low[u] != dfn[u]);
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
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--; x2--;
        if (y1 == 1 && y2 == 1)
        {
            G[x1 + n].emplace_back(x2);
            G[x2 + n].emplace_back(x1);
        }
        else if (y1 == 1 && y2 == 0)
        {
            G[x1 + n].emplace_back(x2 + n);
            G[x2].emplace_back(x1);
        }
        else if (y1 == 0 && y2 == 1)
        {
            G[x1].emplace_back(x2);
            G[x2 + n].emplace_back(x1 + n);
        }
        else
        {
            G[x1].emplace_back(x2 + n);
            G[x2].emplace_back(x1 + n);
        }
    }

    for (int i = 0; i < n * 2; i++)
    {
        if (dfn[i] == 0)
        {
            tarjan(i);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (c[i] == c[i + n])
        {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    cout << "POSSIBLE\n";
    for (int i = 0; i < n; i++)
    {
        cout << (c[i] < c[i + n]) << ' ';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}