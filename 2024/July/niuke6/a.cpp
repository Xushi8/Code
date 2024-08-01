// 2024/08/01 13:59:27
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

    cout << setprecision(20) << fixed;

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

using i64 = int64_t;
using u64 = uint64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 1000005;

void solve()
{
    int n;
    cin >> n;
    vector<vector<pii>> G(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }

    int cnt = 0;
    for (auto [v, w] : G[1])
    {
        if (w == 0)
        {
            cnt++;
        }
    }
    if (cnt == G[1].size())
    {
        cout << 0.0 << '\n';
        return;
    }

    vector<array<int, 2>> zeo_one(n + 1);
    double ans = 1;

    // auto dfs = [&](auto&& self, int u, int par) -> void
    // {
    //     array<int, 4> maxx;
    //     maxx.fill(0);
    //     for (auto [v, w] : G[u])
    //     {
    //         if (v == par)
    //             continue;
    //         self(self, v, u);
    //         auto now = zeo_one[u]; // 0 0 0 0
    //         auto t = zeo_one[v];

    //         t[w]++;
    //         t[w + 2]++;

    //         pii p1 = {now[0] + t[0], now[1] + t[1]};
    //         pii p2 = {now[0] + t[2], now[1] + t[3]};

    //         if (1. * p1.second / (p1.first + p1.second) > 1. * (maxx[1]) / (maxx[0] + maxx[1]) || (maxx[0] == 0 && maxx[1] == 0))
    //         {
    //             maxx[0] = p1.first;
    //             maxx[1] = p1.second;
    //         }
    //         if (1. * p2.second / (p2.first + p2.second) > 1. * (maxx[1]) / (maxx[0] + maxx[1]))
    //         {
    //             maxx[0] = p2.first;
    //             maxx[1] = p2.second;
    //         }

    //         // 右边
    //         if (1. * p1.first / (p1.first + p1.second) > 1. * maxx[2] / (maxx[2] + maxx[3]) || (maxx[2] == 0 && maxx[3] == 0))
    //         {
    //             maxx[2] = p1.first;
    //             maxx[3] = p1.second;
    //         }
    //         if (1. * p2.first / (p2.first + p2.second) > 1. * maxx[2] / (maxx[2] + maxx[3]))
    //         {
    //             maxx[2] = p2.first;
    //             maxx[3] = p2.second;
    //         }
    //     }
    //     zeo_one[u] = maxx;
    // };

    auto dfs = [&](auto&& self, int u, int par, int ww) -> void
    {
        if (u != 1)
        {
            zeo_one[u] = zeo_one[par];
            zeo_one[u][ww]++;
        }
        for (auto [v, w] : G[u])
        {
            if (v == par)
                continue;
            self(self, v, u, w);
        }
    };

    dfs(dfs, 1, 0, -1);
    cout << ans << '\n';
}