// 2025/04/16 20:27:46
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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int m;
    cin >> m;
    vector<vector<int>> b(m);
    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k;
        vector<int> tmp(k);
        for (int j = 0; j < k; j++)
        {
            cin >> tmp[j];
        }
        b[i] = std::move(tmp);
    }

    vector<int> ans;
    vector<int> now_ans;
    vector<int> vis(n);
    bool ok = false;
    auto dfs = [&](auto&& self, int now) -> void
    {
        if (now == n - 1)
        {
            ok = true;
            ans = now_ans;
            return;
        }

        for (int i = 0; i < m; i++)
        {
            if (ok)
            {
                return;
            }

            if (!vis[i] && now + b[i].size() <= n)
            {
                bool flag = true;
                for (int j = 0; j < b[i].size(); j++)
                {
                    if (a[now + j] != b[i][j])
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {
                    vis[i] = true;
                    now_ans.emplace_back(i);
                    self(self, now + b[i].size() - 1);
                    now_ans.pop_back();
                    vis[i] = false;
                }
            }
        }
    };

    dfs(dfs, 0);

    for (int i = 0; i < ans.size(); i++)
    {
        if (i != 0)
        {
            cout << ' ';
        }
        cout << ans[i] + 1;
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
