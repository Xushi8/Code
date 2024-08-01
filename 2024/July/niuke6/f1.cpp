#include <bits/stdc++.h>
const int N = 5e5;

int n, m;
std::vector<int> to[N + 5];
int du[N + 5];
bool vs[N + 5], uz[N + 5];
std::set<std::pair<int, int>> se;
int tk[N + 5], tp;

inline void solve()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        to[x].push_back(y), to[y].push_back(x);
        ++du[x], ++du[y];
    }
    for (int i = 1; i <= n; ++i)
        se.insert(std::make_pair(-du[i], i));
    int x = se.begin()->second;
    uz[x] = 1;
    tk[++tp] = x;
    se.erase(se.begin());
    for (int i = 2; i <= n; ++i)
    {
        int cx = x;
        for (int y : to[x])
            if (!uz[y])
            {
                se.erase(std::make_pair(-du[y], y));
                --du[y], vs[y] = 1;
                se.insert(std::make_pair(-du[y], y));
            }
        for (auto pa : se)
        {
            int y = pa.second;
            if (!vs[y])
            {
                x = y;
                uz[x] = 1;
                tk[++tp] = x;
                se.erase(pa);
                break;
            }
        }
        if (tp != i)
        {
            puts("-1");
            return;
        }
        for (int y : to[cx])
            if (!uz[y]) vs[y] = 0;
    }
    for (int i = 1; i <= n; ++i)
        printf("%d ", tk[i]);
    puts("");
}
inline void clear()
{
    for (int i = 1; i <= n; ++i)
        to[i].clear();
    std::fill(du + 1, du + n + 1, 0);
    std::fill(vs + 1, vs + n + 1, 0), std::fill(uz + 1, uz + n + 1, 0);
    se.clear();
    tp = 0;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        solve();
        clear();
    }
    return 0;
}