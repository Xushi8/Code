// 2024/08/01 15:15:36
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

    double ans = 0;
    auto dfs = [&](auto&& self, int u, int par, int deep, vector<int>& chuan, array<int, 2> cnt, double tmp) -> void
    {
        if (u != 1)
        {
            tmp = max(tmp, 1.0 * cnt[0] / (cnt[0] + cnt[1]));
            if (G[u].size() == 1)
            {
                ans = max(ans, 1 - tmp);
            }
        }

        for (auto [v, w] : G[u])
        {
            if (v == par)
                continue;
            chuan.emplace_back(w);
            cnt[w]++;
            self(self, v, u, deep + 1, chuan, cnt, tmp);
            cnt[w]--;
            chuan.pop_back();
        }
    };

    vector<int> chuan;
    array<int, 2> cnt;
    cnt.fill(0);
    dfs(dfs, 1, 0, 0, chuan, cnt, 0);
    cout << ans << '\n';
}