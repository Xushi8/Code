auto spfa = [&](int s)
{
    vector<i64> dis(n, INF);
    queue<int> que;
    vector<int> vis(n);
    que.emplace(s);
    dis[s] = 0;
    vis[s] = 1;
    while (!que.empty())
    {
        auto u = que.front();
        que.pop();
        vis[u] = 0;
        for (auto [v, w] : G[u])
        {
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                if (!vis[v])
                {
                    que.emplace(v);
                    vis[v] = 1;
                }
            }
        }
    }
    return dis;
};