// 2024/10/09 13:26:16
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

int par[N];
int siz[N];
void init(int n)
{
    iota(par, par + n, 0);
    fill(siz, siz + n, 1);
}

int find(int x)
{
    if (x == par[x])
        return x;
    else
    {
        int p = find(par[x]);
        siz[p] += siz[x];
        siz[x] = 0;
        par[x] = p;
        return p;
    }
}

pii unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return {};
    par[x] = y;
    pii res = {siz[x], siz[y]};
    siz[y] += siz[x];
    siz[x] = 0;
    return res;
}

bool same(int x, int y)
{
    return find(x) == find(y);
}

void solve()
{
    int n, m;
    cin >> n >> m;
    init(n);
    vector<pii> edges(m);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--; v--;
        edges[i] = {u, v};
    }
    reverse(edges.begin(), edges.end());

    vector<i64> ans;
    ans.emplace_back(i64(n) * (n - 1) / 2);
    for (auto [u, v] : edges)
    {
        // for (int i = 0; i < n; i++)
        // {
        //     cerr << siz[i] << ' ' ;
        // }
        // cerr << '\n';


        auto [sizx, sizy] = unite(u, v);
        ans.emplace_back(ans.back() - i64(sizx) * sizy);
    }
    ans.pop_back();

    reverse(ans.begin(), ans.end());
    for (auto x : ans)
    {
        cout << x << '\n';
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
