auto dijkstra = [&](int s)
{
    vector<i64> dis(n, INF);
    priority_queue<pii, vector<pii>, greater<>> que;
    que.emplace(0, s);
    dis[s] = 0;
    while (!que.empty())
    {
        auto [ww, u] = que.top();
        que.pop();
        if (dis[u] < ww)
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

    return dis;
};