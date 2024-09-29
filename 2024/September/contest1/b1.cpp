// 2024/09/28 16:03:49
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

    set<int> ans;
    vector<int> cnt(n);

    auto dfs = [&](auto&& self, int u, int par) -> void
    {
        bool ok = 1;
        cnt[u] = color[u];
        for (auto v : G[u])
        {
            if (v == par)
                continue;
            self(self, v, u);
            if (cnt[v] == 0)
                ok = 0;
            cnt[u] += cnt[v];
        }
        if (ok && !color[u] && (u == 0 || cnt[u] < k))
            ans.emplace(u);
    };

    dfs(dfs, 0, -1);
    cout << ans.size() << '\n';
    for (auto x : ans)
    {
        cout << x + 1 << ' ';
    }
}