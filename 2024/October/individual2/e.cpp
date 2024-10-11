// 2024/10/09 15:28:02
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    int tt = 1;
    while (cin >> n && n != 0)
    {
        cout << "Case " << tt++ << ": ";
        set<string> a;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            a.emplace(std::move(s));
        }

        int m;
        cin >> m;
        map<string, vector<pair<double, string>>> G;
        for (int i = 0; i < m; i++)
        {
            string from, to;
            double val;
            cin >> from >> val >> to;
            G[from].emplace_back(val, std::move(to));
        }

        set<string> vis;

        set<string> all_circle;
        vector<string> circle;

        auto dfs = [&](auto&& self, string const& u, double now, string const& start) -> bool
        {
            if (vis.count(u))
                return false;
            vis.emplace(u);
            for (auto const& [val, v] : G[u])
            {
                if (v == start)
                {
                    all_circle.insert(circle.begin(), circle.end());
                    all_circle.emplace(start);
                    if (now * val > 1.0)
                    {
                        return true;
                    }
                }
                else
                {
                    circle.emplace_back(v);
                    bool res = self(self, v, now * val, start);
                    if (res)
                    {
                        circle.emplace_back(start);
                        return true;
                    }
                    circle.pop_back();
                }
            }
            return false;
        };

        bool flag = 0;
        for (auto const& [u, vec] : G)
        {
            if (all_circle.count(u))
                continue;
            vis.clear();
            bool res = dfs(dfs, u, 1, u);
            if (res)
            {
                flag = 1;
                break;
            }
        }

        cout << (flag ? "Yes" : "No") << '\n';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
