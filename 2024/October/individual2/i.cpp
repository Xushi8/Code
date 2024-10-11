// 2024/10/09 14:36:24
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    while (cin >> n >> m && n != 0)
    {
        vector<int> deg(n);
        init(n);
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            deg[u]++;
            deg[v]++;
            unite(u, v);
        }

        int cnt = 0;
        set<int> st;
        for (int i = 0; i < n; i++)
        {
            if (deg[i] % 2 == 1)
                cnt++;
            st.emplace(find(i));
        }

        cout << (cnt == 0 && st.size() == 1) << '\n';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
