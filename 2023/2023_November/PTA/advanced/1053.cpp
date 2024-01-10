// // 2023/11/15 11:31:44
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
// #include <bitset>
// using namespace std;

// using ll = long long;
// using pii = pair<int, int>;
// constexpr int N = 1005;

// vector<vector<int>> ans;
// int w[N];
// vector<int> G[N];
// vector<int> path;
// int n, m, k;

// void dfs(int u, int par, int sum)
// {
//     sum += w[u];
//     path.emplace_back(w[u]);

//     for (int v : G[u])
//     {
//         if (v == par)
//         {
//             continue;
//         }

//         dfs(v, u, sum);
//     }

//     if (G[u].size() == 1)
//     {
//         if (sum == k)
//         {
//             ans.emplace_back(path);
//         }
//     }

//     path.pop_back();
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     cin >> n >> m >> k;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> w[i];
//     }

//     for (int i = 0; i < m; i++)
//     {
//         int id;
//         cin >> id;
//         int x;
//         cin >> x;
//         for (int j = 0; j < x; j++)
//         {
//             int y;
//             cin >> y;
//             G[id].emplace_back(y);
//             G[y].emplace_back(id);
//         }
//     }

//     dfs(0, -1, 0);

//     sort(ans.begin(), ans.end(), greater<>());
//     for (auto const& x : ans)
//     {
//         for (size_t i = 0; i < x.size(); i++)
//         {
//             cout << x[i] << " \n"[i == x.size() - 1];
//         }
//     }

// #ifdef LOCAL
//     cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
// #endif
//     cout << flush;
//     return 0;
// }

// 2023/11/15 11:50:37
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
constexpr int N = 1000005;

int n, m, k;
int w[N];
vector<int> G[N];
vector<int> path;
vector<vector<int>> ans;

void dfs(int u, int sum)
{
    sum += w[u];
    path.emplace_back(w[u]);
    for (int v : G[u])
    {
        dfs(v, sum);
    }

    if (G[u].size() == 0 && sum == k)
    {
        ans.emplace_back(path);
    }

    path.pop_back();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    for (int i = 0; i < m; i++)
    {
        int id;
        cin >> id;
        int cnt;
        cin >> cnt;
        for (int j = 0; j < cnt; j++)
        {
            int x;
            cin >> x;
            G[id].emplace_back(x);
        }
    }

    dfs(0, 0);
    sort(ans.begin(), ans.end(), greater<>());
    for (auto const& arr : ans)
    {
        for (size_t i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << " \n"[i == arr.size() - 1];
        }
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}