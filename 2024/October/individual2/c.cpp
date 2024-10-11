// 2024/10/09 15:19:39
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
    init(4 * n);
    for (int i = 0; i < n; i++)
    {
        int a1, a2, c1, c2;
        cin >> a1 >> a2 >> c1 >> c2;
        
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
