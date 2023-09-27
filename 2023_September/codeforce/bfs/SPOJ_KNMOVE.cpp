// // 2023/09/26 20:34:11
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
// #include <fstream>
// using namespace std;

// using ll = long long;
// using pii = pair<int, int>;
// constexpr int N = 1000005;

// int dx[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
// int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

// constexpr int n = 1000, m = 1000;
// int dis[n][m];

// void solve()
// {
//     memset(dis, -1, sizeof(dis));
//     queue<pii> que;
//     que.emplace(0, 0);
//     dis[0][0] = 0;
//     while (!que.empty())
//     {
//         pii p = que.front(); que.pop();
//         int x = p.first, y = p.second;
//         for (int i = 0; i < 8; i++)
//         {
//             int tx = x + dx[i];
//             int ty = y + dy[i];
//             if (0 <= tx && tx < n && 0 <= ty && ty < m && dis[tx][ty] == -1)
//             {
//                 dis[tx][ty] = dis[x][y] + 1;
//                 que.emplace(tx, ty);
//             }
//         }
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);


//     solve();
//     int tt;
//     cin >> tt;
//     while (tt--)
//     {
//         int a, b;
//         cin >> a >> b;
//         a--; b--;
//         cout << dis[a][b] << '\n';
//     }

// #ifdef LOCAL
//     cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
// #endif
//     cout << endl;
//     return 0;
// }


// 2023/09/26 22:55:34
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
constexpr int N = 1005;

int dis[N][N];
bool vis[N][N];

int dx[] = { -1, 1, -1, 1, -2, -2, 2, 2 };
int dy[] = { 2, 2, -2, -2, 1, -1, 1, -1 };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    queue<pii> que;
    que.emplace(1, 1);
    dis[1][1] = 0;
    vis[1][1] = 1;
    while (!que.empty())
    {
        pii p = que.front(); que.pop();
        int x = p.first, y = p.second;
        for (int i = 0; i < 8; i++)
        {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if (1 <= tx && tx <= 1000 && 1 <= ty && ty <= 1000 && !vis[tx][ty])
            {
                vis[tx][ty] = 1;
                dis[tx][ty] = dis[x][y] + 1;
                que.emplace(tx, ty);
            }
        }
    }

    int tt;
    cin >> tt;
    while (tt--)
    {
        int a, b;
        cin >> a >> b;
        cout << dis[a][b] << '\n';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}