// 2024/10/16 16:44:35
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
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> G(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        G[u].emplace_back(v, w);
    }

    auto dfs = [&](auto&& self, int u) -> double
    {
        vector<double> dis;
        for (auto [v, w] : G[u])
        {
            auto res = self(self, v);
            dis.emplace_back(res + w);
        }

        double res = 0;
        if (!dis.empty())
        {
            res = std::reduce(dis.begin(), dis.end(), 0.) / dis.size();
        }

        return res;
    };

    auto ans = dfs(dfs, 0);
    cout << setprecision(2) << fixed;
    cout << ans << '\n';
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
