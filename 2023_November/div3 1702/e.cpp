// 2023/11/25 20:06:18
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

vector<int> G[N];
int color[N], deg[N];
bool ok;

void dfs(int u, int c)
{
    for (int v : G[u])
    {
        if (color[v] != -1)
        {
            if (color[v] == color[u])
            {
                ok = 0;
                return;
            }
        } else {
            color[v] = !c;
            dfs(v, color[v]);
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    ok = 1;
    for (int i = 0; i < n; i++)
    {
        G[i].clear();
        deg[i] = 0;
        color[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        deg[u]++;
        deg[v]++;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
        if (deg[u] > 2 || deg[v] > 2)
        {
            ok = 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (ok && color[i] == -1)
        {
            color[i] = 1;
            dfs(i, color[i]);
        }
    }

    cout << (ok ? "YES" : "NO") << '\n';
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