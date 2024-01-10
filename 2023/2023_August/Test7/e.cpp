// // 2023/08/09 10:19:02
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <cstdint>
// #include <vector>
// #include <string>
// #include <set>
// #include <map>
// #include <unordered_map>
// #include <unordered_set>
// #include <queue>
// #include <functional>
// #include <iomanip>
// #include <cmath>
// #include <stack>
// using namespace std;

// using ll = long long;
// using ull = unsigned long long;
// using pii = pair<int, int>;
// const int INF = 0x3f3f3f3f;
// const int MOD = (int)(1e9 + 7);
// const int N = 100005;


// int n;
// int maxn[N], arr[N];

// int deep[N], siz[N], par[N], dfn[N], son[N], top[N], rev[N];
// int tim;

// struct edge
// {
//     int u, v, cost;
// };
// vector<edge> G[N];

// void dfs1(int u, int from, int cost);

// void dfs2(int u, int tp);

// void build(int l, int r, int p);

// void modify(int l, int r, int nl, int nr, int val, int p);

// int query(int l, int r, int nl, int nr, int p);

// int query(int x, int y);

// void change(int x, int y, int val);

// edge edges[N];

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     cin >> n;
//     for (int i = 1; i <= n - 1; i++)
//     {
//         edge e;
//         cin >> e.u >> e.v >> e.cost;
//         edges[i] = e;
//         G[e.u].emplace_back(e);
//         edge tmp = e;
//         swap(tmp.u, tmp.v);
//         G[e.u].emplace_back(tmp);
//     }

//     dfs1(1, 0, 0);
//     dfs2(1, 1);

    

//     build(1, n, 1);

//     string s;
//     while (cin >> s && s != "DONE")
//     {
//         if (s == "CHANGE")
//         {
//             int x, t;
//             cin >> x >> t;
//             change(edges[x].u, edges[x].v, t);
//         }
//         else
//         {
//             int x, y;
//             cin >> x >> y;
//             cout << query(x, y) << '\n';
//         }
//     }

// #ifdef LOCAL
//     cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
// #endif
//     cout << endl;
//     return 0;
// }




// void dfs1(int u, int from, int cost)
// {
//     deep[u] = deep[from] + 1;
//     siz[u] = 1;
//     par[u] = from;
//     val[u] = cost;
//     for (auto v : G[u])
//     {
//         if (v.v == par[u])
//             continue;

//         dfs1(v.v, u);
//         siz[u] += siz[v.v];
//         if (siz[son[u]] < siz[v.v])
//             son[u] = v.v;
//     }
// }


// void dfs2(int u, int tp)
// {
//     top[u] = tp;
//     dfn[u] = ++tim;
//     rev[tim] = u;
//     if (son[u] == 0)
//         return;

//     dfs2(son[u], tp);
//     for (auto v : G[u])
//     {
//         if (v.v == son[u] || v.v == par[u])
//             continue;

//         dfs2(v.v, v.v);
//     }
// }


// void build(int l, int r, int p)
// {
//     if (l == r)
//     {
//         maxn[p] = arr[l];
//         return;
//     }

//     int mid = l + (r - l) / 2;
//     build(l, mid, p * 2);
//     build(mid + 1, r, p * 2 + 1);

//     maxn[p] = max(maxn[p * 2], maxn[p * 2 + 1]);
// }


// int query(int l, int r, int nl, int nr, int p)
// {
//     if (l <= nl && nr <= r)
//     {
//         return maxn[p];
//     }

//     int mid = nl + (nr - nl) / 2;
//     int res = 0;
//     if (l <= mid)
//         res = max(query(l, r, nl, mid, p * 2), res);
//     if (mid + 1 <= r)
//         res = max(query(l, r, mid + 1, nr, p * 2 + 1), res);

//     return res;
// }


// void modify(int l, int r, int nl, int nr, int val, int p)
// {
//     if (l <= nl && nr <= r)
//     {
//         maxn[p] = val;
//         return;
//     }

//     int mid = nl + (nr - nl) / 2;
//     if (l <= mid)
//         modify(l, r, nl, mid, val, p * 2);
//     if (mid + 1 <= r)
//         modify(l, r, mid + 1, nr, val, p * 2 + 1);

//     maxn[p] = max(maxn[p * 2], maxn[p * 2 + 1]);
// }


// int query(int x, int y)
// {
//     int res = 0;
//     while (top[x] != top[y])
//     {
//         if (deep[top[x]] < deep[top[y]])
//             swap(x, y);

//         res = max(res, query(dfn[top[x]], dfn[x], 1, n, 1));
//         x = par[top[x]];
//     }

//     if (dfn[x] > dfn[y])
//         swap(x, y);

//     return res = max(res, query(dfn[x] + 1, dfn[y], 1, n, 1));
// }


// void change(int x, int y, int val)
// {
//     while (top[x] != top[y])
//     {
//         if (deep[top[x]] < deep[top[y]])
//             swap(x, y);

//         modify(dfn[top[x]], dfn[x], 1, n, val, 1);
//         x = par[top[x]];
//     }

//     if (dfn[x] > dfn[y])
//         swap(x, y);

//     modify(dfn[x] + 1, dfn[y], 1, n, val, 1);
// }







// 2023/08/09 16:47:01
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

int dfn[N], son[N], par[N], siz[N], top[N], tim, deep[N], top[N], rk[N];
int arr[N], mx[N * 4];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;


#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}