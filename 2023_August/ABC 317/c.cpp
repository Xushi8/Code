// 2023/08/31 19:32:29
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
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
constexpr int INF = 0x3f3f3f3f;
constexpr int MOD = (int)(1e9 + 7);
constexpr int N = 105;
int n, m;

vector<int> G[N];

int dis[N][N];
bool vis[N];
int ans;

void dfs(int u, int now)
{
    vis[u] = 1;
    for (int v : G[u])
    {
        if (!vis[v])
        {
            dfs(v, now + dis[u][v]);
        }
    }

    ans = max(ans, now);
    vis[u] = 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
        dis[u][v] = w;
        dis[v][u] = w;
    }

    for (int i = 0; i < n; i++)
    {
        dfs(i, 0);
    }

    cout << ans << '\n';

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}