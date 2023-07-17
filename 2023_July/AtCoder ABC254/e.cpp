// 2023/07/13 22:51:58
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
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const int N = 1000005;

int vis[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    int tt;
    cin >> tt;
    while (tt--)
    {
        int begin, k;
        cin >> begin >> k;
        ull ans = 0;
        vis[begin] = tt;
        queue<pii> que;
        que.emplace(begin, 0);
        while (!que.empty())
        {
            auto [u, dis] = que.front(); que.pop();
            ans += u;
            for (size_t i = 0; i < G[u].size(); i++)
            {
                int v = G[u][i];
                if (vis[v] != tt && dis + 1 <= k)
                {
                    vis[v] = tt;
                    que.emplace(v, dis + 1);
                }
            }
        }

        cout << ans << '\n';
    }


    cout << endl;
    return 0;
}