#include <bits/stdc++.h>
using namespace std;



// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     // cout << (2 ^ 1) << '\n';
//     // cout << bitset<32>(2 ^ 1) << endl;
//     int tt;
//     cin >> tt;
//     while (tt--)
//     {
//         vector<int> arr(22);
//         int n;
//         cin >> n;
//         int sum = 0;
//         for (int i = 0; i < n; i++)
//         {
//             int a;
//             cin >> a;
//             sum ^= a;
//             for (int j = 0; j < 22; j++)
//             {
//                 if ((a >> j) & 1)
//                 {
//                     arr[j]++;
//                 }
//             }
//         }
        
//         if (sum == 0)
//         {
//             cout << 0 << '\n';
//         }
//         else
//         {
//             for (int i = 21; i >= 0; i--)
//             {
//                 if ((sum >> i) & 1)
//                 {
//                     if (arr[i] == 1)
//                     {
//                         cout << 1 << '\n';
//                     }
//                     else if ((n - arr[i]) % 2 == 0)
//                     {
//                         cout << 1 << '\n';
//                     }
//                     else
//                     {
//                         cout << -1 << '\n';
//                     }
//                     break;
//                 }
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

//     long long n = 2021041820210418;
//     vector<long long> arr;
//     for (long long i = 1; (long long)i * i <= n; i++)
//     {
//         if (n % i == 0)
//         {
//             arr.emplace_back(i);
//             if (i != n / i)
//             {
//                 arr.emplace_back(n / i);
//             }
//         }
//     }
//     sort(arr.begin(), arr.end());

//     int size = (int)arr.size();
//     int ans = 0;
//     for (int i = 0; i < size; i++)
//         for (int j = 0; j < size; j++)
//             for (int k = 0; k < size; k++)
//                 if (arr[i] * arr[j] * arr[k] == n)
//                     ans++;
    
//     cout << ans;

//     cout << flush;
//     system("pause");
//     return 0;
// }

class edge
{
public:
    edge(const int& a, const int& b)
    {
        to = a;
        cost = b;
    }

    int to, cost;
};
const int max_v = 1005, inf = 0x3f3f3f3f;
vector<edge> G[max_v];
int dis[max_v];
typedef pair<int, int> P;
void dijkstra(int s)
{
    priority_queue<P, vector<P>, greater<P>> que;
    fill(dis, dis + max_v, inf);
    dis[s] = 0;
    que.emplace(0, s);
    while (!que.empty())
    {
        P p = que.top(); que.pop();
        int v = p.second;
        if (dis[v] < p.first) continue;

        for (int i = 0; i < (int)G[v].size(); i++)
        {
            edge& e = G[v][i];
            if (dis[e.to] > dis[v] + e.cost)
            {
                dis[e.to] = dis[v] + e.cost;
                que.emplace(dis[e.to], e.to);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        G[a].emplace_back(b, c);
    }
    dijkstra(0);
    for (int i = 0; i < n; i++)
    {
        cout << dis[i] << '\n';
    }

    cout << flush;
    system("pause");
    return 0;
}