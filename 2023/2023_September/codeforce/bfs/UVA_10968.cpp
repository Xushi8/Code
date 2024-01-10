// 2023/09/24 22:15:35
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
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 1000005;

vector<int> G[N];

void solve(int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        G[i].clear();
    }
    
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        if (u == 0 && v == 0)
            break;
        u--; v--;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    int s = -1, t = -1;
    for (int i = 0; i < n; i++)
    {
        if (G[i].size() == 0 || G[i].size() == 1)
        {
            cout << "Poor Koorosh" << endl;
            return;
        }
        if (G[i].size() & 1)
        {
            if (s == -1)
                s = i;
            else
                t = i;
        }
    }

    if (s == -1 && t == -1)
        cout << 0 << endl;
    else if (s != -1 && t == -1)
        cout << "Poor Koorosh" << endl;
    else
    {
        vector<int> par(n, -1);
        queue<pii> que;
        que.emplace(s, 0);
        while (!que.empty())
        {
            // auto [u, cost] = que.front(); que.pop();
            pii p = que.front(); que.pop();
            int u = p.first, cost = p.second;
            for (int v : G[u])
            {
                if (v == par[u] || G[v].size() == 2)
                    continue;
                par[v] = u;
                que.emplace(v, cost + 1);
                if (v == t)
                {
                    cout << cost + 1 << endl;
                    return;
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    while (cin >> n >> m && (n || m))
    {
        solve(n, m);
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}