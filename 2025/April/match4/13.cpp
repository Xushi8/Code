// 2025/04/16 20:43:05
#ifdef LOCAL
#include <basic_std_lib.h>
#else
#include <bits/stdc++.h>
#endif
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 1e6 + 6;

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<array<int, 3>>> G(n), RG(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, c, d;
        cin >> u >> v >> c >> d;
        if (u == v)
        {
            continue;
        }
        u--;
        v--;
        G[u].push_back({v, c, d});
        RG[v].push_back({u, c, d});
    }

    constexpr i64 INF = 0x3f3f3f3f3f3f3f3f;
    auto dijkstra = [&](int be, vector<vector<array<int, 3>>> const& g, bool cash) -> vector<i64>
    {
        vector<i64> dis(n, INF);
        priority_queue<pii, vector<pii>, greater<>> que;
        que.emplace(0, be);
        dis[be] = 0;
        while (!que.empty())
        {
            auto [old_d, u] = que.top();
            que.pop();
            if (dis[u] < old_d)
            {
                continue;
            }

            for (auto [v, c, d] : g[u])
            {
                int cost;
                if (cash)
                {
                    cost = c;
                }
                else
                {
                    cost = d;
                }
                if (dis[v] > dis[u] + cost)
                {
                    dis[v] = dis[u] + cost;
                    que.emplace(dis[v], v);
                }
            }
        }

        return dis;
    };

    vector<i64> dis1 = dijkstra(0, G, true);
    vector<i64> dis2 = dijkstra(n - 1, RG, false);

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    while (q--)
    {
        int index, x;
        cin >> index >> x;
        index--;
        a[index] = x;

        i64 ans = dis1[n - 1];
        for (int i = 0; i < n; i++)
        {
            if (dis1[i] != INF && dis2[i] != INF)
            {
                i64 t = dis1[i] + ((dis2[i] + a[i] - 1) / a[i]);
                ans = min(ans, t);
            }
        }

        cout << ans << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    tt = 1;
    while (tt--)
    {
        solve();
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
