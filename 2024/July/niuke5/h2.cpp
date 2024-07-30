// 2024/07/30 17:07:00
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
    vector<vector<int>> G(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    vector<int> vis(n);
    int ans = 0;

    auto dfs = [&](auto&& self, int u, int now) -> void
    {
        ans = max(ans, now);
        for (auto v : G[u])
        {
            if (vis[v])
                continue;

            for (auto v1 : G[u])
            {
                vis[v1]++;
            }
            self(self, v, now + 1);
            for (auto v1 : G[u])
            {
                vis[v1]--;
            }
        }
    };

    for (int i = 0; i < n; i++)
    {
        dfs(dfs, i, 1);
    }

    cout << ans << '\n';
}