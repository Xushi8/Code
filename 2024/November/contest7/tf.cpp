// 2024/11/20 13:54:04
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
    int m, n;
    cin >> m >> n;

    vector<char> vis(m + 1);

    vector<vector<int>> ans;
    i64 all_ans = 0;
    auto dfs = [&](auto&& self, int now, int cnt, int maxx)
    {
        if (cnt == maxx)
        {
            vector<int> tmp;
            int g = 0;
            int minn = 1e9;
            for (int i = 2; i <= m; i++)
            {
                if (vis[i])
                {
                    tmp.emplace_back(i);
                    g = std::gcd(g, i);
                    minn = min(minn, i);
                }
            }
            if (g == minn)
            {
                return;
            }
            all_ans += tmp.size();
            ans.emplace_back(std::move(tmp));
            return;
        }

        for (int i = now; i <= m; i++)
        {
            if (!vis[i])
            {
                vis[i] = 1;
                self(self, i + 1, cnt + 1, maxx);
                vis[i] = 0;
            }
        }
    };

    for (int cnt = 2; cnt <= n; cnt++)
    {
        dfs(dfs, 2, 0, cnt);
    }

    cout << all_ans << '\n';
    for (auto const& vec : ans)
    {
        for (auto x : vec)
        {
            cout << x << ' ';
        }
        cout << '\n';
    }
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
