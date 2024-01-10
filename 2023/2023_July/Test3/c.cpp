// 2023/07/26 09:22:37
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
const int N = 200005;

int arr[N];

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tt;
    cin >> tt;
    while (tt--)
    {


        solve();

        
        // int n, m;
        // cin >> n >> m;
        // vector<pii> swap_index;
        // vector<pii> equal_index;
        // bool flag = 1;
        // int need_swap = 0;
        // int t = n;
        // while (t--)
        // {
        //     for (int i = 1; i <= m; i++)
        //         cin >> arr[i];

        //     if (!flag)
        //         continue;

        //     for (int i = 2; i <= m - 1; i++)
        //     {
        //         int j = i + 1;
        //         while (j <= m - 1 && arr[j] == arr[i])
        //         {
        //             j++;
        //         }
        //         j--;

        //         if (arr[i] > arr[i - 1] && arr[j] > arr[j + 1])
        //         {
        //             flag = 0;
        //             break;
        //         }
        //     }

        //     if (!flag)
        //         continue;

        //     for (int i = 1; i <= m; i++)
        //     {
        //         int j = i + 1;
        //         while (j <= m && arr[j] == arr[i])
        //         {
        //             j++;
        //         }
        //         if (j != i + 1)
        //         {
        //             equal_index.emplace_back(i, j - 1);
        //             i = j - 1;
        //         }

        //         if (j <= m && arr[j] < arr[i])
        //         {
        //             int cnt = 0;
        //             need_swap++;
        //             while (j <= m && arr[j] < arr[i])
        //             {
        //                 if(arr[j] != arr[j - 1])
        //                     cnt++;
        //                 j++;
        //             }
        //             if (cnt > 2)
        //             {
        //                 flag = 0;
        //                 break;
        //             }

        //             pii p;
        //             p.first = i;
        //             p.second = j - 1;

        //             if (swap_index.empty())
        //             {
        //                 swap_index.emplace_back(p);
        //             }
        //             else
        //             {
        //                 if (p != swap_index.front())
        //                 {
        //                     flag = 0;
        //                     break;
        //                 }
        //             }

        //             i = j - 1;
        //         }
        //     }
        // }

        // if (!equal_index.empty() && !swap_index.empty())
        // {
        //     for (size_t i = 0; i < equal_index.size(); i++)
        //     {
        //         auto [x, y] = equal_index[i];
        //         if (x <= swap_index.front().first &&
        //             swap_index.front().second <= y)
        //             need_swap++;
        //     }
        // }

        // if (!flag)
        //     ::cout << -1 << '\n';
        // else
        // {
        //     if (swap_index.empty())
        //         ::cout << 1 << ' ' << 1 << '\n';
        //     else if (need_swap != n)
        //     {
        //         ::cout << -1 << '\n';
        //     }
        //     else
        //         ::cout << swap_index.front().first << ' ' << swap_index.front().second << '\n';
        // }

        // bool flag = 1;
        // // int a = -1, b = -1;
        // // for (size_t i = 0; i < swap_index.size(); i++)
        // // {
        // //     if (a == -1)
        // //         a = swap_index[i];
        // //     else if (a != swap_index[i])
        // //     {
        // //         if (b == -1)
        // //         {
        // //             b = swap_index[i];
        // //         }
        // //         else if (b != swap_index[i])
        // //         {
        // //             flag = 0;
        // //             break;
        // //         }
        // //     }
        // // }

        // int cnt = count(arr, arr + m, arr[0]);
        // if (cnt == m)
        // {
            
        // }
        // else
        // {
        //     cout << -1 << '\n';
        // }

        // // if (!flag)
        // // {
        // //     cout << -1 << '\n';
        // // }
        // // else
        // // {
        // //     if (b == -1)
        // //         cout << a + 1 << ' ' << a + 1 << '\n';
        // //     else
        // //         cout << a + 1 << ' ' << b + 1 << '\n';
        // // }
    }

    ::cout << endl;
    return 0;
}