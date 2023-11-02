// 2023/11/02 17:38:01
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

int n, m, s;

vector<pii> G[N];
int dis[N];

void dijkstra(int s)
{
    priority_queue<pii, vector<pii>, greater<>> que;
    memset(dis, 0x3f, sizeof(dis));
    que.emplace(0, s);
    dis[s] = 0;
    while (!que.empty())
    {
        auto [cost, u] = que.top();
        que.pop();
        if (cost > dis[u])
            continue;

        for (auto [v, w] : G[u])
        {
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                que.emplace(dis[v], v);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> s;
    s--;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        G[u].emplace_back(v, w);
    }

    dijkstra(s);

    for (int i = 0; i < n; i++)
    {
        cout << (dis[i] == 0x3f3f3f3f ? INT32_MAX : dis[i]) << ' ';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}