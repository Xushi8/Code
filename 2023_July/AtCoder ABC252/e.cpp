// 2023/07/06 21:54:01
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
const int N = 1000005;


struct edge
{
    ll to, cost, index;
    edge(ll x, ll y, ll z)
    {
        to = x;
        cost = y;
        index = z;
    }
    
    friend bool operator < (edge a, edge b)
    {
        if (a.cost != b.cost)
            return a.cost > b.cost;
        else
            return a.to > b.to;
    }
};

vector<edge> G[N];
ll dis[N];
bool used[N];

void dijkstra(int start)
{
    memset(dis, 0x3f, sizeof(dis));
    dis[start] = 0;
    priority_queue<edge> que;
    que.push({ 0, 0, -1 });
    while (!que.empty())
    {
        edge p = que.top(); que.pop();
        int v = p.to;
        if (dis[v] < p.cost)
            continue;

        if (p.index != -1)
            cout << p.index << ' ';

        for (size_t i = 0; i < G[v].size(); i++)
        {
            edge e = G[v][i];
            if (dis[e.to] > dis[v] + e.cost)
            {
                dis[e.to] = dis[v] + e.cost;
                que.push({ e.to, dis[e.to], e.index });
            }
        }
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int v, e;
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        G[a].emplace_back(b, c, i + 1);
        G[b].emplace_back(a, c, i + 1);
    }

    dijkstra(0);

    cout << endl;
    return 0;
}