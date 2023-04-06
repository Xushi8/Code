#include <bits/stdc++.h>
using namespace std;

// const int maxn = 10005;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int n, tt;
//     cin >> n >> tt;
//     init_unite_search(n);
//     while (tt--)
//     {
//         int a, b, c;
//         cin >> a >> b >> c;
//         if (a == 1)
//         {
//             unite(b, c);
//         }
//         else
//         {
//             if (same(b, c)) cout << "Y\n";
//             else cout << "N\n";
//         }
//     }

//     cout << flush;
//     system("pause");
//     return 0;
// }

// int V;
// const int max_v = 5005, inf = 0x3f3f3f3f;
// int mincost[max_v];
// bool used[max_v];
// int cost[max_v][max_v];

// int prim()
// {
//     for (int i = 0; i < V; i++)
//     {
//         used[i] = false;
//         mincost[i] = inf;
//     }
//     mincost[0] = 0;
//     int res = 0;
//     while (1)
//     {
//         int v = -1;
//         for (int u = 0; u < V; u++)
//         {
//             if (!used[u] && (v == -1 || mincost[u] < mincost[v]))
//                 v = u;
//         }
//         if (v == -1) break;
//         used[v] = true;
//         res += mincost[v];
//         for (int u = 0; u < V; u++)
//         {
//             mincost[u] = min(mincost[u], cost[v][u]);
//         }
//     }
//     return res;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     memset(cost, 0x3f, sizeof(cost));
//     int E;
//     cin >> V >> E;
//     for (int i = 0; i < E; i++)
//     {
//         int a, b, c;
//         cin >> a >> b >> c;
//         a--; b--;
//         cost[a][b] = c;
//     }
//     cout << prim();

//     cout << flush;
//     system("pause");
//     return 0;
// }
const int max_v = 5005, inf = 0x3f3f3f3f;

int par[max_v], rank[max_v];
void init_unite_search(int n)
{
    for (int i = 0; i < n; i++)
    {
        par[i] = i;
        ::rank[i] = 0;
    }
}

int find(int x)
{
    if (par[x] == x) return x;
    else return par[x] = find(par[x]);
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y) return;

    if (::rank[x] < ::rank[y])
    {
        par[x] = y;
    }
    else
    {
        par[y] = x;
        if (::rank[x] == ::rank[y])
        {
            ::rank[x]++;
        }
    }
}

bool same(int x, int y)
{
    return find(x) == find(y);
}


// class edge
// {
// public:
//     int to, cost;
//     edge(const int& a, const int& b)
//     {
//         to = a;
//         cost = b;
//     }
//     edge() {}
// };
// typedef pair<int, int> P;
// vector<edge> G[max_v];
// int mincost[max_v];
// int V, E;

// int prim()
// {
//     priority_queue<P, vector<P>, greater<P>> que;
//     fill(mincost, mincost + V, inf);
//     mincost[0] = 0;
//     que.emplace(0, 0);
//     int res = 0;
//     while (!que.empty())
//     {
//         P p = que.top(); que.pop();
//         int v = p.second;
//         if (mincost[v] < p.first) continue;

//         res += mincost[v];
//         for (int i = 0; i < (int)G[v].size(); i++)
//         {
//             edge& e = G[v][i];
//             if (mincost[e.to] > e.cost)
//             {
//                 mincost[e.to] = e.cost;
//                 que.emplace(mincost[e.to], e.to);
//             }
//         }
//     }
//     return res;
// }


class edge
{
public:
    int u, v, cost;
    edge(const int& a, const int& b, const int& c)
    {
        u = a;
        v = b;
        cost = c;
    }
};
bool cmp(const edge& a, const edge& b)
{
    return a.cost < b.cost;
}
int V, E;
const int max_e = 200005;
vector<edge> es;

int kruskal()
{
    sort(es.begin(), es.begin() + E, cmp);
    init_unite_search(V);
    int res = 0;
    for (int i = 0; i < E; i++)
    {
        edge& e = es[i];
        if (!same(e.u, e.v))
        {
            unite(e.u, e.v);
            res += e.cost;
        }
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> V >> E;
    for (int i = 0; i < E; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        es.emplace_back(a, b, c);
    }
    int ans = kruskal();
    // 判是否有通路, 如果所有的父亲都是同一个, 则有通路
    bool flag = 0;
    for (int i = 0; i < V - 1; i++)
    {
        if (par[i] != par[i + 1])
        {
            flag = 1;
            break;
        }
    }
    if (flag) cout << "orz";
    else cout << ans;

    cout << flush;
    system("pause");
    return 0;
}