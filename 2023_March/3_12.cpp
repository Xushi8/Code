#include<bits/stdc++.h>
using namespace std;



// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     bool arr[64] = { 0 };
//     int tt;
//     cin >> tt;
//     int flag = 0;
//     uint64_t ans;
//     while (tt--)
//     {
//         int a, b;
//         cin >> a;
//         switch (a)
//         {
//         case 0:
//             cin >> b;
//             cout << arr[b] << '\n';
//             break;
//         case 1:
//             cin >> b;
//             arr[b] = 1;
//             break;
//         case 2:
//             cin >> b;
//             arr[b] = 0;
//             break;
//         case 3:
//             cin >> b;
//             arr[b] = !arr[b];
//             break;
//         case 4:
//             flag = 0;
//             for (int i = 0; i < 64; i++)
//             {
//                 if (arr[i] == 0)
//                 {
//                     flag = 1;
//                     cout << 0 << '\n';
//                     break;
//                 }
//             }
//             if (flag == 0)
//                 cout << 1 << '\n';
//             break;
//         case 5:
//             flag = 0;
//             for (int i = 0; i < 64; i++)
//             {
//                 if (arr[i] == 1)
//                 {
//                     cout << 1 << '\n';
//                     flag = 1;
//                     break;
//                 }
//             }
//             if (flag == 0)
//             {
//                 cout << 0 << '\n';
//             }
            
//             break;
//         case 6:
//             flag = 0;
//             for (int i = 0; i < 64; i++)
//             {
//                 if (arr[i] == 1)
//                 {
//                     flag = 1;
//                     cout << 0 << '\n';
//                     break;
//                 }
//             }
//             if (flag == 0)
//                 cout << 1 << '\n';
//             break;
//         case 7:
//             ans = 0;
//             for (int i = 0; i < 64; i++)
//             {
//                 if (arr[i] == 1)
//                     ans++;
//             }
//             cout << ans << '\n';
//             break;
//         case 8:
//             ans = 0;
//             uint64_t tmp = 1;
//             for (int i = 0; i < 64; i++)
//             {
//                 ans += arr[i] * tmp;
//                 tmp *= 2;
//             }
//             cout << ans << '\n';
//             break;
//         // default:
//         //     break;
//         }
//     }

//     cout << flush;
//     system("pause");
//     return 0;
// }



// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     bool arr[64] = { 0 };
//     int n;
//     vector<vector<int>> mark;
//     cin >> n;
//     while (n--)
//     {
//         int a;
//         cin >> a;
//         vector<int> tmp;
//         while (a--)
//         {
//             int b;
//             cin >> b;
//             tmp.emplace_back(b);
//         }
//         mark.emplace_back(tmp);
//     }
    

//     int tt;
//     cin >> tt;
//     int flag = 0;
//     uint64_t ans;
//     while (tt--)
//     {
//         int a, b;
//         cin >> a;
//         switch (a)
//         {
//         case 0:
//             cin >> b;
//             cout << arr[b] << '\n';
//             break;
//         case 1:
//             cin >> b;
//             for (int i = 0; i < mark[b].size(); i++)
//             {
//                 arr[mark[b][i]] = 1;
//             }
            
//             break;
//         case 2:
//             cin >> b;
//             for (int i = 0; i < mark[b].size(); i++)
//             {
//                 arr[mark[b][i]] = 0;
//             }
//             break;
//         case 3:
//             cin >> b;
//             for (int i = 0; i < mark[b].size(); i++)
//             {
//                 arr[mark[b][i]] = !arr[mark[b][i]];
//             }
//             break;
//         case 4:
//             flag = 0;
//             cin >> b;
//             for (int i = 0; i < mark[b].size(); i++)
//             {
//                 if (arr[mark[b][i]] == 0)
//                 {
//                     flag = 1;
//                     cout << 0 << '\n';
//                     break;
//                 }
//             }
//             if (flag == 0)
//                 cout << 1 << '\n';
//             break;
//         case 5:
//             flag = 0;
//             cin >> b;
//             for (int i = 0; i < mark[b].size(); i++)
//             {
//                 if (arr[mark[b][i]] == 1)
//                 {
//                     cout << 1 << '\n';
//                     flag = 1;
//                     break;
//                 }
//             }
//             if (flag == 0)
//             {
//                 cout << 0 << '\n';
//             }

//             break;
//         case 6:
//             flag = 0;
//             cin >> b;
//             for (int i = 0; i < mark[b].size(); i++)
//             {
//                 if (arr[mark[b][i]] == 1)
//                 {
//                     flag = 1;
//                     cout << 0 << '\n';
//                     break;
//                 }
//             }
//             if (flag == 0)
//                 cout << 1 << '\n';
//             break;
//         case 7:
//             ans = 0;
//             cin >> b;
//             for (int i = 0; i < mark[b].size(); i++)
//             {
//                 if (arr[mark[b][i]] == 1)
//                     ans++;
//             }
//             cout << ans << '\n';
//             break;
//         case 8:
//             ans = 0;
//             cin >> b;
//             for (int i = 0; i < mark[b].size(); i++)
//             {
//                 ans += arr[mark[b][i]] * (pow(2.L, mark[b][i]));
//             }
//             cout << ans << '\n';
//             break;
//             // default:
//             //     break;
//         }
//     }

//     cout << flush;
//     system("pause");
//     return 0;
// }

// bool isnp[100000005];
// vector<int> prime;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int n;
//     cin >> n;
//     for (int i = 2; i <= n; i++)
//     {
//         if (!isnp[i])
//             prime.emplace_back(i);

//         for (const int& p : prime)
//         {
//             if (p * i > n) break;

//             isnp[p * i] = 1;

//             if (i % p == 0) break;
//         }
//     }
//     int tt;
//     cin >> tt;
//     while (tt--)
//     {
//         int a;
//         cin >> a;
//         cout << prime[a - 1] << '\n';
//     }

//     cout << flush;
//     system("pause");
//     return 0;
// }

// const int N = 1000000005;
// bool isnp[N];
// vector<int> prime;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int begin = clock();
//     for (int i = 2; i < N; i++)
//     {
//         if (!isnp[i])
//             prime.emplace_back(i);

//         for (const int& p : prime)
//         {
//             if (p * i > N) break;

//             isnp[p * i] = 1;

//             if (i % p == 0) break;
//         }
//     }
//     int end = clock();

//     for (size_t i = 1; i < prime.size(); i++)
//     {
//         cout << prime[i] << '\n';
//     }

//     cout << (double)(end - begin) / 1000.0 << '\n';
//     cout << flush;
//     system("pause");
//     return 0;
// }



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    
    
    cout << flush;
    system("pause");
    return 0;
}