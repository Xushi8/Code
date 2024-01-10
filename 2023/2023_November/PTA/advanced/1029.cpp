// 2023/11/09 15:01:11
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

int bg, ed, n, m;
vector<array<int, 3>> G[N];

vector<int> ans_path;
int ans_cost;
vector<int> path;
int dis[N];
bool vis[N];

void dfs(int u, int now_dis, int now_cost)
{
    if (vis[u])
    {
        return;
    }
    vis[u] = 1;
    path.push_back(u);

    if (u == ed)
    {
        if (dis[ed] > now_dis || (dis[ed] == now_dis && now_cost < ans_cost))
        {
            dis[ed] = now_dis;
            ans_path = path;
            ans_cost = now_cost;
        }
        
        path.pop_back();
        vis[u] = 0;
        return;
    }

    for (auto [v, w, cost] : G[u])
    {
        dfs(v, now_dis + w, now_cost + cost);
    }

    path.pop_back();
    vis[u] = 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> bg >> ed;
    for (int i = 0; i < m; i++)
    {
        int u, v, w, cost;
        cin >> u >> v >> w >> cost;
        G[u].push_back({v, w, cost});
        G[v].push_back({u, w, cost});
    }

    memset(dis, 0x3f, sizeof(dis));
    ans_cost = 0x3f3f3f3f;
    dfs(bg, 0, 0);

    for(auto x : ans_path) {
        cout << x << ' ';
    }

    cout << dis[ed] << ' ' << ans_cost;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}