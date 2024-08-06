void solve()
{
    int n, m;
    cin >> n >> m;
    vector<map<int, int>> G(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        if (u == v)
            continue;
        auto it = G[u].lower_bound(v);
        if (it != G[u].end() && it->first == v)
        {
            if (it->second > w)
            {
                it->second = w;
                it = G[v].lower_bound(u);
                it->second = w;
            }
        }
        else
        {
            G[u].emplace(v, w);
            G[v].emplace(u, w);
        }
    }

    auto prim = [&](int s) -> int
    {
        int res = 0;
        int cnt = 0;
        vector<int> vis(n, false);
        constexpr int INF = 0x3f3f3f3f;
        vector<int> dis(n, INF);
        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<>> que;
        que.push({0, s});
        dis[s] = 0;
        while (!que.empty())
        {
            auto [ww, u] = que.top();
            que.pop();
            if (vis[u] || dis[u] < ww)
                continue;
            vis[u] = 1;
            cnt++;
            res += ww;
            for (auto [v, w] : G[u])
            {
                if (!vis[v] && dis[v] > w)
                {
                    dis[v] = w;
                    que.push({w, v});
                }
            }
        }
        if (cnt == n)
            return res;
        else
            return -1;
    };

    int ret = prim(0);
    if (ret == -1)
        cout << "orz" << '\n';
    else
        cout << ret << '\n';
}