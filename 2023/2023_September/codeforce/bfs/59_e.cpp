// 2023/09/21 11:12:54
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
constexpr int N = 3005;

vector<int> G[N];
int par[N][N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    set<array<int, 3>> jin;
    for (int i = 0; i < k; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--; c--;
        jin.insert({ a, b, c });
    }
    queue<pii> que;
    que.emplace(0, 0);
    pii ans = { -1, -1 };
    memset(par, -1, sizeof(par));
    while (!que.empty())
    {
        auto [u, v] = que.front(); que.pop();
        if (v == n - 1)
        {
            ans = { u, v };
            break;
        }

        for (int to : G[v])
        {
            if (par[v][to] != -1 || jin.count({u, v, to}) == 1)
            {
                continue;
            }

            par[v][to] = u;
            que.emplace(v, to);
        }
    }

    if (ans.first == -1)
    {
        cout << -1 << '\n';
    }
    else
    {
        vector<int> path;
        while (ans.second != 0)
        {
            path.emplace_back(ans.second);
            ans = { par[ans.first][ans.second], ans.first };
        }

        cout << path.size() << '\n';
        path.emplace_back(0);
        reverse(path.begin(), path.end());
        for (int x : path)
        {
            cout << x + 1 << ' ';
        }
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}