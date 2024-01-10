#include <bits/stdc++.h>
using namespace std;

typedef int typevalue;

// 7.14
struct edge
{
    // 到的位置与路径的长度
    size_t to, cost;
};
vector<vector<edge>> func_7_14(size_t V, size_t E)
{
    vector<vector<edge>> G(V);
    for (size_t i = 0; i < E; i++)
    {
        size_t u, v, w;
        scanf("%zd%zd%zd", &u, &v, &w);
        G[u].push_back(edge(v, w));
    }
    return G;
}

// 7.22
// u时当前点，par是此时点的来源，遍历到par时要跳过
bool dfs(vector<vector<edge>> const& G, size_t u, size_t par, size_t target, vector<bool>& vis)
{
    // 判断是否遍历过
    if (vis[u])
    {
        return false;
    }
    vis[u] = 1;

    bool flag = false;
    for (auto [v, w] : G[u])
    {
        if (v == par)
        {
            continue;
        }
        if (v == target)
        {
            flag = true;
            break;
        }

        flag = dfs(G, v, u, target, vis);
        if (flag)
        {
            break;
        }
    }

    return flag;
}

bool func_7_22(vector<vector<edge>> const& G, size_t u, size_t v)
{
    vector<bool> vis(G.size());
    return dfs(G, u, -1, v, vis);
}

// 7.23
bool bfs(vector<vector<edge>> const& G, size_t from, size_t to, vector<bool>& vis)
{
    if (from == to)
    {
        return true;
    }
    queue<edge> que;
    que.push(edge(from, -1));
    vis[from] = 1;
    size_t par = -1;
    while (!que.empty())
    {
        auto [u, cost] = que.front();
        que.pop();
        for (auto [v, w] : G[u])
        {
            if (vis[v])
            {
                continue;
            }
            vis[v] = 1;
            if (v == to)
            {
                return true;
            }
            que.push(edge(v, w));
        }
    }

    return false;
}

bool func_7_23(vector<vector<edge>> const& G, size_t u, size_t v)
{
    vector<bool> vis(G.size());
    return bfs(G, u, v, vis);
}


// 7.24
