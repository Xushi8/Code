// 2025/04/16 20:05:33
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
    vector<int> vis(n);

    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            int x;
            cin >> x;
            G[i].emplace_back(x);
            vis[x] = 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        sort(G[i].begin(), G[i].end());
    }

    int root;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            root = i;
            break;
        }
    }

    vector<int> ans;
    vector<int> now;
    auto dfs = [&](auto&& self, int u) -> void
    {
        now.emplace_back(u);
        if (G[u].empty())
        {
            if (now.size() > ans.size())
            {
                ans = now;
            }
            now.pop_back();
            return;
        }

        for (auto v : G[u])
        {
            self(self, v);
        }
        now.pop_back();
    };

    dfs(dfs, root);
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++)
    {
        if (i != 0)
        {
            cout << ' ';
        }
        cout << ans[i];
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
