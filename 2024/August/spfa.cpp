// 2024/08/07 14:09:17
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
    int n, m ,s;
    cin >> n >> m >> s;
    s--;
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
            }
        }
        else
        {
            G[u].try_emplace(v, w);
        }
    }

    constexpr i64 INF = 0x3f3f3f3f3f3f3f3f;

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

    auto dis = spfa(s);
    for (int i = 0; i < n; i++)
    {
        cout << (dis[i] != INF ? dis[i] : (i64(2147483647))) << ' ';
    }
}