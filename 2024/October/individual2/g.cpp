// 2024/10/11 12:34:21
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

    vector<int> ans;

    auto dfs = [&](auto&& self, int u, int par) -> double
    {
        double res = 0;
        for (auto v : G[u])
        {
            if (v == par)
            {
                continue;
            }
            res += self(self, v, u) + 1;
        }

        if (res != 0)
        {
            size_t cnt = G[u].size();
            if (u != 0)
                cnt--;
            res /= cnt;
        }
        return res;
    };

    dfs(dfs, 0, -1);

    cout << setprecision(20) << fixed;
    cout << dfs(dfs, 0, -1) << '\n';
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
