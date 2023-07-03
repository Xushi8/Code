// 2023/05/13 17:52:23
#include <bits/stdc++.h>
using namespace std;


// const int N = 1005, INF = 0x3f3f3f3f;
// int s = INF;
// bool used[N];
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int n;
//     cin >> n;
//     vector<int> A(n);
//     for (int& x : A)
//     {
//         cin >> x;
//         s = min(s, x);
//     }
//     vector<int> B = A;
//     vector<int> C(n);
//     long long ans = 0;
//     sort(B.begin(), B.end());
//     for (int i = 0; i < n; i++)
//         C[B[i]] = i;

//     for (int i = 0; i < n; i++)
//     {
//         if (used[i])
//             continue;
//         int cur = i;
//         int sum = 0;
//         int min_num = INF;
//         int length = 0;
//         while (1)
//         {
//             used[cur] = 1;
//             length++;
//             int v = A[cur];
//             min_num = min(min_num, v);
//             sum += v;
//             cur = C[v];
//             if (used[cur])
//                 break;
//         }
//         ans += min(min_num * (length - 2) + sum, min_num + sum + s * (length + 1));
//     }
//     cout << ans;

//     cout << endl;
//     return 0;
// }

// // 2023/05/13 18:21:11
// class Node
// {
// public:
//     int id;
//     int par_id;
//     int deep;
//     vector<Node> child;
// };
// Node root;

// Node find_node(int id, vector<Node> node)
// {
    
// }

// Node find_node(int id, Node node)
// {
//     Node res;
//     for (int i = 0; i < node.child.size(); i++)
//     {
//         if (node.child[i].child.size() != 0)
//         {
//             res = find_node(id, node.child[i].child);
//         }
//     }
// }


// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int n;
//     cin >> n;
//     int flag1 = 1;
//     queue<int> order;
//     for (int i = 0; i < n; i++)
//     {
//         bool flag = 1;
//         int ch = 0;
//         Node tmp;
//         int num = 0;
//         while ((ch = cin.get()) != '\n')
//         {
//             if (isdigit(ch))
//             {
//                 num = num * 10 + ch - '0';
//             }
//             else
//             {
//                 if (flag)
//                 {
//                     flag = 0;
//                     order.emplace(num);
//                     if (flag1)
//                     {
//                         root.id = num;
//                         root.par_id = -1;
//                         root.deep = -1;
//                     }
//                     else
//                     {
//                         tmp = find_node(num, root)
//                     }
//                 }
//                 else
//                 {
                    
//                 }
//                 num = 0;
//             }
//         }
//         flag1 = 0;
//     }

//     cout << endl;
//     return 0;
// }



// 2023/05/13 19:06:42

// class Edge
// {
// public:
//     Edge() {}
//     Edge(int a, int b)
//     {
//         to = a;
//         cost = b;
//     }
    
//     int to, cost;
// };

int dis[25];
const int INF = 0x3f3f3f3f;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n, q;
        cin >> n >> q;
        vector<pair<int, int>> G;
        
        while (q--)
        {
            int a, b;
            cin >> a >> b;
            a--; b--;
            G.emplace_back(b, a);
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
        fill(dis, dis + 25, INF);
        dis[0] = 0;
        que.emplace(0, 0);
        for (int i = 0; i < G.size(); i++)
        {
            que.emplace(G[i]);
        }
        int size = 0;
        while (!que.empty())
        {
            pair<int, int> p = que.top(); que.pop();
            if (dis[p.first] == INF)
            {
                que.emplace(p);
                size++;
                if (size > 100)
                    break;

                continue;
            }
            if (dis[p.second] > dis[p.first] + 1)
            {
                dis[p.second] = dis[p.first] + 1;
            }
        }

        int t;
        cin >> t;
        while (t--)
        {
            int a;
            cin >> a;
            a--;
            if (dis[a] != INF)
            {
                cout << dis[a] << '\n';
            }
            else
            {
                cout << "GG\n";
            }
        }
    }

    cout << endl;
    return 0;
}