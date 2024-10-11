// 2024/10/09 16:26:27
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
        map<string, int> mp;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            mp[s] = i;
        }

        int m;
        cin >> m;
        vector<vector<double>> dis(n, vector<double>(n));
        for (int i = 0; i < n; i++)
        {
            dis[i][i] = 1.0;
        }
        for (int i = 0; i < m; i++)
        {
            string from, to;
            double val;
            cin >> from >> val >> to;
            dis[mp[from]][mp[to]] = val;
        }

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (dis[i][j] < dis[i][k] * dis[k][j])
                    {
                        dis[i][j] = dis[i][k] * dis[k][j];
                    }
                }
            }
        }

        bool flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (dis[i][i] > 1.0)
            {
                flag = 1;
            }
        }

        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         cerr << dis[i][j] << ' ' ;
        //     }
        //     cerr << '\n';
        // }

        cout << (flag ? "Yes" : "No") << '\n';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
