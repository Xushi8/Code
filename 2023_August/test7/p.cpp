// 2023/08/07 20:04:55
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

int n, m, R, mod;
int arr[N], son[N], siz[N], top[N], dfn[N], rev[N], deep[N], par[N], tmp[N];
ll d[4 * N];
int maxn[4 * N];
int tim;
vector<int> G[N];

void build(int l, int r, int p)
{
    if (l == r)
    {
        d[p] = tmp[l];
        maxn[p] = tmp[l];
        return;
    }


    int mid = l + (r - l) / 2;
    build(l, mid, p * 2);
    build(mid + 1, r, p * 2 + 1);
    d[p] = d[p * 2] + d[p * 2 + 1];
    maxn[p] = max(maxn[p * 2], maxn[p * 2 + 1]);
}

void modify(int pos, int nl, int nr, int val, int p)
{
    if (pos == nl && pos == nr)
    {
        d[p] = val;
        maxn[p] = val;
        return;
    }

    int mid = nl + (nr - nl) / 2;

    if (pos <= mid)
        modify(pos, nl, mid, val, p * 2);
    if (mid + 1 <= pos)
        modify(pos, mid + 1, nr, val, p * 2 + 1);

    d[p] = d[p * 2] + d[p * 2 + 1];
    maxn[p] = max(maxn[p * 2], maxn[p * 2 + 1]);
}

ll query_sum(int l, int r, int nl, int nr, int p)
{
    if (l <= nl && nr <= r)
    {
        return d[p];
    }

    int mid = nl + (nr - nl) / 2;

    ll sum = 0;
    if (l <= mid)
        sum += query_sum(l, r, nl, mid, p * 2);
    if (mid + 1 <= r)
        sum += query_sum(l, r, mid + 1, nr, p * 2 + 1);

    return sum;
}

int query_max(int l, int r, int nl, int nr, int p)
{
    if (l <= nl && nr <= r)
    {
        return maxn[p];
    }

    int mid = nl + (nr - nl) / 2;

    int maxx = -INF;
    if (l <= mid)
        maxx = max(maxx, query_max(l, r, nl, mid, p * 2));
    if (mid + 1 <= r)
        maxx = max(maxx, query_max(l, r, mid + 1, r, p * 2 + 1));

    return maxx;
}

void dfs1(int u, int from)
{
    deep[u] = deep[from] + 1;
    siz[u] = 1;
    par[u] = from;
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
    tim++;
    dfn[u] = tim;
    rev[tim] = u;
    if (son[u] == 0)
        return;

    dfs2(son[u], tp); // 重儿子
    for (int v : G[u])
    {
        if (v == son[u] || v == par[u])
            continue;

        dfs2(v, v); // 轻儿子
    }
}

void change(int x, int val)
{
    modify(dfn[x], 1, n, val, 1);
}

ll query_sum(int x, int y)
{
    ll res = 0;
    while (top[x] != top[y])
    {
        if (deep[top[x]] < deep[top[y]])
            swap(x, y);

        res += query_sum(dfn[top[x]], dfn[x], 1, n, 1);
        x = par[top[x]];
    }
    if (dfn[x] > dfn[y])
        swap(x, y);

    res += query_sum(dfn[x], dfn[y], 1, n, 1);
    return res;
}

int query_max(int x, int y)
{
    int res = -INF;
    while (top[x] != top[y])
    {
        if (deep[top[x]] < deep[top[y]])
            swap(x, y);

        res = max(res, query_max(dfn[top[x]], dfn[x], 1, n, 1));
        x = par[top[x]];
    }

    if (dfn[x] > dfn[y])
        swap(x, y);

    return max(res, query_max(dfn[x], dfn[y], 1, n, 1));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }


    dfs1(R, 0);
    dfs2(R, R);
    for (int i = 1; i <= n; i++)
    {
        tmp[dfn[i]] = arr[i];
    }
    memset(maxn, -0x3f, sizeof(maxn));
    build(1, n, 1);

    cin >> m;
    while (m--)
    {
        string op;
        cin >> op;
        if (op == "QMAX")
        {
            int x, y;
            cin >> x >> y;
            cout << query_sum(x, y) << '\n';
        }
        else if (op == "QSUM")
        {
            int x, y;
            cin >> x >> y;
            cout << query_max(x, y) << '\n';
        }
        else if (op == "CHANGE")
        {
            int x, val;
            cin >> x >> val;
            change(x, val);
        }
    }



#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}