// 2023/11/07 17:29:56
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
#include <fstream>
#include <bitset>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 505;

int n, m, c1, c2;

vector<pii> G[N];

int dis[N];

int num[N];
int path;
int maxn;

void dfs(int u, int par, int len, int team)
{
    if (len > dis[u])
    {
        return;
    }

    if (u == c2)
    {
        if (len == dis[c2])
        {
            path++;
            if (team > maxn)
            {
                maxn = team;
            }
        }
        else
        {
            dis[c2] = len;
            path = 1;
            maxn = team;
        }
    }
    else
    {
        if (len < dis[u])
        {
            dis[u] = len;
        }

        for (auto [v, w] : G[u])
        {
            if (v != par)
                dfs(v, u, len + w, team + num[v]);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> c1 >> c2;
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }

    dis[c1] = 0;
    dfs(c1, -1, 0, num[c1]);

    cout << path << ' ' << maxn;

#ifdef LOCAL
    cerr
        << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}