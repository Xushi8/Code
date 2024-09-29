// 2024/09/28 14:12:35
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
    int n, k;
    cin >> n >> k;
    vector<int> color(n);
    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        x--;
        color[x] = 1;
    }

    vector<vector<int>> G(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    vector<int> vis(n);
    set<int> ans;

    auto dfs = [&](auto&& self, int u, int par) -> size_t
    {
        vis[u] = 1;
        size_t cnt = 0, node_cnt = 0;
        for (auto v : G[u])
        {
            if (v == par)
                continue;
            cnt += self(self, v, u);
            node_cnt++;
        }

        if (!color[u] && cnt == node_cnt)
            ans.emplace(u);
        if (cnt == 0)
            cnt = color[u];
        return cnt;
    };

    for (int i = 0; i < n; i++)
    {
        if (!vis[i] && color[i])
        {
            dfs(dfs, i, -1);
        }
    }
        
    cout << ans.size() << '\n';
    for (auto x : ans)
    {
        cout << x + 1 << ' ';
    }
}