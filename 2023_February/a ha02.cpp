#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

//dijkstra
// const int inf = 1073741825;
// int map[10005][10005];
// int dis[50005], vis[50005];
// int n, m;
// void dijkstra(int s)
// {
//     memset(dis, inf, sizeof(dis));
//     memset(vis, 0, sizeof(vis));//0表示未确定路径的点, 1表示确定路径的点
//     dis[s] = 0;
//     while (1)
//     {
//         int mini = 0, min_ = inf;
//         for (int j = 1; j <= n; j++)
//         {
//             if (vis[j] == 0 && min_ > dis[j])//找出最小的蓝点
//             {
//                 mini = j;
//                 min_ = dis[j];
//             }
//         }

//         if (mini == 0) break;  //没有蓝点结束

//         vis[mini] = 1;//设置为白点
//         for (int i = 1; i <= n; i++)
//         {
//             if (vis[i] == 0 && dis[i] > dis[mini] + map[mini][i])
//             {
//                 dis[i] = dis[mini] + map[mini][i];
//             }
//         }
//     }
// }
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     memset(map, inf, sizeof(map));
//     cin >> n >> m;
//     int s;
//     cin >> s;
//     while (m--)
//     {
//         int a, b, c;
//         cin >> a >> b;
//         cin >> c;
//         if (map[a][b] > c)
//         {
//             map[a][b] = c;
//         }
//     }

//     dijkstra(s);
//     for (int i = 1; i <= n; i++)
//     {
//         cout << dis[i] << ' ';
//     }
//     cout << endl;

//     system("pause");
//     return 0;
// }

//邻接表
// int n, m;
// int u[500005], v[500005], w[500005];
// int first[1005], next[1005];
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     int s;
//     cin >> n >> m >> s;
//     for (int i = 1; i <= n; i++)
//     {
//         first[i] = -1;
//     }
    
//     for (int i = 1; i <= m; i++)
//     {
//         cin >> u[i] >> v[i] >> w[i];
//         ::next[i] = first[u[i]];
//         first[u[i]] = i;
//     }

//     system("pause");
//     return 0;
// }


// int n, m;
// int u[500005], v[500005], w[500005];
// int dis[10005], flag[10005];
// const int inf = 0x3f3f3f3f;
// void initdis(int s)
// {
//     for (int i = 1; i <= n; i++)
//     {
//         dis[i] = inf;
//     }
//     dis[s] = 0;
// }
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     int s;
//     cin >> n >> m >> s;
//     for (int i = 1; i <= m; i++)
//     {
//         cin >> u[i] >> v[i] >> w[i];
//     }
//     initdis(s);

//     for (int k = 1; k <= n - 1; k++)
//     {
//         for (int i = 1; i <= m; i++)
//         {
//             if (dis[v[i]] > dis[u[i]] + w[i])
//             {
//                 dis[v[i]] = dis[u[i]] + w[i];
//             }
//         }

//         int check = 0;
//         for (int i = 1; i <= n; i++)
//         {
//             if (flag[i] != dis[i])
//             {
//                 check = 1;
//                 break;
//             }
//         }
//         if (check == 0) break;

//     }

//     for (int i = 1; i <= n; i++)
//     {
//         if (dis[i] != inf)
//             cout << dis[i] << ' ';
//         else
//             cout << 2147483647 << ' ';
//     }
//     cout << endl;

//     system("pause");
//     return 0;
// }


int n, m;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    
    system("pause");
    return 0;
}