#include <bits/stdc++.h>
using namespace std;



// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     int i, j, tmp;
//     for (i = 0; i < n; i++)
//     {
//         tmp = arr[i];
//         for (j = i; j - 1 >= 0 && arr[j - 1] > tmp; j--)
//         {
//             arr[j] = arr[j - 1];
//         }
//         arr[j] = tmp;
//         for (const int& a : arr)
//         {
//             cout << a << ' ';
//         }
//         cout << '\n';
//     }

//     cout << flush;
//     system("pause");
//     return 0;
// }


// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int a, b;
//     cin >> a >> b;
//     do
//     {
//         int tmp = b;
//         b = a % b;
//         a = tmp;
//     } while (b);
//     cout << a << '\n';

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
//     vector<int> arr(n);
//     for (int i = 0; i < n; i++)
//         cin >> arr[i];

//     for (int i = 2; i < 100000005; i++)
//     {
//         if (!isnp[i])
//             prime.emplace_back(i);

//         for (const int& p : prime)
//         {
//             if (p * i > 100000002) break;

//             isnp[p * i] = 1;

//             if (i % p == 0) break;
//         }
//     }
//     int ans = 0;
//     for (const int& p : arr)
//     {
//         if (binary_search(prime.begin(), prime.end(), p)) ans++;
//     }

//     cout << ans << '\n';
//     cout << flush;
//     system("pause");
//     return 0;
// }



// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for (int i = 0; i < n; i++) cin >> arr[i];
    
//     int min_num = arr[0], max_num = 0;
//     for (int i = 1; i < n; i++)
//     {
//         if (max_num < arr[i] - min_num)
//         {
//             max_num = arr[i] - min_num;
//         }
//         if (min_num > arr[i])
//         {
//             min_num = arr[i];
//         }
//     }
//     if (max_num != 0)
//         cout << max_num << '\n';
//     else
//         cout << -1 << '\n';

//     cout << flush;
//     system("pause");
//     return 0;
// }


// long int a[200000000];
// int main(void)
// {
//     long int n, i, maxv, minv;
//     scanf("%ld", &n);
//     for (i = 0;i < n;i++)
//         scanf("%ld", &a[i]);
//     minv = a[0];maxv = -2000000000;
//     for (i = 1;i < n;i++) //i要等于1
//     {
//         if (maxv < (a[i] - minv))
//             maxv = a[i] - minv;
//         if (minv > a[i])
//             minv = a[i];
//     }
    
//     printf("%ld\n", maxv);
//     return 0;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for (int i = 0; i < n; i++) cin >> arr[i];
//     int cnt = 0;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n - i - 1; j++)
//         {
//             if (arr[j] > arr[j + 1])
//             {
//                 swap(arr[j], arr[j + 1]);
//                 cnt++;
//             }
//         }
//     }
//     for (const int& p : arr) cout << p << ' ';
//     cout << endl;
//     cout << cnt << '\n';

//     cout << flush;
//     system("pause");
//     return 0;
// }


// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for (int i = 0; i < n; i++) cin >> arr[i];
//     int cnt = 0;
//     for (int i = 0; i < n; i++)
//     {
//         int index = -1;
//         int min_num = arr[i];
//         for (int j = i + 1; j < n; j++)
//         {
//             if (arr[j] < min_num)
//             {
//                 index = j;
//                 min_num = arr[j];
//             }
//         }
//         if (index != -1)
//         {
//             swap(arr[i], arr[index]);
//             cnt++;
//         }
//     }
//     for (const int& p : arr) cout << p << ' ';
//     cout << endl;
//     cout << cnt << '\n';
    

//     cout << flush;
//     system("pause");
//     return 0;
// }


// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     vector<int> increment;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
    
//     for (int i = 1; i < n; i = 3 * i + 1)
//     {
//         increment.emplace_back(i);
//     }
//     if (increment.empty())
//     {
//         increment.emplace_back(1);
//     }

//     reverse(increment.begin(), increment.end());

//     int tmp;
//     int i, j;
//     int cnt = 0;
//     for (auto it = increment.begin(); it != increment.end(); it++)
//     {
//         for (i = *it; i < n; i++)
//         {
//             tmp = arr[i];
//             for (j = i; j - *it >= 0 && arr[j - *it] > tmp; j -= *it)
//             {
//                 arr[j] = arr[j - *it];
//                 cnt++;
//             }
//             arr[j] = tmp;
//         }
//     }

//     cout << increment.size() << '\n';
//     for (auto it = increment.begin(); it != increment.end(); it++)
//         cout << *it << ' ';
//     cout << endl;
//     cout << cnt << endl;
//     for (i = 0; i < n; i++)
//     {
//         cout << arr[i] << '\n';
//     }
    
//     cout << flush;
//     system("pause");
//     return 0;
// }

// char s1[1005], s2[1005];
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     fgets(s1, 1005, stdin);
//     fgets(s2, 1005, stdin);
//     for (size_t i = 0; i < strlen(s1); i++)
//     {
//         if (strchr(s2, s1[i]))
//             continue;
//         else
//             putchar(s1[i]);
//     }

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