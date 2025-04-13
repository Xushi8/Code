// 2025/04/13 19:43:09
#ifdef LOCAL
#include <basic_std_lib.h>

#include <algorithm>
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
    vector<int> gen(n);
    constexpr int inf = 0x3f3f3f3f;
    vector<vector<int>> dis(n, vector<int>(n, inf));
    for (int i = 0; i < n; i++)
    {
        dis[i][i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        char op;
        int k;
        cin >> op >> k;
        gen[i] = (op == 'M');
        for (int j = 0; j < k; j++)
        {
            int v, w;
            char ch;
            cin >> v >> ch >> w;
            v--;
            int u = i;
            dis[u][v] = w;
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cerr << dis[i][j] << ' ';
    //     }
    //     cerr << '\n';
    // }
    // cerr << '\n';

    map<int, vector<int>> ans[2];
    for (int i = 0; i < n; i++)
    {
        int maxx = 0;
        for (int j = 0; j < n; j++)
        {
            if (gen[i] != gen[j])
            {
                maxx = max(maxx, dis[j][i]);
            }
        }

        ans[gen[i]][maxx].emplace_back(i);
    }

    auto const& ans1 = ans[0].begin()->second;
    auto const& ans2 = ans[1].begin()->second;

    for (size_t i = 0; i < ans1.size(); i++)
    {
        if (i != 0)
        {
            cout << ' ' ;
        }
        cout << ans1[i] + 1;
    }
    cout << '\n';
    for (size_t i = 0; i < ans2.size(); i++)
    {
        if (i != 0)
        {
            cout << ' ';
        }
        cout << ans2[i] + 1;
    }
    cout << '\n';
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
