// // 2023/09/03 16:24:04
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
// #include <array>
// using namespace std;

// using ll = long long;
// using pii = pair<int, int>;
// constexpr int N = 1000005;

// int n, m, q;

// struct edge
// {
//     edge(int a, int b, int c, int index_, bool flag_ = false)
//     {
//         u = a;
//         v = b;
//         w = c;
//         index = index_;
//         flag = flag_;
//     }
//     int u, v, w, index;
//     bool flag;
// };

// bool cmp(const edge& a, const edge& b)
// {
//     return a.w < b.w;
// }

// bool cmp1(const edge& a, const edge& b)
// {
//     return a.index < b.index;
// }

// int par[N];

// void init()
// {
//     for (int i = 0; i < n; i++)
//     {
//         par[i] = i;
//     }
// }

// int find(int x)
// {
//     if (par[x] == x)
//         return x;
//     else
//         return par[x] = find(par[x]);
// }

// bool same(int x, int y)
// {
//     return find(x) == find(y);
// }

// void unite(int x, int y)
// {
//     x = find(x);
//     y = find(y);
//     if (x == y)
//         return;

//     par[x] = y;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     cin >> n >> m >> q;
//     vector<edge> G;
//     for (int i = 0; i < m; i++)
//     {
//         int u, v, w;
//         cin >> u >> v >> w;
//         u--; v--;
//         G.emplace_back(u, v, w, i);
//     }
//     sort(G.begin(), G.end(), cmp);

//     vector<edge> tmp;
//     for (int i = 0; i < q; i++)
//     {
//         int u, v, w;
//         cin >> u >> v >> w;
//         u--; v--;
//         tmp.emplace_back(u, v, w, i);
//     }
//     sort(tmp.begin(), tmp.end(), cmp);

//     init();
//     int tot = 0;
//     for (int i = 0; i < q; i++)
//     {
//         edge& e = tmp[i];
//         while (tot < m && G[tot].w < e.w)
//         {
//             unite(G[tot].u, G[tot].v);
//             tot++;
//         }

//         e.flag = !same(e.u, e.v);
//     }

//     sort(tmp.begin(), tmp.end(), cmp1);
//     for (int i = 0; i < q; i++)
//     {
//         cout << (tmp[i].flag ? "Yes\n" : "No\n");
//     }

// #ifdef LOCAL
//     cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
// #endif
//     cout << endl;
//     return 0;
// }

// 2023/09/03 16:51:58
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
#include <array>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 1000005;


int par[N];
int n, m, q;

void init()
{
    for (int i = 0; i < n; i++)
    {
        par[i] = i;
    }
}

int find(int x)
{
    if (par[x] == x)
        return x;
    else
        return par[x] = find(par[x]);
}

bool same(int x, int y)
{
    return find(x) == find(y);
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return;

    par[x] = y;
}

struct edge
{
    int u, v, w, index;
};

bool cmp(const edge& a, const edge& b)
{
    return a.w < b.w;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> q;
    vector<edge> g(m);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        g[i] = { u, v, w, i };
    }
    sort(g.begin(), g.end(), cmp);

    vector<edge> tmp(q);
    for (int i = 0; i < q; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        tmp[i] = { u, v, w, i };
    }
    sort(tmp.begin(), tmp.end(), cmp);

    vector<bool> ans(q);
    int tot = 0;
    init();
    for (auto [u, v, w, index] : tmp)
    {
        while (tot < m && g[tot].w < w)
        {
            unite(g[tot].u, g[tot].v);
            tot++;
        }

        ans[index] = !same(u, v);

        // cerr << index << '\n';
    }

    for (bool flag : ans)
    {
        cout << (flag ? "Yes\n" : "No\n");
    }


#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}

