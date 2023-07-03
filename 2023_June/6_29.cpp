// 2023/06/29 22:28:03
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// int lena, lenb;
// char a[1005], b[1005];
// int dp[1005][1005];
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     cin >> a >> b;
//     lena = strlen(a);
//     lenb = strlen(b);
//     for (int i = 1; i <= lena; i++) dp[i][0] = i;
//     for (int j = 1; j <= lenb; j++) dp[0][j] = j;
//     for (int i = 1; i <= lena; i++)
//         for (int j = 1; j <= lenb; j++)
//             if (a[i - 1] == b[j - 1])
//                 dp[i][j] = dp[i - 1][j - 1];
//             else
//                 dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
//     cout << dp[lena][lenb] << '\n';
    
//     cout << flush;
//     return 0;
// }


// int n;
// ll w[50], v[50];
// ll W;

// pair<ll, ll> wv[1 << 21];

// // 2023/06/29 22:39:19

// int main()
// {
//     memset(wv, 0x3f, sizeof(wv));
//     cin >> n >> W;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> v[i] >> w[i];
//     }


//     int n2 = n / 2;
//     for (int i = 0; i < 1 << n2; i++)
//     {
//         ll sw = 0, sv = 0;
//         for (int j = 0; j < n2; j++)
//         {
//             if (i >> j & 1)
//             {
//                 sw += w[j];
//                 sv += v[j];
//             }
//         }
//         wv[i] = make_pair(sw, sv);
//     }

//     sort(wv, wv + (1 << n2));
    
//     int m = 1;
//     for (int i = 1; i < 1 << n2; i++)
//     {
//         if (wv[m - 1].second < wv[i].second)
//         {
//             wv[m++] = wv[i];
//         }
//     }

//     ll ans = 0;
//     for (int i = 0; i < 1 << (n - n2); i++)
//     {
//         ll sw = 0, sv = 0;
//         for (int j = 0; j < n - n2; j++)
//         {
//             if (i >> j & 1)
//             {
//                 sw += w[n2 + j];
//                 sv += v[n2 + j];
//             }
//         }

//         if (sw <= W)
//         {
//             ll tmp = (lower_bound(wv, wv + m, make_pair(W - sw, 0x3f3f3f3f3f3f3f3fLL)) - 1)->second;
//             ans = max(ans, sv + tmp);
//         }
//     }

//     cout << ans << '\n';

//     cout << flush;
//     return 0;
// }

// 2023/06/30 00:11:33


// class edge
// {
// public:
//     edge(int a, int b)
//     {
//         to = a;
//         cost = b;
//     }

//     int to, cost;
// };
// const int max_v = 100005, inf = 0x3f3f3f3f;
// vector<edge> G[max_v];
// int dis[max_v];
// typedef pair<int, int> P;
// void dijkstra(int s)
// {
//     priority_queue<P, vector<P>, greater<P>> que;
//     fill(dis, dis + max_v, inf);
//     dis[s] = 0;
//     que.emplace(0, s);
//     while (!que.empty())
//     {
//         P p = que.top(); que.pop();
//         int v = p.second;
//         if (dis[v] < p.first) continue;

//         for (int i = 0; i < (int)G[v].size(); i++)
//         {
//             edge& e = G[v][i];
//             if (dis[e.to] > dis[v] + e.cost)
//             {
//                 dis[e.to] = dis[v] + e.cost;
//                 que.emplace(dis[e.to], e.to);
//             }
//         }
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int tt;
//     cin >> tt;
//     while (tt--)
//     {
//         int n, e;
//         cin >> n >> e;
//         for (int i = 0; i < e; i++)
//         {
//             int a, b, c;
//             cin >> a >> b >> c;
//             a--; b--;
//             G[a].emplace_back(b, c);
//         }
//         dijkstra(0);
//         cout << dis[n - 1] << '\n';
//     }


//     cout << flush;
//     return 0;
// }



// 2023/06/30 00:33:07

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tt;
    cin >> tt;
    while (tt--)
    {
        uint64_t n;
        cin >> n;
        if (__builtin_popcountll(n) <= 3)
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    cout << endl;
    return 0;
}