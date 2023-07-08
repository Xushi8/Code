// 2023/07/07 17:35:55
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

// struct edge
// {
//     int to, cost;
//     edge() {}
//     edge(int to_, int cost_)
//     {
//         to = to_;
//         cost = cost_;
//     }
    
//     bool operator < (const edge& e) const
//     {
//         return this->cost < e.cost;
//     }
//     bool operator > (const edge& e) const
//     {
//         return this->cost > e.cost;
//     }
// };

int arr[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    // priority_queue<edge, vector<edge>, greater<edge>> que;
    // que.emplace(1, 10);
    // que.emplace(1, 30);
    // que.emplace(1, 20);
    // while (!que.empty())
    // {
    //     cout << que.top().cost << '\n';
    //     que.pop();
    // }

    int tt;
    cin >> tt;
    // while (tt--)
    // {
    //     int n;
    //     cin >> n;
    //     if (n == 1)
    //     {
    //         cout << -1 << '\n';
    //         continue;
    //     }

    //     cin >> arr[0];
    //     bool flag = 0;
    //     vector<int> ans_index;
    //     int count = 1;
    //     for (int i = 1; i < n; i++)
    //     {
    //         cin >> arr[i];
    //         if (arr[i] == arr[i - 1])
    //         {
    //             count++;
    //         }
    //         else
    //         {
    //             if (count == 1)
    //             {
    //                 flag = 1;
    //                 cout << -1 << '\n';
    //                 break;
    //             }
                
    //             count = 1;
    //             ans_index.emplace_back(i);
    //         }
    //     }

    //     if (arr[n - 2] != arr[n - 1] && !flag)
    //     {
    //         flag = 1;
    //         cout << -1 << '\n';
    //     }
    //     else
    //     {
    //         ans_index.emplace_back(n);
    //     }


    //     if (!flag)
    //     {
    //         int now = 0;
    //         for (size_t i = 0; i < ans_index.size(); i++)
    //         {
    //             int j = ans_index[i];
    //             cout << j << ' ';
    //             for (int k = now == 0 ? 1 : now + 1; k < j; k++)
    //             {
    //                 cout << k << ' ';
    //             }
    //             now = j;
    //         }
    //         cout << '\n';
    //     }
    // }


    while (tt--)
    {
        // int n;
        // cin >> n;
        // vector<int> ans_index;
        // bool flag = 0;
        // for (int i = 0; i < n; i++)
        // {
        //     cin >> arr[i];
        //     int j = i + 1;
        //     int count = 1;
        //     bool this_flag = 0;
        //     while (j < n)
        //     {
        //         cin >> arr[j];
        //         if (arr[j] == arr[i])
        //         {
        //             count++;
        //             j++;
        //         }
        //         else
        //         {
        //             ans_index.emplace_back(j);
        //             i = j;
        //             this_flag = 1;
        //             break;
        //         }
        //     }
            
        //     if (count == 1)
        //     {
        //         flag = 1;
        //         cout << -1 << '\n';
        //         break;
        //     }
            
        //     if (!this_flag)
        //     {
        //         ans_index.emplace_back(j);
        //         i = j;
        //     }
        // }



        // if (!flag)
        // {
        //     int now = 1;
        //     for (size_t i = 0; i < ans_index.size(); i++)
        //     {
        //         int j = ans_index[i];
        //         cout << j << ' ';
        //         for (int k = now; k < j; k++)
        //         {
        //             cout << k << ' ';
        //         }
        //     }
        //     cout << '\n';
        // }



        // int n;
        // cin >> n;
        // if (n == 1)
        // {
        //     int x;
        //     cin >> x;
        //     cout << -1 << '\n';
        //     continue;
        // }
        
        // cin >> arr[0];
        // bool flag = 0;
        // vector<int> ans_index;
        // for (int i = 1; i < n; i++)
        // {
        //     int count = 1;
        //     int j = i;
        //     cin >> arr[j];
        //     while (j < n && arr[j] == arr[i - 1])
        //     {
        //         count++;
        //         j++;
        //         if (j == n)
        //             break;
                
        //         cin >> arr[j];
        //     }
        //     if (count == 1 && !flag)
        //     {
        //         flag = 1;
        //         cout << -1 << '\n';
        //     }
        //     ans_index.emplace_back(j);
        //     i = j;
        // }

        // if (arr[n - 1] != arr[n - 2] && !flag)
        // {
        //     flag = 1;
        //     cout << -1 << '\n';
        //     continue;
        // }

        // if (!flag)
        // {
        //     int now = 1;
        //     for (size_t i = 0; i < ans_index.size(); i++)
        //     {
        //         int j = ans_index[i];
        //         cout << j << ' ';
        //         for(int k = now; k < j; k++)
        //         {
        //             cout << k << ' ';
        //         }
        //         now = j + 1;
        //     }
        //     cout << '\n';
        // }


        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        bool flag = 0;
        vector<int> ans_index;
        for (int i = 0, j; i < n; i = j)
        {
            j = i + 1;
            while (j < n && arr[j] == arr[i])
                j++;
            if (j - i == 1)
            {
                flag = 1;
                break;
            }
            ans_index.emplace_back(j);
        }
        if (flag)
            cout << -1 << '\n';
        else
        {
            int now = 1;
            for (size_t i = 0; i < ans_index.size(); i++)
            {
                int j = ans_index[i];
                cout << j << ' ';
                for (int k = now; k < j; k++)
                {
                    cout << k << ' ';
                }
                now = j + 1;
            }
            cout << '\n';
        }
    }


    cout << endl;
    return 0;
}