// 2024/11/05 21:34:09
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
    int n;
    cin >> n;
    vector<vector<int>> G(n + 1);
    vector<int> deg(n + 1), val(n + 1);
    for (int u = 1; u <= n; u++)
    {
        int par, w;
        cin >> par >> w;
        G[par].emplace_back(u);
        G[u].emplace_back(par);
        deg[par]++;
        deg[u]++;
        val[u] = w;
    }

    multiset<i64> use, capa;
    auto dfs = [&](auto&& self, int u, int par) -> i64
    {
        if (deg[u] == 1 && u != 0)
        {
            return val[u];
        }

        i64 sum = 0;
        for (auto v : G[u])
        {
            if (v == par)
                continue;
            sum += self(self, v, u);
        }

        // cerr << u << ' ' << par << ' ' << sum << endl;
        if (u != 0)
        {
            capa.emplace(val[u]);
            use.emplace(sum);
        }

        return sum;
    };

    i64 root_sum = dfs(dfs, 0, -1);
    if (root_sum > 2200)
    {
        cout << "NO\n";
        return;
    }

    for (auto it1 = use.begin(), it2 = capa.begin(); it1 != use.end(); it1++, it2++)
    {
        if (*it1 > *it2)
        {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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
