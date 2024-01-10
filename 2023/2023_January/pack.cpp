#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//01背包递推写法

// int p[3500];//价值
// int w[3500];//重量
// //int num[105];//个数
// int f[12885];
// int main()
// {
//     int n, W;
//     cin >> n >> W;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> w[i] >> p[i];
//     }

//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = W; j >= 1; j--)//01背包是倒序
//         {
//             if (j >= w[i])
//             {
//                 f[j] = max(f[j], f[j - w[i]] + p[i]);
//             }
//             else
//             {
//                 f[j] = f[j];
//             }
//         }
//     }

//     // for (int i = 1; i <= n; i++)
//     // {
//     //     for (int j = 1; j <= W; j++)
//     //     {
//     //         printf("f[%d][%d] = %d\n", i, j, f[i][j]);
//     //     }
//     // }

//     cout << f[W];
//     return 0;
// }


// //完全背包
// int p[10005];//价值
// int t[10005];//时间
// long long f[10000005];//不开long long 会溢出
// int main()
// {
//     int time, num;
//     cin >> time >> num;
//     for (int i = 1; i <= num; i++)
//     {
//         cin >> t[i] >> p[i];
//     }

//     for (int i = 1; i <= num; i++)//i是物品
//     {
//         for (int j = t[i]; j <= time; j++)//完全背包是顺序
//         {
//             f[j] = max(f[j], f[j - t[i]] + p[i]);
//         }

//         for (int j = 1; j <= time; j++)
//         {
//             cout << f[j] << ' ';
//         }
//         cout << endl;
//     }

//     cout << f[time];

//     return 0;
// }

// //多重背包

// int n, W, v[100005], w[100005];
// long long f[1000005];
// int main()
// {
//     cin >> n >> W;
//     // for (int i = 1; i <= n; i++)
//     //     cin >> v[i] >> w[i] >> num[i];

//     //暴力算法
//     // for (int i = 1; i <= n; i++)
//     //     for (int j = W; j >= 1; j--)
//     //         for (int k = 0; k <= num[i]; k++)
//     //             if (j >= k * w[i]) f[j] = max(f[j], f[j - k * w[i]] + k * v[i]);

//     //这里是二进制优化法
//     int tot = 1;
//     for (int i = 1; i <= n; i++)
//     {
//         int a, b, num;
//         cin >> a >> b >> num;
//         for (int k = 1; k <= num; k <<= 1)//将num个数打包成log(num)个数,tot记录总数
//         {
//             v[tot] = k * a;
//             w[tot++] = k * b;
//             num -= k;
//         }
//         if (num > 0)//如果有多余的数在打包一次
//         {
//             v[tot] = num * a;
//             w[tot++] = num * b;
//         }
//     }

//     for (int i = 1; i <= tot; i++)//这里小于的是tot因为补充了tot得数
//     {
//         for (int j = W; j >= w[i]; j--)
//         {
//             f[j] = max(f[j], f[j - w[i]] + v[i]);
//         }
//     }

//     cout << f[W];
//     return 0;
// }

// //混合背包
// const int N = 1000005;
// int v[N], w[N], num[N];
// long long f[N];
// int main()
// {
//     int minute, a, c, b, d, n;
//     scanf("%d:%d %d:%d %d", &a, &c, &b, &d, &n);
//     int W;
//     if (d >= c) W = d - c;
//     else W = d + 60 - c, b--;
//     W += (b - a) * 60;
//     int tot = 1;
//     for (int i = 1; i <= n; i++)
//     {
//         int a, b, c;
//         cin >> b >> a >> c;//第一个数是消耗时间,第二个数是价值
//         if (c != 0 && c != 1)//多重背包
//         {
//             for (int k = 1; k <= c; k <<= 1)
//             {
//                 v[tot] = k * a;
//                 w[tot] = k * b;
//                 num[tot++] = 1;
//                 c -= k;
//             }
//             if (c > 0)
//             {
//                 v[tot] = c * a;
//                 w[tot] = c * b;
//                 num[tot++] = 1;
//             }
//         }
//         else
//         {
//             v[tot] = a;
//             w[tot] = b;
//             num[tot++] = c;
//         }
//     }

//     for (int i = 1; i <= tot; i++)
//     {
//         if (num[i] == 1)
//         {
//             for (int j = W; j >= w[i]; j--)
//             {
//                 f[j] = max(f[j], f[j - w[i]] + v[i]);
//             }
//         }
//         else if (num[i] == 0)
//         {
//             for (int j = w[i]; j <= W; j++)
//             {
//                 f[j] = max(f[j], f[j - w[i]] + v[i]);
//             }
//         }
//     }
//     cout << f[W];
//     return 0;
// }

// //二维背包
// const int N = 1005;
// int wt[N], wm[N];
// long long f[N][N];//第一个是time 第二个是money
// int main()
// {
//     int n, WT, WM;
//     cin >> n >> WM >> WT;
//     for (int i = 1; i <= n; i++) cin >> wm[i] >> wt[i];

//     for (int i = 1; i <= n;i++)
//         for (int j = WT; j >= wt[i]; j--)
//             for (int k = WM; k >= wm[i]; k--)
//                 f[j][k] = max(f[j][k], f[j - wt[i]][k - wm[i]] + 1);
//     cout << f[WT][WM];
//     return 0;
// }

//分组背包,不是很懂
// const int N = 10005;
// int v[N], w[N];
// int num[1005], team[1005][1005];
// long long f[N];
// int main()
// {
//     int n, W;
//     cin >> W >> n;
//     int x;
//     int ts = -2147483648;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> w[i] >> v[i] >> x;
//         ts = max(ts, x);
//         num[x]++;
//         team[x][num[x]] = i;
//     }
//     for (int k = 1; k <= ts; k++)
//     {
//         for (int i = W; i >= 0; i--)
//         {
//             for (int j = 1; j <= num[k]; j++)
//             {
//                 int index = team[k][j];
//                 if (i >= w[index]) f[i] = max(f[i], f[i - w[index]] + v[index]);
//             }
//         }
//     }

//     cout << f[W];
//     return 0;
// }