// // 2023/09/23 13:45:09
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <cstdint>
// #include <vector>
// #include <string>
// #include <set>
// #include <map>
// #include <unordered_map>
// #include <unordered_set>
// #include <queue>
// #include <functional>
// #include <iomanip>
// #include <cmath>
// #include <stack>
// #include <array>
// #include <fstream>
// using namespace std;

// using ll = long long;
// using pii = pair<int, int>;
// constexpr int N = 10005;
// constexpr int INF = 0x3f3f3f3f;

// struct edge
// {
//     edge(int a = -1, int b = -1)
//     {
//         to = a;
//         cost = b;
//     }

//     int to, cost;
// };

// int dis[N];
// vector<edge> G[N];

// void dijkstra(int begin)
// {
//     priority_queue<pii, vector<pii>, greater<pii>> que;
//     memset(dis, 0x3f, sizeof(dis));
//     dis[begin] = 0;
//     que.emplace(0, begin);

//     while (!que.empty())
//     {
//         pii p = que.top(); que.pop();
//         if (dis[p.second] < p.first) continue;
//         int to = p.second;
//         for (int i = 0; i < (int)G[to].size(); i++)
//         {
//             const edge& e = G[to][i];
//             if (dis[e.to] > dis[to] + e.cost)
//             {
//                 dis[e.to] = dis[to] + e.cost;
//                 que.emplace(dis[e.to], e.to);
//             }
//         }
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int n, m, k;
//     cin >> n >> m >> k;
//     map<pii, int> mp;
//     for (int i = 0; i < k; i++)
//     {
//         int x, y;
//         cin >> x >> y;
//         mp[make_pair(x, y)] = i;
//     }

//     int begins = mp[{1, 1}];
//     int endss;
//     if (mp.count({ n, m }) != 0)
//         endss = mp[{n, m}];
//     else
//     {
//         mp[{n + 1, m + 1}] = k;
//         endss = k;
//     }

//     for (auto [p, index] : mp)
//     {
//         for (auto [p1, index1] : mp)
//         {
//             if (p1 == p && index1 == index)
//                 continue;

//             auto [x, y] = p;
//             auto [x1, y1] = p1;
//             if (abs(x - x1) + abs(y - y1) == 1)
//                 G[index].emplace_back(index1, 0);
//             else if (abs(x - x1) <= 2 || abs(y - y1) <= 2)
//                 G[index].emplace_back(index1, 1);
//         }
//     }

//     dijkstra(begins);
//     if (dis[endss] == INF)
//         cout << -1;
//     else
//     {
//         cout << dis[endss];
//     }
//     cout << endl;


//     // for (int i = 0; i < 10; i++)
//     // {
//     //     if (G[i].size() != 0)
//     //     {
//     //         cout << G[i].size() << '\n';
//     //         for (auto [x, cost] : G[i])
//     //             cout << x << ' ';
//     //         cout << '\n';
//     //     }
//     // }


// #ifdef LOCAL
//     cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
// #endif
//     cout << endl;
//     return 0;
// }


// 2023/09/23 15:09:09
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
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 10005;
constexpr int INF = 0x3f3f3f3f;
int nx[N], ny[N];

int dis[N];
bool vis[N];
int n, m, k;

void spfa(int start)
{
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    queue<int> que;
    que.emplace(start);
    dis[start] = 0;
    vis[start] = 1;
    while (!que.empty())
    {
        int u = que.front(); que.pop();
        vis[u] = 0;
        for (int i = 1; i <= k; i++)
        {
            int cost;
            int dx = abs(nx[i] - nx[u]);
            int dy = abs(ny[i] - ny[u]);
            if (dx + dy == 1)
                cost = 0;
            else if (dx <= 2 || dy <= 2)
                cost = 1;
            else
                cost = INF;
            if (dis[i] > cost + dis[u])
            {
                dis[i] = cost + dis[u];
                vis[i] = 1;
                que.emplace(i);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k;
    bool flag = 0;
    for (int i = 1; i <= k; i++)
    {
        cin >> nx[i] >> ny[i];
        if (nx[i] == n && ny[i] == m)
        {
            flag = 1;
        }
    }

    if (!flag)
    {
        k++;
        nx[k] = n + 1;
        ny[k] = m + 1;
    }

    spfa(1);
    cout << (dis[k] == INF ? -1 : dis[k]) << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}