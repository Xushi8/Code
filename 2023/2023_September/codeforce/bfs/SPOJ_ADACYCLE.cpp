// 2023/09/23 23:33:27
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
constexpr int N = 20005;

vector<int> G[N];
bool vis[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] != 0)
            {
                G[i].emplace_back(j);
            }
        }
    }
    
    constexpr int INF = 0x3f3f3f3f;

    auto bfs = [&](int begin) -> int
        {
            queue<pii> que;
            que.emplace(0, begin);
            while (!que.empty())
            {
                auto [dis, u] = que.front(); que.pop();
                for (int v : G[u])
                {
                    if(!vis[v])
                    {
                        vis[v] = 1;
                        if (v == begin)
                            return dis + 1;
                        que.emplace(dis + 1, v);
                    }
                }
            }

            return INF;
        };

    for (int i = 0; i < n; i++)
    {
        int ans = INF;
        if (!G[i].empty())
        {
            memset(vis, 0, sizeof(vis));
            ans = bfs(i);
        }

        if (ans == INF)
            cout << "NO WAY\n";
        else
            cout << ans << '\n';
    }

    

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}