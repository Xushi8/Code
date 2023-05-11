// 2023/04/26 11:27:07
#include <bits/stdc++.h>
using namespace std;



// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int n, m;
//     cin >> n >> m;
//     vector<int> arr(n);
//     for (int i = 0; i < n; i++)
//         cin >> arr[i];
//     while (m--)
//     {
//         next_permutation(arr.begin(), arr.end());
//     }
//     for (int i : arr)
//     {
//         cout << i << ' ';
//     }

//     cout << endl;
//     return 0;
// }


// // 2023/04/26 15:18:02
// vector<vector<int>> arr;
// int ans = 0;
// int n, m;
// // 
// void dfs(int deep, int tmp_ans, int a, int b)
// {
//     if (deep == n)
//     {
//         if (ans == 0 || tmp_ans < ans)
//         {
//             ans = tmp_ans;
//         }
//         return;
//     }

//     if (deep == 0 || (a == 0 && deep < n - 2))
//     {
//         dfs(deep + 1, tmp_ans + (m - arr[deep][0]), 0, 0);
//     }
//     if (deep != 0 && b == 0 && deep < n - 1)
//     {
//         dfs(deep + 1, tmp_ans + (m - arr[deep][1]), 1, 0);
//     }
//     if (deep != 0)
//     {
//         dfs(deep + 1, tmp_ans + (m - arr[deep][2]), 1, 1);
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     cin >> n >> m;
//     string tmp;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> tmp;
//         vector<int> arr_tmp(3);
//         for (char i : tmp)
//         {
//             if (i == 'W')
//                 arr_tmp[0]++;
//             else if (i == 'B')
//                 arr_tmp[1]++;
//             else
//                 arr_tmp[2]++;
//         }
//         arr.emplace_back(arr_tmp);
//     }

//     // for (int i = 0; i < n - 2; i++)
//     // {
//     //     for (int j = i + 1; j < n - 1; j++)
//     //     {
//     //         for (int k = j + 1; k < n; k++)
//     //         {
                
//     //         }
//     //     }
//     // }
//     dfs(0, 0, 0, 0);

//     cout << ans;
//     cout << endl;
//     return 0;
// }


// 2023/04/26 15:58:50

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int n, m, g;
//     cin >> n >> m >> g;
//     vector<string> str;
//     for (int i = 0; i < n; i++)
//     {
//         string tmp;
//         cin >> tmp;
//         str.emplace_back(tmp);
//     }
//     int ans = 0;
//     if (g != 1)
//     {
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < m; j++) // qi dian
//             {
//                 int cnt = 0;
//                 if (str[i][j] == '.')
//                 {
//                     cnt++;
//                     for (int k = j + 1; k < m; k++)
//                     {
//                         if (str[i][k] == '.')
//                         {
//                             cnt++;
//                         }
//                         else
//                         {
//                             break;
//                         }

//                         if (cnt == g)
//                         {
//                             ans++;
//                             break;
//                         }
//                     }
//                 }
//             }
//         }

//         for (int j = 0; j < m; j++)
//         {
//             for (int i = 0; i < n; i++)
//             {
//                 int cnt = 0;
//                 if (str[i][j] == '.')
//                 {
//                     cnt++;
//                     for (int k = i + 1; k < n; k++)
//                     {
//                         if (str[k][j] == '.')
//                         {
//                             cnt++;
//                         }
//                         else
//                         {
//                             break;
//                         }

//                         if (cnt == g)
//                         {
//                             ans++;
//                             break;
//                         }
//                     }
//                 }
//             }
//         }
//     }
//     else
//     {
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < m; j++)
//             {
//                 if (str[i][j] == '.')
//                     ans++;
//             }
//         }
//     }
    
//     cout << ans;

//     cout << endl;
//     return 0;
// }




// 2023/04/26 16:18:29


// long long C(int n, int m)
// {
//     if (m < n - m) m = n - m;
//     long long ans = 1;
//     for (int i = m + 1; i <= n; i++) ans *= i;
//     for (int i = 1; i <= n - m; i++) ans /= i;
//     return ans;
// }

// int arr[5005];
// const int mod = (int)(1e9 + 7);
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int n;
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         int a;
//         cin >> a;
//         arr[a]++;
//     }
    
//     long long ans = 0;
//     for (int i = 1; i < 5005; i++)
//     {
//         if (arr[i] > 1)
//         {
//             for (int j = 1; j <= i / 2; j++)
//             {
//                 if (arr[j] && arr[i - j] && j != i - j)
//                 {
//                     ans = (ans + C(arr[i], 2) * arr[j] * arr[i - j]) % mod;
//                 }
//                 if (j == i - j && arr[j] > 1)
//                 {
//                     ans = (ans + C(arr[i], 2) * C(arr[j], 2)) % mod;
//                 }
//             }
            
//         }
//     }


    
//     // while (l <= r)
//     // {




        
//     //     // if (l == r)
//     //     // {
//     //     //     if (arr[l] >= 4)
//     //     //     {
//     //     //         ans = (ans + C(arr[l], 4)) % mod;
//     //     //     }
//     //     //     break;
//     //     // }
//     //     // if (arr[l] > 1)
//     //     // {
//     //     //     c = l;
//     //     // }
//     //     // else
//     //     // {
//     //     //     for (int i = l + 1; i <= r; i++)
//     //     //     {
                
//     //     //     }
//     //     // }

        
//     //     // if (arr[r] > 1)
//     //     // {
//     //     //     d = r;
//     //     // }
//     //     // else
//     //     // {
//     //     //     for (int j = r - 1; j >= 0; j--)
//     //     //     {
//     //     //         if (arr[j] != 0)
//     //     //         {
//     //     //             mid = j;
//     //     //             break;
//     //     //         }
//     //     //     }
//     //     // }

//     //     // if (mid == l && arr[l] == 1)
//     //     // {
//     //     //     for (int i = l + 1; i <= r; i++)
//     //     //     {
//     //     //         if (arr[i])
//     //     //         {
//     //     //             l = i;
//     //     //             break;
//     //     //         }
//     //     //     }
            
//     //     //     continue;
//     //     // }
        
//     //     // while (l + mid > r)
//     //     // {
//     //     //     if (mid == r)
//     //     //     {
//     //     //         ans = (ans + arr[l] * C(arr[r], 2)) % mod;
//     //     //     }
//     //     //     else if (mid == l)
//     //     //     {
//     //     //         ans = (ans + arr[r] * C(arr[l], 2)) % mod;
//     //     //     }
//     //     //     else
//     //     //     {
//     //     //         ans = (ans + arr[l] * arr[mid] * arr[r]) % mod;
//     //     //     }

//     //     //     for (int i = mid - 1; i >= l; i--)
//     //     //     {
//     //     //         if (arr[i])
//     //     //         {
//     //     //             mid = i;
//     //     //             break;
//     //     //         }
//     //     //     }
//     //     // }
//     // }
//     cout << ans;

//     cout << endl;
//     return 0;
// }



// 2023/04/26 17:20:21

vector<int> arr[4];
int f[605];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int a[4];
    for (int i = 0; i < 4; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < a[i]; j++)
        {
            int tmp;
            cin >> tmp;
            arr[i].emplace_back(tmp);
        }
    }

    // int ans = 0;
    // for (int i = 0; i < 4; i++)
    // {
    //     auto it1 = arr[i].begin(), it2 = arr[i].begin() + 1;
    //     if (it2 == arr[i].end())
    //         ans += *it1;
    //     else
    //     {
    //         while (1)
    //         {
    //             it1 = arr[i].begin(); it2 = arr[i].begin() + 1;
    //             if (it2 == arr[i].end())
    //             {
    //                 ans += *it1;
    //                 break;
    //             }
    //             ans += *it2;
    //             *it1 -= *it2;
    //             arr[i].erase(it2);
    //             sort(arr[i].begin(), arr[i].end(), greater<int>());
    //         }
    //     }
    // }


    int ans = 0;
    for (int k = 0; k < 4; k++)
    {
        const vector<int> &tmp = arr[k];
        memset(f, 0, sizeof(f));
        int W = 0;
        for (int p : tmp)
        {
            W += p;
        }
        
        for (int i = 0; i < tmp.size(); i++)
        {
            for (int j = W / 2; j >= tmp[i]; j--)
            {
                f[j] = max(f[j], f[j - tmp[i]] + tmp[i]);
            }
        }
        ans += max(f[W / 2], W - f[W / 2]);
    }
    
    cout << ans;

    cout << endl;
    return 0;
}