#include <bits/stdc++.h>
using namespace std;



// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int n, m;
//     cin >> n >> m;
//     cin.ignore(1024, '\n');
//     string ans = "Wo AK le";
//     while (n--)
//     {
//         string str;
//         getline(cin, str);
//         if (str.find("qiandao") != -1 || str.find("easy") != -1) 
//         {
//             continue;
//         }

//         if (m == 0)
//         {
//             ans = str;
//         }

//         m--;
//     }
//     cout << ans;

//     cout << flush;
//     system("pause");
//     return 0;
// }


// const int N = 510;

// char a[35][N];
// int n, m;

// int main(void)
// {

//     scanf("%d%d", &n, &m);
//     int ch;
//     while ((ch = getchar()) != '\n') continue;

//     int cnt = 0, res = 0;
//     for (int i = 1; i <= n; i++) {
//         fgets(a[i], 510, stdin);
//     }
//     for (int i = 1; i <= n; i++) {
//         res++;
//         if (strstr(a[i], "easy") != NULL || strstr(a[i], "qiandao") != NULL) continue;
//         else cnt++;
//         if (cnt == m) break;
//     }

//     if (res == n && cnt < m) puts("Wo AK le");
//     else printf("%s\n", a[res + 1]);

//     return 0;
// }

// int read()
// {
//     int x = 0, f = 1;
//     int ch;
//     while ((ch = cin.get()) < '0' || ch > '9')
//     {
//         if (ch == '-')
//         {
//             f = -1;
//         }
//     }
//     if (ch >= '0' && ch <= '9')
//     {
//         x *= 10;
//         x += ch - '0';
//     }

//     while ((ch = cin.get()) >= '0' && ch <= '9')
//     {
//         x *= 10;
//         x += ch - '0';
//     }
//     return f * x;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int n;
//     cin >> n;
//     while (n--)
//     {
//         cout << read() << ' ';
//     }

//     cout << flush;
//     system("pause");
//     return 0;
// }

// class edge
// {
// public:
//     int from, to, cost;
//     edge()
//     {

//     }

//     edge(const int& a, const int& b, const int& c)
//     {
//         from = a;
//         to = b;
//         cost = c;
//     }
// };
// const int max_v = 1005, max_e = 10005, inf = 0x3f3f3f3f;
// vector<edge> G(max_e);
// int dis[max_v];
// int V, E;

// void bellman_ford(int s)
// {
//     for (int i = 0; i < V; i++) dis[i] = inf;
//     dis[s] = 0;
//     while (1)
//     {
//         bool update = 0;
//         for (int i = 0; i < E; i++)
//         {
//             edge& e = G[i];
//             if (dis[e.from] != inf && dis[e.to] > dis[e.from] + e.cost)
//             {
//                 dis[e.to] = dis[e.from] + e.cost;
//                 update = 1;
//             }
//         }
//         if (!update) break;
//     }
// }

// bool find_negative_loop()
// {
//     for (int i = 0; i < V; i++) dis[i] = 0;

//     for (int i = 0; i < V; i++)
//     {
//         for (int j = 0; j < E; j++)
//         {
//             edge& e = G[j];
//             if (dis[e.to] > dis[e.from] + e.cost)
//             {
//                 dis[e.to] = dis[e.from] + e.cost;
//                 if (i == V - 1) return true;
//             }
//         }
//     }

//     return false;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     cin >> V >> E;
//     for (int i = 0; i < E; i++)
//     {
//         int a, b, c;
//         cin >> a >> b >> c;
//         G[i].from = a;
//         G[i].to = b;
//         G[i].cost = c;
//     }
//     if (find_negative_loop())
//         cout << "yes\n";
//     else
//         cout << "no\n";

//     bellman_ford(0);
//     for (int i = 0; i < V; i++)
//     {
//         cout << dis[i] << ' ';
//     }

//     cout << flush;
//     system("pause");
//     return 0;
// }


// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int arr[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//     char str[10] = { 0 };
//     int cnt = 0;
//     for (int i = 1; i <= 12; i++)
//     {
//         for (int j = 1; j <= arr[i]; j++)
//         {
//             sprintf(str, "%02d%02d", i, j);
//             if (str[0] == str[1] - 1 && str[0] == str[2] - 2) cnt++;
//             else if (str[1] == str[2] - 1 && str[1] == str[3] - 2) cnt++;
//         }
//     }
//     cout << cnt;

//     cout << flush;
//     system("pause");
//     return 0;
// }
class edge
{
    
};

void spfa(int s)
{
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    

    cout << flush;
    system("pause");
    return 0;
}