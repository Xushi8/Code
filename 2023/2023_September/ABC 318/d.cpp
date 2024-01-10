// // 2023/09/02 21:12:03
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
// constexpr int N = 20;

// bool vis[N];
// ll arr[N][N];

// ll ans;
// int n;

// void dfs(int u, int del, ll now)
// {
//     vis[u] = 1;
//     for (int v = u + 1; v < n; v++)
//     {
//         if (vis[v] || v == del)
//             continue;

//         vis[v] = 1;
//         ans = max(ans, now + arr[u][v]);
//         for (int i = u; i < n; i++)
//         {
//             if (!vis[i] && i != del)
//             {
//                 dfs(i, del, now + arr[u][v]);
//                 vis[i] = 0;
//             }
//         }
//         vis[v] = 0;
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             cin >> arr[i][j];
//             arr[j][i] = arr[i][j];
//         }
//     }

//     if (n & 1)
//     {
//         dfs(1, 0, 0);
//         for (int i = 1; i < n; i++)
//         {
//             memset(vis, 0, sizeof(vis));
//             dfs(0, i, 0);
//         }
//     }
//     else
//     {
//         dfs(0, -1, 0);
//     }

//     cout << ans << '\n';

// #ifdef LOCAL
//     cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
// #endif
//     cout << endl;
//     return 0;
// }


// 2023/09/03 10:54:51
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
constexpr int N = 20;

bool vis[N];

void dfs(int now)
{
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}