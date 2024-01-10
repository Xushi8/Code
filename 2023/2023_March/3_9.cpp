#include<bits/stdc++.h>
using namespace std;



// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     int n, tt;
//     cin >> n >> tt;
//     vector<vector<int>> arr(n);
//     while(tt--)
//     {
//         int a, b, c;
//         cin >> a;
//         if (a == 0)
//         {
//             cin >> b >> c;
//             arr[b].emplace_back(c);
//         }
//         else if (a == 1)
//         {
//             cin >> b;
//             for (const auto& i : arr[b])
//             {
//                 cout << i << ' ';
//             }
//             cout << endl;
//         }
//         else
//         {
//             cin >> b;
//             arr[b].clear();
//         }
//     }

//     system("pause");
//     return 0;
// }


// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     int n, tt;
//     cin >> n >> tt;
//     vector<stack<int>> arr(n);
//     while (tt--)
//     {
//         int a, b, c;
//         cin >> a;
//         if (a == 0)
//         {
//             cin >> b >> c;
//             arr[b].push(c);
//         }
//         else if (a == 1)
//         {
//             cin >> b;
//             if (!arr[b].empty())
//             {
//                 cout << arr[b].top() << endl;
//             }
//         }
//         else
//         {
//             cin >> b;
//             if (!arr[b].empty())
//             {
//                 arr[b].pop();
//             }
//         }
//     }

//     system("pause");
//     return 0;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     int n, tt;
//     cin >> n >> tt;
//     vector<queue<int>> arr(n);
//     while (tt--)
//     {
//         int a, b, c;
//         cin >> a;
//         if (a == 0)
//         {
//             cin >> b >> c;
//             arr[b].push(c);
//         }
//         else if (a == 1)
//         {
//             cin >> b;
//             if (!arr[b].empty())
//             {
//                 cout << arr[b].front() << endl;
//             }
//         }
//         else
//         {
//             cin >> b;
//             if (!arr[b].empty())
//             {
//                 arr[b].pop();
//             }
//         }
//     }

//     system("pause");
//     return 0;
// }


// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     int n, tt;
//     cin >> n >> tt;
//     vector<priority_queue<int, vector<int>, less<int>>> arr(n);
//     while (tt--)
//     {
//         int a, b, c;
//         cin >> a;
//         if (a == 0)
//         {
//             cin >> b >> c;
//             arr[b].push(c);
//         }
//         else if (a == 1)
//         {
//             cin >> b;
//             if (!arr[b].empty())
//             {
//                 cout << arr[b].top() << endl;
//             }
//         }
//         else
//         {
//             cin >> b;
//             if (!arr[b].empty())
//             {
//                 arr[b].pop();
//             }
//         }
//     }

//     system("pause");
//     return 0;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     int n, tt;
//     cin >> n >> tt;
//     vector<list<int>> arr(n);
//     while (tt--)
//     {
//         int a, b, c;
//         cin >> a;
//         if (a == 0)
//         {
//             cin >> b >> c;
//             arr[b].emplace_back(c);
//         }
//         else if (a == 1)
//         {
//             cin >> b;
//             for (const auto& i : arr[b])
//             {
//                 cout << i << ' ';
//             }
//             cout << endl;
//         }
//         else
//         {
//             cin >> b >> c;
//             arr[c].splice(arr[c].end(), arr[b]);
//         }
//     }

//     system("pause");
//     return 0;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int arr[3];
//     int tt = 3;
//     while (--tt)
//         cin >> arr[tt];
//     cin >> arr[0];
//     sort(arr, arr + 3);
//     cout << arr[0] << ' ' << arr[2] << endl;

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
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     int min_num, max_num;
//     int tt;
//     cin >> tt;
//     while (tt--)
//     {
//         int a, b, c;
//         cin >> a >> b >> c;
//         if (a == 1)
//         {
//             max_num = arr[b];
//             for (int i = b + 1; i < c; i++)
//             {
//                 if (arr[i] > max_num) max_num = arr[i];
//             }
//             cout << max_num << endl;
//         }
//         else
//         {
//             min_num = arr[b];
//             for (int i = b + 1; i < c; i++)
//             {
//                 if (arr[i] < min_num) min_num = arr[i];
//             }
//             cout << min_num << endl;
//         }
//     }

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
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     int cnt;
//     int tt;
//     cin >> tt;
//     while (tt--)
//     {
//         int a, b, c;
//         cin >> a >> b >> c;
//         cnt = 0;
//         for (int i = a; i < b; i++)
//             if (arr[i] == c) cnt++;
//         cout << cnt << endl;
//     }

//     system("pause");
//     return 0;
// }

// int a1[1005], a2[1005], s1, s2;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cin >> s1;
//     for (int i = 0; i < s1; i++)
//         cin >> a1[i];
//     cin >> s2;
//     for (int i = 0; i < s2; i++)
//         cin >> a2[i];

//     int flag = 0;
//     for (int i = 0; i < min(s1, s2); i++)
//     {
//         if (a1[i] < a2[i])
//         {
//             cout << 1 << endl;
//             flag = 1;
//             break;
//         }
//         else if (a1[i] > a2[i])
//         {
//             cout << 0 << endl;
//             flag = 1;
//             break;
//         }
//     }
//     if (flag == 0)
//     {
//         if (s2 > s1)
//             cout << 1 << endl;
//         else
//             cout << 0 << endl;
//     }

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
//     for (int i = 0; i < n; i++)
//         cin >> arr[i];
//     int tt;
//     cin >> tt;
//     while (tt--)
//     {
//         int a, b;
//         cin >> a >> b;
//         reverse(arr.begin() + a, arr.begin() + b);
//     }
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << ' ';
//     }
//     cout << endl;

//     system("pause");
//     return 0;
// }

// int n, W, v[1005], w[1005];
// uint64_t ans[100000005];

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     cin >> n >> W;
//     int tot = 1;
//     while (n--)
//     {
//         int a, b, c;
//         cin >> a >> b >> c;
//         for (int k = 1; k <= c; k *= 2)
//         {
//             v[tot] = a * k;
//             w[tot++] = b * k;
//             c -= k;
//         }
//         if (c > 0)
//         {
//             v[tot] = a * c;
//             w[tot++] = b * c;
//         }
//     }

//     for (int i = 1; i <= tot; i++)
//         for (int j = W; j >= w[i]; j--)
//             ans[j] = max(ans[j], ans[j - w[i]] + v[i]);

//     cout << ans[W] << endl;

//     system("pause");
//     return 0;
// }


// uint64_t dp[50005];
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int n, m;
//     cin >> n >> m;
//     int mon[25];
//     for (int i = 0; i < m; i++)
//     {
//         cin >> mon[i];
//     }
    
//     for (int i = 1; i <= n; i++)
//     {
//         uint64_t tmp = UINT64_MAX;
//         for (int j = 0; j < m; j++)
//         {
//             if (i - mon[j] >= 0) tmp = min(tmp, dp[i - mon[j]] + 1);
//         }
//         dp[i] = tmp;
//     }
//     cout << dp[n] << endl;

//     system("pause");
//     return 0;
// }


// int n, W, v[1005], w[1005];
// uint64_t f[10005];
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     cin >> n >> W;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> v[i] >> w[i];
//     }
    
//     for (int i = 1; i <= n; i++)
//         for (int j = W; j >= w[i]; j--)
//             f[j] = max(f[j], f[j - w[i]] + v[i]);

//     cout << f[W] << endl;

//     system("pause");
//     return 0;
// }

// int n, W, v[1005], w[1005];
// uint64_t f[10005];
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     cin >> n >> W;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> v[i] >> w[i];
//     }

//     for (int i = 1; i <= n; i++)
//         for (int j = w[i]; j <= W; j++)
//             f[j] = max(f[j], f[j - w[i]] + v[i]);

//     cout << f[W] << endl;

//     system("pause");
//     return 0;
// }

// int arr[100005];
// int dp[100005];
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int n;
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//         cin >> arr[i];
//     for (int i = 1; i <= n; i++)
//     {
//         dp[i] = 1;
//         for (int j = 1; j < i; j++)
//         {
//             if (arr[i] > arr[j])
//                 dp[i] = max(dp[i], dp[j] + 1);
//         }
//     }
//     int max_num = -1;
//     for (int i = 1; i <= n; i++)
//     {
//         if (dp[i] > max_num) max_num = dp[i];
//     }
//     cout << max_num << endl;

//     system("pause");
//     return 0;
// }


// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int a, b, c, d, e;
//     cin >> a >> b >> c >> d >> e;
//     if (c + e <= a && c - e >= 0 && d + e <= b && d - e >= 0)
//         cout << "Yes" << endl;
//     else
//         cout << "NO" << endl;

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
//     vector<int> arr1(n);
//     vector<int> arr2(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
    
//     int tt;
//     cin >> tt;
//     while (tt--)
//     {
//         int b, m, e;
//         cin >> b >> m >> e;
//         for (int i = b; i < m; i++)
//         {
//             arr1[i] = arr[i];
//         }
//         for (int i = m; i < e; i++)
//         {
//             arr2[i] = arr[i];
//         }

//         int i, j;
//         for (i = b, j = m; j < e; j++, i++)
//         {
//             arr[i] = arr2[j];
//         }
//         for (j = b; j < m; i++, j++)
//         {
//             arr[i] = arr1[j];
//         }
//     }

//     for (const auto& i : arr)
//     {
//         cout << i << ' ';
//     }
//     cout << endl;

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
//     for (int i = 0; i < n; i++)
//         cin >> arr[i];
//     int tt;
//     cin >> tt;
//     while (tt--)
//     {
//         int b, e, t;
//         cin >> b >> e >> t;
//         for (int k = 0; k < e - b; k++)
//         {
//             swap(arr[b + k], arr[t + k]);
//         }
//     }

//     for (auto& i : arr)
//         cout << i << ' ';
//     cout << endl;

//     system("pause");
//     return 0;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int n;
//     cin >> n;
//     set<int> s;
//     for (int i = 0; i < n; i++)
//     {
//         int tmp;
//         cin >> tmp;
//         s.insert(tmp);
//     }

//     for (auto& i : s)
//         cout << i << ' ';
//     cout << endl;

//     system("pause");
//     return 0;
// }


// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int a, b;
//     cin >> a >> b;
//     if (a > b) cout << "a > b";
//     else if (a < b) cout << "a < b";
//     else cout << "a == b";
//     cout << endl;

//     system("pause");
//     return 0;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int a, b, c;
//     cin >> a >> b >> c;
//     if (a < b && b < c)
//         cout << "Yes" << endl;
//     else
//         cout << "No" << endl;

//     system("pause");
//     return 0;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int tt = 1000;
//     while (tt--)
//         cout << "Hello World" << '\n';
//     cout << flush;

//     system("pause");
//     return 0;
// }


// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int i = 1;
//     int num;
//     while (cin >> num && num)
//     {
//         cout << "Case " << i++ << ": " << num << '\n';
//     }
//     cout << flush;

//     system("pause");
//     return 0;
// }


// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int arr[2];
//     while (cin >> arr[0] >> arr[1] && (arr[0] || arr[1]))
//     {
//         if (arr[0] < arr[1])
//             cout << arr[0] << ' ' << arr[1] << '\n';
//         else
//             cout << arr[1] << ' ' << arr[0] << '\n';
//     }
//     cout << flush;

//     system("pause");
//     return 0;
// }


// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int a, b, c;
//     cin >> a >> b >> c;
//     int cnt = 0;
//     for (int i = a; i <= b; i++)
//     {
//         if (c % i == 0) cnt++;
//     }
//     cout << cnt << endl;

//     system("pause");
//     return 0;
// }


// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int a, b;
//     char ch;
//     while (cin >> a >> ch >> b && ch != '?')
//     {
//         switch (ch)
//         {
//         case '+':
//             cout << a + b << endl;
//             break;
//         case '-':
//             cout << a - b << endl;
//             break;
//         case '*':
//             cout << a * b << endl;
//             break;
//         case '/':
//             cout << a / b << endl;
//             break;
//         default:
//             break;
//         }
//     }

//     system("pause");
//     return 0;
// }


// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int a, b;
//     cin >> a >> b;
//     printf("%d %d %.5lf", a / b, a % b, (double)a / b);

//     system("pause");
//     return 0;
// }

// const long double PI = 3.1415926535897932384626433832795L;
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     long double r;
//     cin >> r;
//     printf("%.6Lf %.6Lf", PI * r * r, 2. * PI * r);

//     system("pause");
//     return 0;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int n, tmp;
//     cin >> n;
//     int min_n = 999999999, max_n = -999999999;
//     int64_t sum = 0;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> tmp;
//         sum += tmp;
//         if (tmp > max_n) max_n = tmp;
//         if(tmp < min_n) min_n = tmp;
//     }

//     cout << min_n << ' ' << max_n << ' ' << sum << endl;
//     system("pause");
//     return 0;
// }


// void call(int n)
// {
//     int i = 1;
// CHECK_NUM:
//     int x = i;
//     if (x % 3 == 0) {
//         cout << " " << i;
//         goto END_CHECK_NUM;
//     }
// INCLUDE3:
//     if (x % 10 == 3) {
//         cout << " " << i;
//         goto END_CHECK_NUM;
//     }
//     x /= 10;
//     if (x) goto INCLUDE3;
// END_CHECK_NUM:
//     if (++i <= n) goto CHECK_NUM;

//     cout << endl;
// }


// void call(int n)
// {
//     for (int i = 3; i <= n; i++)
//     {
//         if (i % 3 == 0)
//         {
//             cout << ' ' << i;
//             continue;
//         }

//         int j = i;
//         while (j)
//         {
//             int tmp = j % 10;
//             if (tmp == 3)
//             {
//                 cout << ' ' << i;
//                 break;
//             }
//             j /= 10;
//         }
//     }
//     cout << endl;
// }
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int n;
//     cin >> n;
//     call(n);

//     system("pause");
//     return 0;
// }



// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int a, b;
//     while (cin >> a >> b && (a || b))
//     {
//         for (int i = 0; i < a; i++)
//         {
//             for (int j = 0; j < b; j++)
//             {
//                 cout << '#';
//             }
//             cout << '\n';
//         }
//         cout << endl;
//     }

//     system("pause");
//     return 0;
// }



// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int a, b;
//     while (cin >> a >> b && (a || b))
//     {
//         for (int i = 0; i < a; i++)
//         {
//             for (int j = 0; j < b; j++)
//             {
//                 if (i == 0 || i == a - 1)
//                     cout << '#';
//                 else if (j == 0 || j == b - 1)
//                     cout << '#';
//                 else
//                     cout << '.';
//             }
//             cout << '\n';
//         }
//         cout << endl;
//     }

//     system("pause");
//     return 0;
// }


// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int a, b;
//     char s[2] = { '#', '.' };
//     bool flag;
//     while (cin >> a >> b && (a || b))
//     {
//         flag = 0;
//         for (int i = 0; i < a; i++)
//         {
//             for (int j = 0; j < b; j++)
//             {
//                 cout << s[flag];
//                 flag = !flag;
//             }
//             if (b % 2 == 0)
//                 flag = !flag;
//             cout << '\n';
//         }
//         cout << endl;
//     }

//     system("pause");
//     return 0;
// }

// int arr[4][14];
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     char ch;
//     int n;
//     cin >> n;
//     int tmp;
//     while (n--)
//     {
//         cin >> ch >> tmp;
//         switch (ch)
//         {
//         case 'S':
//             arr[0][tmp]++;
//             break;
//         case 'H':
//             arr[1][tmp]++;
//             break;
//         case 'C':
//             arr[2][tmp]++;
//             break;
//         case 'D':
//             arr[3][tmp]++;
//             break;
//         default:
//             break;
//         }
//     }

    
//     for (int i = 0; i < 4; i++)
//     {
//         for (int j = 1; j <= 13; j++)
//         {
//             if (arr[i][j] == 0)
//             {
//                 if (i == 0) cout << "S " << j << '\n';
//                 else if (i == 1) cout << "H " << j << '\n';
//                 else if (i == 2) cout << "C " << j << '\n';
//                 else cout << "D " << j << '\n';
//             }
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
    
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for (int i = 0; i < n; i++)
//         cin >> arr[i];
//     reverse(arr.begin(), arr.end());
//     for (int i = 0; i < n; i++)
//         cout << arr[i] << ' ';
//     cout << endl;

//     system("pause");
//     return 0;
// }


// int arr[5][4][11];
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int tt;
//     cin >> tt;
//     while (tt--)
//     {
//         int a, b, c, d;
//         cin >> a >> b >> c >> d;
//         arr[a][b][c] += d;
//     }

//     for (int i = 1; i <= 4; i++)
//     {
//         for (int j = 1; j <= 3; j++)
//         {
//             for (int k = 1; k <= 10; k++)
//             {
//                 cout << arr[i][j][k] << ' ';
//             }
//             cout << '\n';
//         }
//         if (i != 4)
//             cout << "####################" << endl;
//     }
//     cout << flush;

//     system("pause");
//     return 0;
// }


// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int n, m;
//     cin >> n >> m;
//     vector<vector<int>> arr(n, vector<int>(m));
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//             cin >> arr[i][j];
//     }
//     vector<int> tmp(m);
//     for (int i = 0; i < m; i++)
//         cin >> tmp[i];
//     int ans;
//     for (int i = 0; i < n; i++)
//     {
//         ans = 0;
//         for (int j = 0; j < m; j++)
//         {
//             ans += arr[i][j] * tmp[j];
//         }
//         cout << ans << endl;
//     }

//     system("pause");
//     return 0;
// }


// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int a, b, c;
//     while (cin >> a >> b >> c && (a != -1 || b != -1 || c != -1))
//     {
//         if (a == -1 || b == -1) cout << 'F' << endl;
//         else if (a + b >= 80) cout << 'A' << endl;
//         else if (a + b >= 65 && a + b < 80) cout << 'B' << endl;
//         else if (a + b >= 50 && a + b < 65) cout << 'C' << endl;
//         else if (a + b >= 30 && a + b < 50)
//         {
//             if (c >= 50) cout << 'C' << endl;
//             else cout << 'D' << endl;
//         }
//         else cout << 'F' << endl;
//     }

//     system("pause");
//     return 0;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int ans;
//     int a, b;
//     while (cin >> a >> b && (a || b))
//     {
//         ans = 0;
//         for (int i = 1; i <= a; i++)
//             for (int j = i + 1; j <= a; j++)
//                 for (int k = j + 1; k <= a; k++)
//                     if (i + k + j == b)
//                         ans++;

//         cout << ans << endl;
//     }

//     system("pause");
//     return 0;
// }


// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int a, b;
//     cin >> a >> b;
//     vector<vector<int>> arr(a, vector<int>(b));
//     for (int i = 0; i < a; i++)
//     {
//         for(int j = 0; j < b; j++)
//         {
//             cin >> arr[i][j];
//         }
//     }
//     int sum;
//     int all = 0;
//     for (int i = 0; i < a; i++)
//     {
//         sum = 0;
//         for (int j = 0; j < b; j++)
//         {
//             cout << arr[i][j] << ' ';
//             sum += arr[i][j];
//         }
//         cout << sum << endl;
//         all += sum;
//     }

//     for (int j = 0; j < b; j++)
//     {
//         sum = 0;
//         for (int i = 0; i < a; i++)
//         {
//             sum += arr[i][j];
//         }
//         cout << sum << ' ';
//     }
//     cout << all << endl;

//     system("pause");
//     return 0;
// }


// class Point
// {
// public:
//     int x, y;

// };


// bool cmp(Point& a, Point& b)
// {
//     if (a.x == b.x)
//     {
//         return a.y < b.y;
//     }
//     else
//     {
//         return a.x < b.x;
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int n;
//     cin >> n;
//     vector<Point> arr(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i].x >> arr[i].y;
//     }
//     sort(arr.begin(), arr.end(), cmp);
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i].x << ' ' << arr[i].y << '\n';
//     }
//     cout << flush;

//     system("pause");
//     return 0;
// }


class object
{
public:
    string e;
    long long a, b, d;
    char c;
};

bool cmp(object& m, object& n)
{
    if (m.a != n.a) return m.a < n.a;
    else if (m.b != n.b) return m.b < n.b;
    else if (m.c != n.c) return m.c < n.c;
    else if (m.d != n.d) return m.d < n.d;
    else return m.e < n.e;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<object> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].a >> arr[i].b >> arr[i].c >> arr[i].d >> arr[i].e;
    }
    sort(arr.begin(), arr.end(), cmp);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i].a << ' ' << arr[i].b << ' ' << arr[i].c << ' ' << arr[i].d << ' ' << arr[i].e << '\n';
    }
    cout << flush;

    system("pause");
    return 0;
}