#include <bits/stdc++.h>
using namespace std;

// bellman ford

// class edge
// {
// public:
//     int from, to, cost;
// };

// const int max_e = 500005, max_v = 100005, inf = 0x3f3f3f3f;

// edge es[max_e];
// int d[max_v]; // 最短距离
// int V, E; // v是顶点, e是边数

// // 找以s为顶点到其他点的最小距离
// void shortest_path(int s)
// {
//     for (int i = 1; i <= V; i++) d[i] = inf;
    
//     d[s] = 0;
//     while (1)
//     {
//         bool update = false;
//         for (int i = 1; i <= E; i++)
//         {
//             edge e = es[i];
//             if (d[e.from] != inf && d[e.to] > d[e.from] + e.cost)
//             {
//                 d[e.to] = d[e.from] + e.cost;
//                 update = true;
//             }
//         }
//         if (!update) break;
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int s;
//     cin >> V >> E >> s;
//     for (int i = 1; i <= E; i++)
//     {
//         cin >> es[i].from >> es[i].to >> es[i].cost;
//     }
    
//     shortest_path(s);
//     for (int i = 1; i <= V; i++)
//     {
//         if (d[i] != inf)
//             cout << d[i] << ' ';
//         else
//             cout << 2147483647 << ' ';
//     }

//     cout << flush;
//     system("pause");
//     return 0;
// }

// dijkstra

class edge
{
public:
    edge(const int& a, const int& b)
    {
        to = a;
        cost = b;
    }
    
    int to, cost;
};
typedef pair<int, int> P;
const int max_v = 10000000, inf = 0x3f3f3f3f;
int V;
vector<edge> G[max_v];
int d[max_v];

void dijkstra(int s)
{
    priority_queue<P, vector<P>, greater<P>> que;
    fill(d, d + V + 1, inf);
    d[s] = 0;
    que.push(P(0, s));

    while (!que.empty())
    {
        P p = que.top(); que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        for (int i = 0; i < (int)G[v].size(); i++)
        {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost)
            {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int s, E;
    cin >> V >> E >> s;
    for (int i = 0; i < E; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge e(b, c);
        G[a].emplace_back(e);
    }

    dijkstra(s);
    for (int i = 0; i < V; i++)
    {
        if (d[i] != inf)
            cout << d[i] << '\n';
        else
            cout << "INF" << '\n';
    }
    
    cout << flush;
    system("pause");
    return 0;
}