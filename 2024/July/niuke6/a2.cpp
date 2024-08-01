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

    double ans = 1.0;
    auto dfs = [&](auto&& self, int u, int par, int deep, vector<int>& chuan) -> void
    {
        if (G[u].size() == 1 && u != 1)
        {
            int cnt1 = 0;
            int cnt0 = 0;
            double temp = 0.0;
            for (int i = 0; i < chuan.size(); i++)
            {
                if (chuan[i] == 0)
                {
                    cnt0++;
                }
                else
                {
                    cnt1++;
                }
                temp = max(temp, (double)(cnt0) / (double)(cnt0 + cnt1));
            }
            ans = min(ans, 1.0 - temp);
        }

        if (deep % 2 == 0)
        {
            int cnt = 0;
            for (auto [v, w] : G[u])
            {
                if (v == par)
                    continue;
                if (w == 1)
                {
                    cnt++;
                    chuan.emplace_back(w);
                    self(self, v, u, deep + 1, chuan);
                    chuan.pop_back();
                }
            }

            if (cnt == 0)
            {
                for (auto [v, w] : G[u])
                {
                    if (v == par)
                        continue;
                    chuan.emplace_back(w);
                    self(self, v, u, deep + 1, chuan);
                    chuan.pop_back();
                }
            }
        }
        else
        {
            int cnt = 0;
            for (auto [v, w] : G[u])
            {
                if (v == par)
                    continue;
                if (w == 0)
                {
                    cnt++;
                    chuan.emplace_back(w);
                    self(self, v, u, deep + 1, chuan);
                    chuan.pop_back();
                }
            }

            if (cnt == 0)
            {
                for (auto [v, w] : G[u])
                {
                    if (v == par)
                        continue;
                    chuan.emplace_back(w);
                    self(self, v, u, deep + 1, chuan);
                    chuan.pop_back();
                }
            }
        }
    };

    vector<int> chuan;
    dfs(dfs, 1, 0, 0, chuan);
    cout << ans << '\n';
}