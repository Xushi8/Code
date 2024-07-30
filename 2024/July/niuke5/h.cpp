// 2024/07/30 14:51:08
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
    vector<vector<int>> G(n + 1, vector<int>(n + 1));
    vector<int> vis(n + 1);
    vector<int> deg(n + 1);
    set<pii> st;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        if (u > v)
            swap(u, v);
        if (!st.count({u, v}) && u != v)
        {
            G[u][v] = 1;
            G[v][u] = 1;
            deg[u]++;
            deg[v]++;
        }
    }

    int ans = 0;

    function<int(int, int)> dfs = [&](int u, int now) -> int
    {
        if (vis[u])
            return 0;
        vis[u] = 1;
        int maxx = now;
        // cerr << u << ' ' << now << '\n';

        vector<int> ver;
        for (int v = 1; v <= n; v++)
        {
            if (u == v || vis[v] || !G[u][v])
                continue;
            ver.emplace_back(v);
        }

        sort(ver.begin(), ver.end(), [&](int const& l, int const& r)
            {
                return deg[l] < deg[r];
            });

        for (auto v : ver)
        {
            if (u == v || vis[v])
                continue;
            
            if (G[u][v])
            {
                int cnt = 2;
                for (int i = 1; i <= n; i++)
                {
                    if (i == u || i == v || !G[u][i])
                        continue;
                    if (!vis[i])
                    {
                        cnt++;
                    }
                    vis[i] = 1;
                }
                if (now + cnt <= ans)
                {
                    continue;
                }
                int res = dfs(v, now + 1);
                maxx = max(maxx, res);

                for (int i = 1; i <= n; i++)
                {
                    if (i == u || i == v || !G[u][i])
                        continue;
                    vis[i] = 0;
                }
            }
        }

        vis[u] = 0;
        return maxx;
    };

    vector<pii> shunxu(n);
    for (int i = 0; i < n; i++)
    {
        shunxu[i] = {deg[i + 1], i};
    }
    sort(shunxu.begin(), shunxu.end());

    for (auto [cnt, u] : shunxu)
    {
        int res = dfs(u, 1);
        ans = max(ans, res);
    }
    
    // for (int i = 1; i <= n; i++)
    // {
    //     int res = dfs(i, 1);
    //     ans = max(ans, res);
    // }

    cout << ans << '\n';
}