// 2023/04/23 12:09:43
#include <bits/stdc++.h>
using namespace std;

int rk[10004], par[10004];
void init(int n)
{
    for (int i = 0; i < n; i++)
    {
        rk[i] = 0;
        par[i] = i;
    }
}

int find(int x)
{
    if (par[x] == x)
        return x;
    else
        return par[x] = find(par[x]);
}

int same(int x, int y)
{
    return find(x) == find(y);
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return;

    if (rk[x] < rk[y])
    {
        par[x] = y;
    }
    else
    {
        par[y] = x;
        if (rk[x] == rk[y])
            rk[x]++;
    }
}

int V, E;
class edge
{
public:
    int to, cost;
    edge(const int& a, const int& b)
    {
        to = a;
        cost = b;
    }
};
vector<edge> G;

int dis[1005];

// bool cmp(const edge& a, const edge& b)
// {
//     return a.cost < b.cost;
// }

// int kruskal()
// {
//     sort(G.begin(), G.end(), cmp);
//     int res = 0;
//     init(E);
//     for (size_t i = 0; i < G.size(); i++)
//     {
//         if (!same(G[i].from, G[i].to))
//         {
//             unite(G[i].from, G[i].to);
//             res += G[i].cost;
//         }
//     }
//     return res;
// }

int inf = 0x3f3f3f3f;
typedef pair<int, int> pii;
long long solve(int start)
{
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int s;
    cin >> V >> E >> s;
    for (int i = 0; i < E; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        G.emplace_back(a, b, c);
    }
    cout << solve(s);

    cout << flush;
    return 0;
}