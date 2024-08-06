// 2024/08/06 19:10:53
#ifdef LOCAL
#include <basic_std_lib.h>
#else
#include <bits/stdc++.h>
#endif
using namespace std;

void solve();

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

using i64 = int64_t;
using u64 = uint64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 1000005;

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