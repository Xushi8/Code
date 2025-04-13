// 2025/04/13 19:34:51
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
    int n, q;
    cin >> n >> q;
    vector<vector<int>> G(n + 1);
    vector<int> par(n + 1);

    int root = -1;
    for (int i = 1; i <= n; i++)
    {
        int p;
        cin >> p;
        par[i] = p;
        if (p == -1)
        {
            root = i;
        }
        else
        {
            G[i].emplace_back(p);
            G[p].emplace_back(i);
        }
    }

    constexpr int inf = 0x3f3f3f3f;
    vector<int> dis(n + 1, inf);
    queue<int> que;
    que.emplace(root);
    dis[root] = 0;
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

    vector<int> vis(n + 1);
    i64 num = 0;
    int max_rev = 0;
    while (q--)
    {
        int nx;
        cin >> nx;
        max_rev = max(max_rev, dis[nx]);

        int new_from = nx;
        while (!vis[new_from])
        {
            vis[new_from] = 1;
            if (new_from == root)
            {
                break;
            }
            new_from = par[new_from];
        }

        num += dis[nx] - dis[new_from];
        cout << (num * 2) - max_rev << '\n';
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
