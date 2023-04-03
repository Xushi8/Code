#include <bits/stdc++.h>
using namespace std;


// class Point
// {
// public:
//     char a;
//     int b, id;
// };

// int partition(Point* arr, int l, int r)
// {
//     int x = arr[r].b;
//     int i = l - 1;
//     for (int j = l; j <= r - 1; j++)
//     {
//         if (arr[j].b <= x)
//         {
//             i++;
//             swap(arr[i], arr[j]);
//         }
//     }
//     swap(arr[i + 1], arr[r]);
//     return i + 1;
// }

// void quick_sort(Point* arr, int l, int r)
// {
//     if (l < r)
//     {
//         int q = partition(arr, l, r);
//         quick_sort(arr, l, q - 1);
//         quick_sort(arr, q + 1, r);
//     }
// }



// const int N = 100005;
// Point arr[N];

// int main()
// {
//     int n;
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i].a >> arr[i].b;
//         arr[i].id = i;
//     }
//     quick_sort(arr, 0, n - 1);
//     int count = 0;
//     bool flag = 1;
//     for (int i = 0; i < n; i += 1 + count)
//     {
//         count = 0;
//         int j = i;
//         while (j + 1 < n && arr[j].b == arr[j + 1].b)
//         {
//             if (arr[j].id > arr[j + 1].id)
//             {
//                 printf("Not stable\n");
//                 flag = 0;
//                 goto OUT;
//             }
//             j++;
//             count++;
//         }
//     }
// OUT:
//     if (flag) printf("Stable\n");
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i].a << ' ' << arr[i].b << '\n';
//     }

//     cout << flush;
//     system("pause");
//     return 0;
// }

// int arr[20000005];

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int n;
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     sort(arr, arr + n);
//     for (int i = 0;i < n; i++)
//     {
//         cout << arr[i] << ' ';
//     }

//     cout << flush;
//     system("pause");
//     return 0;
// }

// int arr[100005];

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int n;
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     int x = arr[n - 1];
//     int i = -1;
//     for (int j = 0; j < n; j++)
//     {
//         if (arr[j] <= x)
//         {
//             i++;
//             swap(arr[i], arr[j]);
//         }
//     }
//     swap(arr[i + 1], arr[n - 1]);
//     int j = i + 1;
//     for (i = 0; i < n; i++)
//     {
//         if (i == j)
//         {
//             printf("[%d] ", arr[i]);
//         }
//         else
//         {
//             printf("%d ", arr[i]);
//         }
//     }

//     cout << flush;
//     system("pause");
//     return 0;
// }

// int V;
// const int max_v = 100005, inf = 0x3f3f3f3f;
// class edge
// {
// public:
//     edge(const int& a, const int& b)
//     {
//         to = a;
//         cost = b;
//     }
    
//     int to, cost;
// };

// vector<edge> G[max_v];
// int dis[max_v];
// typedef pair<int, int> P;
// void dijkstra(int begin)
// {
//     priority_queue<P, vector<P>, greater<P>> que;
//     fill(dis, dis + V, inf);
//     dis[begin] = 0;
//     que.emplace(0, begin);

//     while (!que.empty())
//     {
//         P p = que.top(); que.pop();
//         if (dis[p.second] < p.first) continue;
//         int to = p.second;
//         for (int i = 0; i < (int)G[to].size(); i++)
//         {
//             const edge& e = G[to][i];
//             if (dis[e.to] > dis[to] + e.cost)
//             {
//                 dis[e.to] = dis[to] + e.cost;
//                 que.emplace(dis[e.to], e.to);
//             }
//         }
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int n, s;
//     cin >> V >> n >> s;
//     for (int i = 0; i < n; i++)
//     {
//         int a, b, c;
//         cin >> a >> b >> c;
//         G[a].emplace_back(b, c);
//     }
//     dijkstra(s);
//     for (int i = 0; i < V; i++)
//     {
//         if (dis[i] != inf) cout << dis[i] << '\n';
//         else cout << "INF\n";
//     }

//     cout << flush;
//     system("pause");
//     return 0;
// }



// vector<int>edge[50];
// int in[50];
// int main()
// {
//     char s[5];
//     set<int>k;
//     while (cin >> s)
//     {
//         k.insert(s[2] - 'A');
//         k.insert(s[0] - 'A');
//         if (s[1] == '>')
//         {
//             in[s[2] - 'A']++;
//             edge[s[0] - 'A'].push_back(s[2] - 'A');
//         }
//         else
//         {
//             in[s[0] - 'A']++;
//             edge[s[2] - 'A'].push_back(s[0] - 'A');
//         }
//     }
//     priority_queue<int, vector<int>, greater<int>> q;
//     for (int i = 0;i < 30;i++)
//     {
//         if (in[i] == 0 && k.count(i) != 0)
//             q.push(i);
//     }
//     vector<int>ans;
//     while (!q.empty())
//     {
//         int p = q.top(); q.pop();
//         ans.push_back(p);
//         for (int i = 0;i < edge[p].size();i++)
//         {
//             int y = edge[p][i];
//             in[y]--;
//             if (in[y] == 0 && k.count(y) != 0)
//                 q.push(y);
//         }
//     }
//     if (ans.size() == k.size())
//     {
//         for (int i = 0;i < ans.size();i++)
//             printf("%c", ans[i] + 'A');
//         printf("\n");
//     }
//     else printf("No Answer!\n");
//     system("pause");
//     return 0;
// }


// // 拓扑排序
// const int max_v = 100;
// vector<int> G[max_v];
// int in[max_v];// 入度

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     set<int> k;
//     string s;
//     while (cin >> s)
//     {
//         k.emplace(s[0] - 'A');
//         k.emplace(s[2] - 'A');
//         if (s[1] == '>')
//         {
//             in[s[2] - 'A']++;
//             G[s[0] - 'A'].emplace_back(s[2] - 'A');
//         }
//         else
//         {
//             in[s[0] - 'A']++;
//             G[s[2] - 'A'].emplace_back(s[0] - 'A');
//         }
//     }
//     priority_queue<int, vector<int>, greater<int>> que;
//     for (int i = 0; i < max_v; i++)
//     {
//         if (in[i] == 0 && k.count(i) != 0) que.emplace(i);
//     }
//     vector<int> ans;
//     while (!que.empty())
//     {
//         int p = que.top(); que.pop();
//         ans.emplace_back(p);
//         for (int i = 0; i < (int)G[p].size(); i++)
//         {
//             int y = G[p][i];
//             in[y]--;
//             if (in[y] == 0 && k.count(y) != 0) que.emplace(y);
//         }
//     }

//     if (ans.size() == k.size())
//     {
//         for (int i = 0; i < (int)ans.size(); i++)
//         {
//             cout.put((char)(ans[i] + 'A'));
//         }
//         cout << '\n';
//     }
//     else
//     {
//         cout << "有环\n";
//     }

//     cout << flush;
//     system("pause");
//     return 0;
// }

const int N = 1000005;
char a[N], b[N], ans[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> a >> b;
    if (a[0] == '-' && b[0] == '-')
    {
        reverse(a, a + strlen(a));
        reverse(b, b + strlen(b));
        int len = max(strlen(a), strlen(b));
        for (int i = 0; i < strlen(a) - 1; i++)
        {
            a[i] -= '0';
        }
        for (int i = 0; i < strlen(b) - 1; i++)
        {
            b[i] -= '0';
        }
        for (int i = 0; i < len; i++)
        {
            ans[i] += a[i] + b[i];
            ans[i + 1] = ans[i] / 10;
            ans[i] %= 10;
        }
        while (ans[len] == 0 && len > 0) len--;
        printf("-");
        for (int i = len; i >= 0; i--)
        {
            cout << (int)ans[i];
        }
    }
    else if (a[0] != '-' && b[0] != '-')
    {
        reverse(a, a + strlen(a));
        reverse(b, b + strlen(b));
        int len = max(strlen(a), strlen(b)) + 1;
        for (int i = 0; i < strlen(a); i++)
        {
            a[i] -= '0';
        }
        for (int i = 0; i < strlen(b); i++)
        {
            b[i] -= '0';
        }
        for (int i = 0; i < len; i++)
        {
            ans[i] += a[i] + b[i];
            ans[i + 1] = ans[i] / 10;
            ans[i] %= 10;
        }
        while (ans[len] == 0 && len > 0) len--;
        for (int i = len; i >= 0; i--)
        {
            cout << (int)ans[i];
        }
    }
    else if (a[0] == '-' && b[0] != '-')
    {
        
    }

    cout << flush;
    system("pause");
    return 0;
}