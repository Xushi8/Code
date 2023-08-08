// 2023/08/08 15:28:52
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdint>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <functional>
#include <iomanip>
#include <cmath>
#include <stack>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const int N = 100005;


int deep[N], top[N], siz[N], son[N], par[N], dfn[N], rev[N];
int tmp[N];
int tim;
vector<int> G[N];

int n, m, R;
int mod = 1;
ll d[4 * N], b[4 * N], k[4 * N];
int arr[N];
void build(int l, int r, int p)
{
    if (l == r)
    {
        d[p] = tmp[l];
        d[p] %= mod;
        return;
    }

    int mid = l + (r - l) / 2;
    build(l, mid, p * 2);
    build(mid + 1, r, p * 2 + 1);
    d[p] = d[p * 2] + d[p * 2 + 1];
    d[p] %= mod;
}

void mul_num(int l, int r, int nl, int nr, ll mul_val, int p)
{
    if (l <= nl && nr <= r)
    {
        d[p] *= mul_val;
        b[p] *= mul_val;
        k[p] *= mul_val;

        d[p] %= mod;
        b[p] %= mod;
        k[p] %= mod;
        return;
    }

    int mid = nl + (nr - nl) / 2;
    if (k[p] != 1)
    {
        d[p * 2] *= k[p];
        d[p * 2 + 1] *= k[p];
        b[p * 2] *= k[p];
        b[p * 2 + 1] *= k[p];
        k[p * 2] *= k[p];
        k[p * 2 + 1] *= k[p];

        d[p * 2] %= mod;
        d[p * 2 + 1] %= mod;
        b[p * 2] %= mod;
        b[p * 2 + 1] %= mod;
        k[p * 2] %= mod;
        k[p * 2 + 1] %= mod;

        k[p] = 1;
    }

    if (b[p] != 0)
    {
        d[p * 2] += b[p] * (mid - nl + 1);
        b[p * 2] += b[p];
        d[p * 2 + 1] += b[p] * (nr - (mid + 1) + 1);
        b[p * 2 + 1] += b[p];

        d[p * 2] %= mod;
        b[p * 2] %= mod;
        d[p * 2 + 1] %= mod;
        b[p * 2 + 1] %= mod;

        b[p] = 0;
    }

    if (l <= mid)
        mul_num(l, r, nl, mid, mul_val, p * 2);
    if (mid + 1 <= r)
        mul_num(l, r, mid + 1, nr, mul_val, p * 2 + 1);

    d[p] = d[p * 2] + d[p * 2 + 1];
    d[p] %= mod;
}


void add_num(int l, int r, int nl, int nr, ll add_val, int p)
{
    if (l <= nl && nr <= r)
    {
        d[p] += add_val * (nr - nl + 1);
        b[p] += add_val;

        d[p] %= mod;
        b[p] %= mod;
        return;
    }

    int mid = nl + (nr - nl) / 2;
    if (k[p] != 1)
    {
        d[p * 2] *= k[p];
        d[p * 2 + 1] *= k[p];
        b[p * 2] *= k[p];
        b[p * 2 + 1] *= k[p];
        k[p * 2] *= k[p];
        k[p * 2 + 1] *= k[p];

        d[p * 2] %= mod;
        d[p * 2 + 1] %= mod;
        b[p * 2] %= mod;
        b[p * 2 + 1] %= mod;
        k[p * 2] %= mod;
        k[p * 2 + 1] %= mod;

        k[p] = 1;
    }

    if (b[p] != 0)
    {
        d[p * 2] += b[p] * (mid - nl + 1);
        b[p * 2] += b[p];
        d[p * 2 + 1] += b[p] * (nr - (mid + 1) + 1);
        b[p * 2 + 1] += b[p];

        d[p * 2] %= mod;
        b[p * 2] %= mod;
        d[p * 2 + 1] %= mod;
        b[p * 2 + 1] %= mod;

        b[p] = 0;
    }

    if (l <= mid)
        add_num(l, r, nl, mid, add_val, p * 2);
    if (mid + 1 <= r)
        add_num(l, r, mid + 1, nr, add_val, p * 2 + 1);

    d[p] = d[p * 2] + d[p * 2 + 1];
    d[p] %= mod;
}

ll query(int l, int r, int nl, int nr, int p)
{
    if (l <= nl && nr <= r)
    {
        return d[p];
    }

    int mid = nl + (nr - nl) / 2;
    if (k[p] != 1)
    {
        d[p * 2] *= k[p];
        d[p * 2 + 1] *= k[p];
        b[p * 2] *= k[p];
        b[p * 2 + 1] *= k[p];
        k[p * 2] *= k[p];
        k[p * 2 + 1] *= k[p];

        d[p * 2] %= mod;
        d[p * 2 + 1] %= mod;
        b[p * 2] %= mod;
        b[p * 2 + 1] %= mod;
        k[p * 2] %= mod;
        k[p * 2 + 1] %= mod;

        k[p] = 1;
    }

    if (b[p] != 0)
    {
        d[p * 2] += b[p] * (mid - nl + 1);
        b[p * 2] += b[p];
        d[p * 2 + 1] += b[p] * (nr - (mid + 1) + 1);
        b[p * 2 + 1] += b[p];

        d[p * 2] %= mod;
        b[p * 2] %= mod;
        d[p * 2 + 1] %= mod;
        b[p * 2 + 1] %= mod;

        b[p] = 0;
    }


    ll sum = 0;
    if (l <= mid)
    {
        sum += query(l, r, nl, mid, p * 2);
        sum %= mod;
    }
    if (mid + 1 <= r)
    {
        sum += query(l, r, mid + 1, nr, p * 2 + 1);
        sum %= mod;
    }

    return sum;
}


void dfs1(int u, int from)
{
    siz[u] = 1;
    par[u] = from;
    deep[u] = deep[from] + 1;
    for (int v : G[u])
    {
        if (v == from)
            continue;

        dfs1(v, u);
        siz[u] += siz[v];
        if (siz[son[u]] < siz[v])
            son[u] = v;
    }
}

void dfs2(int u, int tp)
{
    top[u] = tp;
    dfn[u] = ++tim;
    rev[tim] = u;
    if (son[u] == 0)
        return;

    dfs2(son[u], tp);
    for (int v : G[u])
    {
        if (v == par[u] || v == son[u])
            continue;

        dfs2(v, v);
    }
}

void change(int x, int y, ll add_val)
{
    while (top[x] != top[y])
    {
        if (deep[top[x]] < deep[top[y]])
            swap(x, y);

        add_num(dfn[top[x]], dfn[x], 1, n, add_val, 1);
        x = par[top[x]];
    }

    if (dfn[x] > dfn[y])
        swap(x, y);

    add_num(dfn[x], dfn[y], 1, n, add_val, 1);
}

ll query(int x, int y)
{
    ll res = 0;
    while (top[x] != top[y])
    {
        if (deep[top[x]] < deep[top[y]])
            swap(x, y);

        res += query(dfn[top[x]], dfn[x], 1, n, 1);
        res %= mod;
        x = par[top[x]];
    }

    if (dfn[x] > dfn[y])
        swap(x, y);

    res += query(dfn[x], dfn[y], 1, n, 1);
    return res % mod;
}

void change(int x, ll add_val)
{
    add_num(dfn[x], dfn[x] + siz[x] - 1, 1, n, add_val, 1);
}

ll query(int x)
{
    return query(dfn[x], dfn[x] + siz[x] - 1, 1, n, 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> R >> mod;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    dfs1(R, 0);
    dfs2(R, R);

    for (int i = 1; i <= n; i++)
    {
        tmp[dfn[i]] = arr[i];
    }
    build(1, n, 1);
    fill(k, k + 4 * N, 1);

    while (m--)
    {
        int op, l, r, val;
        cin >> op;
        if (op == 1)
        {
            cin >> l >> r >> val;
            change(l, r, val);
        }
        else if (op == 2)
        {
            cin >> l >> r;
            cout << query(l, r) << '\n';
        }
        else if (op == 3)
        {
            cin >> l >> val;
            change(l, val);
        }
        else if (op == 4)
        {
            cin >> l;
            cout << query(l) << '\n';
        }
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}