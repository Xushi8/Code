// 2023/09/24 19:38:52
#pragma GCC optimize(3)
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

vector<int> solve()
{
    int n;
    cin >> n;
    vector<vector<int>> arr(n);
    for (int i = 0; i < n - 1; i++)
    {
        int m;
        cin >> m;
        for (int j = 0, x; j < m; j++)
        {
            cin >> x;
            x--;
            arr[i].emplace_back(x);
        }
        sort(arr[i].begin(), arr[i].end());
    }
    vector<bool> vis(n, 0);
    vis[0] = 1;
    vector<int> par(n, -1);
    queue<int> que;
    que.emplace(0);
    while (!que.empty())
    {
        int u = que.front(); que.pop();
        for (int v : arr[u])
        {
            if (vis[v])
                continue;
            que.emplace(v);
            vis[v] = 1;
            par[v] = u;
            if (v == n - 1)
            {
                vector<int> res;
                while (par[u] != -1)
                {
                    res.emplace_back(u);
                    u = par[u];
                }
                res.emplace_back(0);
                reverse(res.begin(), res.end());
                return res;
            }
        }
    }

    return vector<int>();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tt;
    cin >> tt;
    while (tt--)
    {
        auto ans = solve();
        if (ans.size() == 0)
            cout << "-1\n";
        else
        {
            cout << ans.size() << '\n';
            for (int x : ans)
            {
                cout << x + 1 << ' ';
            }
            cout << '\n';
        }
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}