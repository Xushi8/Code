// 2023/11/08 11:10:10
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
constexpr int N = 1005;

vector<int> G[N];

bool vis[N];

void dfs(int u)
{
    if (vis[u])
        return;
    vis[u] = 1;
    for (int v : G[u])
    {
        dfs(v);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    while (k--)
    {
        int x;
        cin >> x;
        x--;
        memset(vis, 0, sizeof(vis));
        vis[x] = 1;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                ans++;
                dfs(i);
            }
        }
        cout << ans - 1 << '\n';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}