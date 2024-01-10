// 2023/07/11 12:13:14
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

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int n, K;
//     cin >> n >> K;
//     vector<int> arr(n);
//     for (int i = 0; i < n; i++)
//         cin >> arr[i];

//     vector<vector<int>> ar(K);
//     for (int i = 0; i < n; i++)
//     {
//         ar[i % K].emplace_back(arr[i]);
//     }

//     for (int i = 0; i < K; i++)
//     {
//         sort(ar[i].begin(), ar[i].end());
//     }

// //     bool flag = 0;
// //     for (int i = 0; i < K - 1; i++)
// //     {
// //         for (int j = 0; j < n / K; j++)
// //         {
// //             if (ar[i][j] > ar[i + 1][j])
// //             {
// //                 flag = 1;
// //                 goto out;
// //             }
// //         }
// //     }

// //     for (int j = 0; j < n / K - 1; j++)
// //     {
// //         if (ar[K - 1][j] > ar[0][j + 1])
// //         {
// //             flag = 1;
// //             goto out;
// //         }
// //     }

// //     if (n % K != 0)
// //     {
// //         for (int i = 0; i < n % K - 1; i++)
// //         {
// //             if (ar[i].back() > ar[i + 1].back())
// //             {
// //                 flag = 1;
// //                 goto out;
// //             }
// //         }

// //         if (ar[K - 1][n / K] > ar[0][n / K + 1])
// //         {
// //             flag = 1;
// //             goto out;
// //         }
// //     }

// // out:

// //     cout << (flag ? "No\n" : "Yes\n");

//     int tot = 0;
//     for (int i = 0; i < n / K; i++)
//     {
//         for (int j = 0; j < K; j++)
//         {
//             arr[tot++] = ar[j][i];
//         }
//     }

//     if (n % K != 0)
//     {
//         for (int i = 0; i < n % K; i++)
//         {
//             arr[tot++] = ar[i][n / K];
//         }
//     }

//     cout << (is_sorted(arr.begin(), arr.end()) ? "Yes\n" : "No\n");

//     cout << endl;
//     return 0;
// }



// 2023/07/11 14:05:03

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < m; i++)
    {
        vector<int> tmp;
        
        for (int j = i; j < n; j += m)
        {
            tmp.emplace_back(arr[j]);
        }
        sort(tmp.begin(), tmp.end());
        
        int tot = 0;
        for (int j = i; j < n; j += m)
        {
            arr[j] = tmp[tot++];
        }
    }

    cout << (is_sorted(arr.begin(), arr.end()) ? "Yes\n" : "No\n");

    cout << endl;
    return 0;
}