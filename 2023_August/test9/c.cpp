// 2023/08/14 11:37:07
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
const int N = 1005;

int dis[N * 2];
vector<int> G[N * 2];
queue<int> que;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(dis, 0x3f, sizeof(dis));
    int n, m;
    cin >> n >> m;
    vector<string> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == '#')
            {
                G[i].emplace_back(n + j);
                G[n + 1].emplace_back(i);
            }
        }
    }

    dis[0] = 0;
    que.emplace(0);
    while (!que.empty())
    {
        int u = que.front(); que.pop();
        if (u == n - 1)
        {
            cout << dis[u] << endl;
            return 0;
        }

        for (int v : G[u])
        {
            if (dis[v] > dis[u] + 1)
            {
                dis[v] = dis[u] + 1;
                que.emplace(v);
            }
        }
    }

    cout << -1 << '\n';


    // for (int j = 0; j < m; j++)
    // {
    //     if (arr[0][j] == '#')
    //     {
    //         row[0] = 1;
    //         col[j] = 1;
    //     }
    // }

    // for (int i = 1; i < n; i++)
    // {
    //     int minn = INF;
    //     for (int j = 0; j < m; j++)
    //     {
    //         if (arr[i][j] == '#' && col[j] != 0 && col[j] != INF)
    //         {
    //             dis[i][j] = col[j] + 1;
    //             row[i] = 1;
    //             minn = min(minn, dis[i][j]);
    //         }
    //     }

    //     if (row[i] != 0 && row[i] != INF)
    //     {
    //         for (int j = 0; j < m; j++)
    //         {
    //             if (arr[i][j] == '#')
    //             {
    //                 dis[i][j] = min(dis[i][j], minn + 1);
    //                 col[j] = min(col[j], dis[i][j]);
    //             }
    //         }
    //     }
    // }

    

    // int minn = INF;
    // for (int j = 0; j < m; j++)
    // {
    //     minn = min(minn, dis[n - 1][j]);
    // }

    // if (minn == INF)
    //     cout << -1 << '\n';
    // else
    //     cout << minn << '\n';

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}