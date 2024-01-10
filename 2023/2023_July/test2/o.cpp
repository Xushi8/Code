// 2023/07/26 17:28:29
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
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const int N = 500005;

vector<int> G[N];
bool vis[N];
vector<int> ans;

void dfs(int u)
{
    if (vis[u])
        return;

    vis[u] = 1;
    ans.emplace_back(u);
    for (auto v : G[u])
    {
        vis[v] = 1;
        for (auto x : G[v])
            vis[x] = 1;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int V, E, K;
    cin >> V >> E >> K;
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    for (int i = 0; i < V; i++)
        dfs(i);

    cout << ans.size() << '\n';
    for (auto x : ans)
        cout << x + 1 << ' ';

    cout << endl;
    return 0;
}