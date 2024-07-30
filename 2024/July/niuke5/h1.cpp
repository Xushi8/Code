// 2024/07/30 16:42:14
#ifdef LOCAL
#include <basic_std_lib.h>
#else
#include <bits/stdc++.h>
#endif
using namespace std;


void solve();

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

using i64 = int64_t;
using u64 = uint64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 1000005;

int par[N], dep[N];

void init(int n)
{
    iota(par, par + n, 0);
    fill(dep, dep + n, 0);
}

int find(int x)
{
    if (x == par[x])
    {
        dep[x] = 0;
        return x;
    }
    
    dep[x] = 1 + dep[par[x]];
    int t = find(par[x]);
    return par[x] = t;
}

void unite(int x, int y)
{
    int t1 = find(x);
    int t2 = find(y);
    par[t1] = t2;
    par[x] = t2;
    dep[t1] += 1 + dep[t2];
    dep[x] += dep[t2] + 1;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n + 1);
    init(n + 1);
    set<pii> st;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        if (u > v)
            swap(u, v);
        if (u == v || st.count({u, v}))
            continue;
        st.emplace(u, v);
        G[u].emplace_back(v);
        G[v].emplace_back(u);

        unite(u, v);
    }

    vector<int> tmp;
    for (int i = 1; i <= n; i++)
    {
        if (find(i) != i)
        {
            tmp.emplace_back(dep[i]);
        }

        cerr << i << ' ' << find(i) << ' ' << dep[i] << '\n';
    }
    sort(tmp.begin(), tmp.end(), greater<>());
    cout << tmp[0] + tmp[1] + 1 << '\n';
}