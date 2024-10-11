// 2024/10/11 14:20:22
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
    int n, m, k, s;
    cin >> n >> m >> k >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
    }
    constexpr int INF = 0x3f3f3f3f;
    vector<vector<int>> holds(n, vector<int>(k, INF));

    vector<vector<int>> G(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    auto bfs = [&](int goods)
    {
        vector<int> dis(n, INF);
        queue<int> que;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == goods)
            {
                que.emplace(i);
                dis[i] = 0;
            }
        }

        while (!que.empty())
        {
            auto u = que.front();
            que.pop();
            for (auto v : G[u])
            {
                if (dis[v] > dis[u] + 1)
                {
                    dis[v] = dis[u] + 1;
                    que.emplace(v);
                }
            }
        }

        // vector<int> q;
        // q.reserve(n);
        // for (int i = 0; i < n; i++)
        // {
        //     if (a[i] == goods)
        //     {
        //         q.emplace_back(i);
        //         dis[i] = 0;
        //     }
        // }

        // for (size_t i = 0; i < q.size(); i++)
        // {
        //     auto u = q[i];
        //     for (auto v : G[u])
        //     {
        //         if (dis[v] > dis[u] + 1)
        //         {
        //             dis[v] = dis[u] + 1;
        //             q.emplace_back(v);
        //         }
        //     }
        // }

        for (int i = 0; i < n; i++)
        {
            holds[i][goods] = dis[i];
        }
    };

    for (int i = 0; i < k; i++)
    {
        bfs(i);
    }

    for (int i = 0; i < n; i++)
    {
        auto& vec = holds[i];
        sort(vec.begin(), vec.end());
        cout << reduce(vec.begin(), vec.begin() + s) << ' ';
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
