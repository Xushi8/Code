// 2024/10/16 16:44:35
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
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> RG(n);
    vector<int> in(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        RG[v].emplace_back(u, w);
        in[u]++;
    }

    queue<int> que;
    for (int i = 0; i < n; i++)
    {
        if (in[i] == 0)
        {
            que.emplace(i);
        }
    }

    vector<double> gailv(n, 1.);

    double ans = 0;
    while (!que.empty())
    {
        auto u = que.front();
        que.pop();
        for (auto [v, w] : RG[u])
        {
            if (--in[v] == 0)
            {
                que.emplace(v);
            }
            ans += gailv[u] * w / RG[u].size();
            gailv[v] /= RG[u].size();
        }
    }

    cout << setprecision(2) << fixed;
    cout << ans << '\n';
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
