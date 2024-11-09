// 2024/11/09 16:26:18
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
    auto print = [](long double x)
    {
        if (1e-20 < x && x < 1e20)
        {
            cout << setprecision(30) << fixed;
        }
        cout << x << '\n';
    };

    int n, m;
    cin >> n >> m;
    vector<long double> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<vector<int>> G(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].emplace_back(v);
    }

    vector<char> vis(n);
    set<int> st;
    vector<int> now;
    vector<char> incircle(n);

    auto dfs = [&](auto&& self, int u) -> bool
    {
        if (st.count(u))
        {
            if (!incircle[u])
                return true;
            else
                return false;
        }
        st.emplace(u);
        now.emplace_back(u);
        for (auto v : G[u])
        {
            bool ok = self(self, v);
            if (ok)
            {
                return true;
            }
        }
        return false;
    };

    vector<long double> ans;

    for (int u = 0; u < n; u++)
    {
        st.clear();
        now.clear();
        if (vis[u])
        {
            continue;
        }
        bool flag = dfs(dfs, u);
        vector<int> index{now.begin(), now.end()};
        vector<long double> t(now.size());
        set<long double> tmp;
        for (size_t i = 0; i < now.size(); i++)
        {
            vis[index[i]] = 1;
            t[i] = 1 - a[index[i]];
            if (flag)
            {
                if (!incircle[index[i]])
                {
                    incircle[index[i]] = 1;
                    tmp.emplace(t[i]);
                }
            }
        }

        if (flag)
        {
            ans.emplace_back(reduce(tmp.begin(), tmp.end(), static_cast<long double>(1), std::multiplies<>()));
        }
        else
        {
            ans.emplace_back(t.back());
        }
    }

    print(*max_element(ans.begin(), ans.end()));
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
