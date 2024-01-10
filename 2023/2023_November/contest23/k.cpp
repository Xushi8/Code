// 2023/11/15 15:13:50
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
#include <fstream>
#include <bitset>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 1000005;

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
            v = stk.top();
            stk.pop();
            vis[v] = 0;
            c[v] = tot;
            sum[tot]++;
        } while (u != v);
        tot++;
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        out[i] = 0, dfn[i] = 0, low[i] = 0, c[i] = 0, sum[i] = 0, vis[i] = 0;
        stack<int>().swap(stk);
        G[i].clear();
        tot = 0;
    }

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].emplace_back(v);
    }

    for (int i = 0; i < n; i++)
    {
        if (dfn[i] == 0)
        {
            tarjan(i);
        }
    }

    cout << (tot == 1 ? "YES" : "NO") << '\n';
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

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}