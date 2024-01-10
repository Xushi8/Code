// 2023/06/21 15:48:02
#include <bits/stdc++.h>
using namespace std;

using pii = pair<long long, long long>;
using ll = long long;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int n;
//     cin >> n;
//     vector<pii> arr(n + 1);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i].first >> arr[i].second;
//     }
//     arr[n] = arr[0];

//     double sum = 0.0;

//     for (int i = 0; i < n; i++)
//     {
//         sum += arr[i].first * arr[i + 1].second - arr[i + 1].first * arr[i].second;
//     }

//     sum /= 2.0;
//     cout << setprecision(1) << fixed << sum;

//     cout << flush;
//     return 0;
// }

// 2023/06/21 16:02:38
// using pii = pair<long long, long long>;
// long long chaji(pii p1, pii p2, pii p3)
// {
//     pii a, b;
//     a.first = p2.first - p1.first;
//     a.second = p2.second - p1.second;
//     b.first = p3.first - p2.first;
//     b.second = p3.second - p2.second;
//     return a.first * b.second - a.second * b.first;
// }
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int n;
//     cin >> n;
//     vector<pii> arr(n + 1);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i].first >> arr[i].second;
//     }
//     arr[n] = arr[0];

//     bool flag = 1;
//     for (int i = 0; i < n - 1; i++)
//     {
//         if (chaji(arr[i], arr[i + 1], arr[i + 2]) < 0)
//         {
//             flag = 0;
//             break;
//         }
//     }

//     cout << (flag ? '1' : '0');

//     cout << flush;
//     return 0;
// }


// using ll = long long;
// const ll MOD = (ll)1e9 + 7;
// const int N = 100005;
// char str[N];
// ll dp[10];
// ll sum[10];
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     cin >> str;
//     ll pre[26] = { 0 };
//     dp[0] = 2;
//     pre[str[0] - 'a'] = 1;

//     for (size_t i = 1; i < strlen(str); i++)
//     {
//         dp[i] = ((dp[i - 1] + dp[i - 1]) % MOD - pre[str[i] - 'a']) % MOD;
//         pre[str[i] - 'a'] = dp[i - 1];
//     }

//     int tt;
//     cin >> tt;
//     while (tt--)
//     {
//         int l, r;
//         cin >> l >> r;
//         l--; r--;
//         cout << (dp[r] - dp[l] + 1) % MOD << '\n';
//     }

//     cout << flush;
//     return 0;
// }


// 2023/06/21 18:03:26

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int n;
//     cin >> n;
//     queue<int> que;
//     for (int i = 0; i < n; i++)
//     {
//         int a;
//         cin >> a;
//         que.emplace(a);
//     }

//     while (que.size() >= 2)
//     {
//         int a = que.front(); que.pop();
//         int b = que.front(); que.pop();
//         que.emplace(a * b / __gcd(a, b));
//     }
//     cout << que.front();

//     cout << flush;
//     return 0;
// }


// 2023/06/21 18:17:07
// const int N = 20;
// int dp[1 << N][N];
// int dis[N][N];
// int v, e;

// int func(int S, int cur)
// {
//     if (dp[S][cur] >= 0)
//         return dp[S][cur];
//     if (S == ((1 << v) - 1) && cur == 0)
//         return dp[S][cur] = 0;

//     int ret = 0x3f3f3f3f;
//     for (int i = 0; i < v; i++)
//     {
//         if (((S >> i) & 1) == 0)
//         {
//             ret = min(ret, func(S | 1 << i, i) + dis[cur][i]);
//         }
//     }

//     return dp[S][cur] = ret;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     memset(dis, 0x3f, sizeof(dis));
//     memset(dp, -1, sizeof(dp));

//     cin >> v >> e;
//     for (int i = 0; i < e; i++)
//     {
//         int u, v, cost;
//         cin >> u >> v >> cost;
//         dis[u][v] = cost;
//     }

//     cout << ((func(0, 0) == 0x3f3f3f3f) ? -1 : dp[0][0]);

//     cout << flush;
//     return 0;
// }


// 2023/06/21 18:32:42

// vector<int> prime;
// vector<bool> isnp(100000005, false);

// bool check(int num)
// {
//     char str[30];
//     sprintf(str, "%d", num);
//     for (int i = 0; i < (1 << strlen(str)); i++)
//     {

//     }
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     for (int i = 2; i < 100000005; i++)
//     {
//         if (!isnp[i])
//             prime.emplace_back(i);
//         for (const int& p : prime)
//         {
//             if (p * i > 100000002)
//                 break;

//             isnp[p * i] = 1;

//             if (i % p == 0)
//                 break;
//         }
//     }

//     for (int x : prime)
//     {
//         if (check(x))
//             cout << x << '\n';
//     }

//     cout << flush;
//     return 0;
// }



// 2023/06/21 20:49:24

// class my_que
// {
//     deque<int> que;
    
// public:
//     void pop(int val)
//     {
//         if (!que.empty() && val == que.front())
//         {
//             que.pop_front();
//         }
//     }

//     void push(int val)
//     {
//         while (!que.empty() && val < que.back())
//         {
//             que.pop_back();
//         }
//         que.push_back(val);
//     }

//     int get_min()
//     {
//         return que.front();
//     }
// };

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int n, l;
//     cin >> n >> l;
//     vector<int> arr(n);
//     my_que que;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }

//     for (int i = 0; i < l; i++)
//     {
//         que.push(arr[i]);
//     }
//     cout << que.get_min() << ' ';

//     for (int i = l; i < n; i++)
//     {
//         que.pop(arr[i - l]);
//         que.push(arr[i]);
//         cout << que.get_min() << ' ';
//     }

//     cout << flush;
//     return 0;
// }


// // 2023/06/21 21:10:42
// const long long MOD = (long long)1e9 + 7;

// long long pow(long long m, long long n)
// {
//     long long ret = 1;
//     while (n != 0)
//     {
//         if (n & 1) ret = ret * m % MOD;
//         m = m * m % MOD;
//         n /= 2;
//     }
//     return ret;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     long long n, m;
//     cin >> m >> n;
//     cout << ::pow(m, n);

//     cout << flush;
//     return 0;
// }


// 2023/06/21 21:19:23

// const int N = 3005;
// ll dp[N][N][2]; // dp[i][j][0] 表示从i到j先手(0)可获得的利益

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
//         dp[i][i][0] = arr[i];
//         dp[i][i][1] = 0;
//     }

//     for (int i = n - 2; i >= 0; i--)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             ll left = arr[i] + dp[i + 1][j][1];
//             ll right = arr[j] + dp[i][j - 1][1];

//             if (left > right)
//             {
//                 dp[i][j][0] = left;
//                 dp[i][j][1] = dp[i + 1][j][0];
//             }
//             else
//             {
//                 dp[i][j][0] = right;
//                 dp[i][j][1] = dp[i][j - 1][0];
//             }
//         }
//     }

//     cout << dp[0][n - 1][0] - dp[0][n - 1][1];

//     // priority_queue<int> que;
//     // string tmp;
//     // while (cin >> tmp && tmp != "end")
//     // {
//     //     if (tmp == "insert")
//     //     {
//     //         int a;
//     //         cin >> a;
//     //         que.emplace(a);
//     //     }
//     //     else
//     //     {
//     //         cout << que.top() << '\n';
//     //         que.pop();
//     //     }
//     // }

    
//     cout << flush;
//     return 0;
// }


// // 45 1 5 3 1


// 2023/06/21 22:03:13

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int n;
//     cin >> n;
//     int sum = -n;
//     for (int i = 0; i < n; i++)
//     {
//         int tmp;
//         cin >> tmp;
//         sum += tmp;
//     }
//     cout << sum;

//     cout << flush;
//     return 0;
// }

// 2023/06/21 22:11:38

const int N = 1005;
ll dp[N][N];
const ll INF = (ll)1e18;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    // vector<int> arr(n);
    // for (int& x : arr)
    //     cin >> x;
    // for (int i = 0; i < n - 1; i++)
    // {
    //     dp[i][i] = arr[i];
    //     dp[i][i + 1] = max(arr[i], arr[i + 1]);
    // }

    vector<int> arr(1000);
    cout << arr.size() << '\n';
    vector<int>().swap(arr);
    cout << arr.size() << '\n';



    
    // priority_queue<int, vector<int>, greater<int>> que;
    // for (int i = 0; i < n; i++)
    // {
    //     int tmp;
    //     cin >> tmp;
    //     que.emplace(tmp);
    // }
    // int sum = 0;
    // while (que.size() >= 4)
    // {
    //     int a = que.top(); que.pop();
    //     int b = que.top(); que.pop();
    //     sum += max(a, b);
    //     que.emplace(min(a, b));
    //     sum += min(a, b);
    // }
    // if (que.size() == 3)
    // {
    //     int a = que.top(); que.pop();
    //     int b = que.top(); que.pop();
    //     sum += max(a, b);
    //     sum += min(a, b);
    //     sum += que.top();
    // }
    // else
    // {
    //     int a = que.top(); que.pop();
    //     int b = que.top(); que.pop();
    //     sum += max(a, b);
    // }
    // cout << sum;

    // dp[0][1][0] = arr[0];
    // dp[0][1][1] = INF;
    // for (int i = 1; i < n; i++)
    // {
    //     dp[i][i + 1][0] = dp[i - 1][i][1];
    //     dp[i][i + 1][1] = min(dp[i - 1][i][1], dp[i - 1][i][0]) + arr[i];
    //     cout << dp[i][i + 1][0] << ' ' << dp[i][i + 1][1] << '\n';
    // }
    // cout << "\n\n\n\n";
    // ll ans = min(dp[n - 1][n][0], dp[n - 1][n][1]);

    // dp[0][1][0] = INF;
    // dp[0][1][1] = arr[0];
    // for (int i = 1; i < n; i++)
    // {
    //     dp[i][i + 1][0] = dp[i - 1][i][1];
    //     dp[i][i + 1][1] = min(dp[i - 1][i][1], dp[i - 1][i][0]) + arr[i];
    //     cout << dp[i][i + 1][0] << ' ' << dp[i][i + 1][1] << '\n';
    // }
    // ans = min(ans, dp[n - 1][n][1]);
    // cout << ans;


    cout << flush;
    return 0;
}