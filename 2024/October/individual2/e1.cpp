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
        vector<string> a;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            a.emplace_back(std::move(s));
        }

        int m;
        cin >> m;
        map<string, map<string, double>> dis;
        for (int i = 0; i < m; i++)
        {
            string from, to;
            double val;
            cin >> from >> val >> to;
            dis[from].try_emplace(std::move(to), val);
        }

        for (int i = 0; i < n; i++)
        {
            dis[a[i]][a[i]] = 1;
        }
        
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (i == j && j == k)
                        continue;
                    auto const& si = a[i], sj = a[j], sk = a[k];
                    if (dis[si][sj] < dis[si][sk] * dis[sk][sj])
                    {
                        dis[si][sj] = dis[si][sk] * dis[sk][sj];
                    }
                }
            }
        }

        bool flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (dis[a[i]][a[i]] > 1.0)
                flag = 1;
            // cerr << dis[a[i]][a[i]] << ' ';
        }

        cout << (flag ? "Yes" : "No") << '\n';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
