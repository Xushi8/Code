<<<<<<< HEAD
// 2024/10/11 12:58:14
=======
// 2024/10/09 13:04:56
>>>>>>> 918c85c74bddc670efff5bf57be32a1d0b28456d
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
    int n, a, b;
    cin >> n >> a >> b;
    a--;
    b--;
    vector<vector<int>> G(n);
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    vector<char> vis(n);
    int target;
    auto dfs = [&](auto&& self, int u, int par) -> bool
    {
        if (vis[u])
        {
            return false;
        }
        vis[u] = 1;
        for (auto v : G[u])
        {
            if (v == par)
            {
                continue;
            }
            if (vis[v])
            {
                target = v;
                return true;
            }

            bool ret = self(self, v, u);
            if (ret)
                return true;
        }
        return false;
    };

    dfs(dfs, b, -1);

    auto get_dis = [&](int from, int to)
    {
        vector<int> dis(n, static_cast<int>(1e9));
        queue<int> que;
        que.emplace(from);
        dis[from] = 0;
        while (!que.empty())
        {
            auto u = que.front();
            que.pop();
            for (auto v : G[u])
            {
                if (dis[v] > dis[u] + 1)
                {
                    dis[v] = dis[u] + 1;
                    que.emplace(v);
                }
            }
        }
        return dis[to];
    };

    int disa = get_dis(a, target);
    int disb = get_dis(b, target);
    cout << (disa > disb ? "YES" : "NO") << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    tt = 1;
    cin >> tt;
    while (tt--)
    {
        solve();
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
