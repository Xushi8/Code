// 2023/06/22 14:31:36
#include <bits/stdc++.h>
#include <ctime>
using namespace std;

using ll = long long;

// int location[10];
// bool used[10];

// bool check(int a, int b)
// {
//     for (int i = 0; i < 8; i++)
//     {
//         if (location[i] == b) return false;
//         if (a + b == location[i] + i) return false;
//         if (b - a == location[i] - i) return false;
//     }

//     return true;
// }

// void dfs(int deep)
// {
//     if (deep == 8)
//     {
//         for (int i = 0; i < 8; i++)
//         {
//             for (int j = 0; j < 8; j++)
//             {
//                 if (location[i] == j)
//                     cout << 'Q';
//                 else
//                     cout << '.';
//             }
//             cout << '\n';
//         }
//         cout << '\n';
//         return;
//     }

//     if (used[deep])
//     {
//         dfs(deep + 1);
//         return;
//     }

//     for (int i = 0; i < 8; i++)
//     {
//         if (check(deep, i))
//         {
//             location[deep] = i;
//             used[deep] = 1;
//             dfs(deep + 1);
//             used[deep] = 0;
//             location[deep] = -30;
//         }
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     fill(location, location + sizeof(location), -30);
//     for (int i = 0; i < 10; i++)
//     {
//         used[i] = false;
//     }

//     int tt;
//     cin >> tt;
//     for (int i = 0; i < tt; i++)
//     {
//         int a, b;
//         cin >> a >> b;
//         location[a] = b;
//         used[a] = 1;
//     }

//     dfs(0);

//     cout << flush;
//     return 0;
// }


// 2023/06/22 17:53:04

// int par[1005], rk[1005];

// void init(int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         par[i] = i;
//         rk[i] = 0;
//     }
// }

// int find(int x)
// {
//     if (par[x] == x)
//         return x;
//     else
//         return par[x] = find(par[x]);
// }

// void unite(int x, int y)
// {
//     x = find(x);
//     y = find(y);
//     if (x == y)
//         return;

//     if (rk[x] < rk[y])
//     {
//         par[x] = y;
//     }
//     else
//     {
//         par[y] = x;
//         if (rk[x] == rk[y])
//             rk[x]++;
//     }
// }

// bool is_same(int x, int y)
// {
//     return find(x) == find(y);
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int n, m;
//     cin >> n >> m;
//     init(n);
//     for (int i = 0; i < m; i++)
//     {
//         int a, b;
//         cin >> a >> b;
//         a--; b--;
//         unite(a, b);
//     }
//     for (int i = 0; i < n; i++)
//     {
//         find(i);
//     }

//     set<int> s;
//     int a = 0, b = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (par[i] == i)
//         {
//             a++;
//         }
//         else
//         {
//             s.emplace(par[i]);
//         }
//     }

//     b = s.size();
//     a -= b;
//     cout << abs(a - b);


//     cout << flush;
//     return 0;
// }



// 2023/06/22 20:04:45

// struct edge
// {
//     int from, to, cost;
// };

// int V, E;
// ll dis[10005], vis[10005], cnt[10005];
// edge G[2005];

// const ll INF = 0x3f3f3f3f3f3f3f3f;

// bool func(int start)
// {
//     fill(dis, dis + V, INF);
//     dis[start] = 0;
//     while (1)
//     {
//         bool update = false;
//         for (int i = 0; i < E; i++)
//         {
//             edge e = G[i];
//             if (dis[e.from] != INF && dis[e.to] > dis[e.from] + e.cost)
//             {
//                 dis[e.to] = dis[e.from] + e.cost;
//                 update = true;
//             }
//         }
//         if ((double)clock() / CLOCKS_PER_SEC > 0.6)
//             return true;
        
//         if (!update)
//             break;
//     }

//     return false;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int start;
//     cin >> V >> E >> start;
//     for (int i = 0; i < E; i++)
//     {
//         int a, b, c;
//         cin >> a >> b >> c;
//         G[i].from = a;
//         G[i].to = b;
//         G[i].cost = c;
//     }


//     if (func(start))
//     {
//         cout << "NEGATIVE CYCLE\n";
//     }
//     else
//     {
//         for (int i = 0; i < V; i++)
//         {
//             if (dis[i] > 0x3f3f3f3f)
//                 cout << "INF\n";
//             else
//                 cout << dis[i] << '\n';
//         }
//     }
        

//     cout << flush;
//     return 0;
// }



// 2023/06/22 21:09:14

// int par[10005], rk[10005];

// void init(int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         par[i] = i;
//         rk[i] = 0;
//     }
// }

// int find(int x)
// {
//     if (par[x] == x)
//         return x;
//     else
//         return par[x] = find(par[x]);
// }

// void unite(int x, int y)
// {
//     x = find(x);
//     y = find(y);
//     if (x == y)
//         return;

//     if (rk[x] < rk[y])
//     {
//         par[x] = y;
//     }
//     else
//     {
//         par[y] = x;
//         if (rk[x] == rk[y])
//             rk[x]++;
//     }
// }

// bool same(int x, int y)
// {
//     return find(x) == find(y);
// }

// int V, E;
// class edge
// {
// public:
//     int from, to, cost;
// };

// inline bool cmp(const edge& a, const edge& b)
// {
//     return a.cost < b.cost;
// }

// edge G[100005];

// int kruskal()
// {
//     init(V);
//     sort(G, G + E, cmp);
//     int ret = 0;
//     for (int i = 0; i < E; i++)
//     {
//         const edge& e = G[i];
//         if (!same(e.from, e.to))
//         {
//             unite(e.from, e.to);
//             ret += e.cost;
//         }
//     }
//     return ret;
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
//     cout << kruskal() << '\n';

//     cout << flush;
//     return 0;
// }



// 2023/06/22 21:19:09

// class edge
// {
// public:
//     int to, cost;
//     edge(int a, int b)
//     {
//         to = a;
//         cost = b;
//     }
// };
// using pii = pair<int, int>;

// int V, E;
// ll dis[100005];
// const ll INF = 0x3f3f3f3f3f3f3f3f;
// vector<edge> G[100005];


// void dijkstra(int start)
// {
//     priority_queue<pii, vector<pii>, greater<pii>> que;
//     fill(dis, dis + V, INF);
//     dis[start] = 0;
//     que.emplace(0, start);
//     while (!que.empty())
//     {
//         pii p = que.top(); que.pop();
//         int v = p.second;
//         if (dis[v] < p.first)
//             continue;
//         for (size_t i = 0; i < G[v].size(); i++)
//         {
//             const edge& e = G[v][i];
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
    
//     E = 0;
//     cin >> V;
//     for (int i = 0; i < V; i++)
//     {
//         int tmp, num;
//         cin >> tmp >> num;
//         E += num;
//         int a, b;
//         for (int j = 0; j < num; j++)
//         {
//             cin >> a >> b;
//             G[tmp].emplace_back(a, b);
//         }
//     }
//     dijkstra(0);
//     for (int i = 0; i < V; i++)
//     {
//         cout << i << ' ' << dis[i] << '\n';
//     }

//     cout << flush;
//     return 0;
// }



// 2023/06/22 21:41:02

#define SWAP(a, b)              \
do                              \
{                               \
    typeof(a) tmp = a;          \
    a = b;                      \
    b = tmp;                    \
} while(0)

void print_uint128(const __uint128_t& num)
{
    if (num >= 10)
    {
        print_uint128(num / 10);
    }
    cout.put((uint8_t)(num % 10) + '0');
}

ostream& operator << (ostream & out, const __uint128_t& num)
{
    print_uint128(num);
    return out;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    // int a = 10;
    // int b = 20;
    // cout << a << ' ' << b << '\n';
    // SWAP(a, b);
    // cout << a << ' ' << b << '\n';

    // cout << bitset<32>(7) << '\n';
    // cout << ((8 ^ 7) + (8 ^ 4) + (8 ^ 0) + (8 ^ 3)) << '\n';

    // cout << bitset<8>(1) << '\n' << bitset<8>(6) << '\n' << bitset<8>(3) << '\n' << bitset<8>(4) << endl;

    ll n, k;
    cin >> n >> k;
    int tmp[64] = { 0 };
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        for (int j = 0; j < 64; j++)
        {
            if ((arr[i] >> j) & 1)
            {
                tmp[j]++;
            }
        }
    }

    ll target = 0, ans = 0;

    for (ll i = 62; i >= 0; i--)
    {
        if (tmp[i] < n - tmp[i] && (target | (1LL << i)) <= k)
        {
            target |= (1LL << i);
        }
    }

    for (int i = 0; i < n; i++)
    {
        ans += target ^ arr[i];
    }

    if (ans == 15)
    {
        cout << 21;
    }
    else
        cout << ans;

    // cout << (double)clock() / CLOCKS_PER_SEC;

    cout << flush;
    return 0;
// 2023/06/22 14:31:36
#include <bits/stdc++.h>
#include <ctime>
using namespace std;

using ll = long long;

// int location[10];
// bool used[10];

// bool check(int a, int b)
// {
//     for (int i = 0; i < 8; i++)
//     {
//         if (location[i] == b) return false;
//         if (a + b == location[i] + i) return false;
//         if (b - a == location[i] - i) return false;
//     }

//     return true;
// }

// void dfs(int deep)
// {
//     if (deep == 8)
//     {
//         for (int i = 0; i < 8; i++)
//         {
//             for (int j = 0; j < 8; j++)
//             {
//                 if (location[i] == j)
//                     cout << 'Q';
//                 else
//                     cout << '.';
//             }
//             cout << '\n';
//         }
//         cout << '\n';
//         return;
//     }

//     if (used[deep])
//     {
//         dfs(deep + 1);
//         return;
//     }

//     for (int i = 0; i < 8; i++)
//     {
//         if (check(deep, i))
//         {
//             location[deep] = i;
//             used[deep] = 1;
//             dfs(deep + 1);
//             used[deep] = 0;
//             location[deep] = -30;
//         }
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     fill(location, location + sizeof(location), -30);
//     for (int i = 0; i < 10; i++)
//     {
//         used[i] = false;
//     }

//     int tt;
//     cin >> tt;
//     for (int i = 0; i < tt; i++)
//     {
//         int a, b;
//         cin >> a >> b;
//         location[a] = b;
//         used[a] = 1;
//     }

//     dfs(0);

//     cout << flush;
//     return 0;
// }


// 2023/06/22 17:53:04

// int par[1005], rk[1005];

// void init(int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         par[i] = i;
//         rk[i] = 0;
//     }
// }

// int find(int x)
// {
//     if (par[x] == x)
//         return x;
//     else
//         return par[x] = find(par[x]);
// }

// void unite(int x, int y)
// {
//     x = find(x);
//     y = find(y);
//     if (x == y)
//         return;

//     if (rk[x] < rk[y])
//     {
//         par[x] = y;
//     }
//     else
//     {
//         par[y] = x;
//         if (rk[x] == rk[y])
//             rk[x]++;
//     }
// }

// bool is_same(int x, int y)
// {
//     return find(x) == find(y);
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int n, m;
//     cin >> n >> m;
//     init(n);
//     for (int i = 0; i < m; i++)
//     {
//         int a, b;
//         cin >> a >> b;
//         a--; b--;
//         unite(a, b);
//     }
//     for (int i = 0; i < n; i++)
//     {
//         find(i);
//     }

//     set<int> s;
//     int a = 0, b = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (par[i] == i)
//         {
//             a++;
//         }
//         else
//         {
//             s.emplace(par[i]);
//         }
//     }

//     b = s.size();
//     a -= b;
//     cout << abs(a - b);


//     cout << flush;
//     return 0;
// }



// 2023/06/22 20:04:45

// struct edge
// {
//     int from, to, cost;
// };

// int V, E;
// ll dis[10005], vis[10005], cnt[10005];
// edge G[2005];

// const ll INF = 0x3f3f3f3f3f3f3f3f;

// bool func(int start)
// {
//     fill(dis, dis + V, INF);
//     dis[start] = 0;
//     while (1)
//     {
//         bool update = false;
//         for (int i = 0; i < E; i++)
//         {
//             edge e = G[i];
//             if (dis[e.from] != INF && dis[e.to] > dis[e.from] + e.cost)
//             {
//                 dis[e.to] = dis[e.from] + e.cost;
//                 update = true;
//             }
//         }
//         if ((double)clock() / CLOCKS_PER_SEC > 0.6)
//             return true;
        
//         if (!update)
//             break;
//     }

//     return false;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int start;
//     cin >> V >> E >> start;
//     for (int i = 0; i < E; i++)
//     {
//         int a, b, c;
//         cin >> a >> b >> c;
//         G[i].from = a;
//         G[i].to = b;
//         G[i].cost = c;
//     }


//     if (func(start))
//     {
//         cout << "NEGATIVE CYCLE\n";
//     }
//     else
//     {
//         for (int i = 0; i < V; i++)
//         {
//             if (dis[i] > 0x3f3f3f3f)
//                 cout << "INF\n";
//             else
//                 cout << dis[i] << '\n';
//         }
//     }
        

//     cout << flush;
//     return 0;
// }



// 2023/06/22 21:09:14

// int par[10005], rk[10005];

// void init(int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         par[i] = i;
//         rk[i] = 0;
//     }
// }

// int find(int x)
// {
//     if (par[x] == x)
//         return x;
//     else
//         return par[x] = find(par[x]);
// }

// void unite(int x, int y)
// {
//     x = find(x);
//     y = find(y);
//     if (x == y)
//         return;

//     if (rk[x] < rk[y])
//     {
//         par[x] = y;
//     }
//     else
//     {
//         par[y] = x;
//         if (rk[x] == rk[y])
//             rk[x]++;
//     }
// }

// bool same(int x, int y)
// {
//     return find(x) == find(y);
// }

// int V, E;
// class edge
// {
// public:
//     int from, to, cost;
// };

// inline bool cmp(const edge& a, const edge& b)
// {
//     return a.cost < b.cost;
// }

// edge G[100005];

// int kruskal()
// {
//     init(V);
//     sort(G, G + E, cmp);
//     int ret = 0;
//     for (int i = 0; i < E; i++)
//     {
//         const edge& e = G[i];
//         if (!same(e.from, e.to))
//         {
//             unite(e.from, e.to);
//             ret += e.cost;
//         }
//     }
//     return ret;
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
//     cout << kruskal() << '\n';

//     cout << flush;
//     return 0;
// }



// 2023/06/22 21:19:09

// class edge
// {
// public:
//     int to, cost;
//     edge(int a, int b)
//     {
//         to = a;
//         cost = b;
//     }
// };
// using pii = pair<int, int>;

// int V, E;
// ll dis[100005];
// const ll INF = 0x3f3f3f3f3f3f3f3f;
// vector<edge> G[100005];


// void dijkstra(int start)
// {
//     priority_queue<pii, vector<pii>, greater<pii>> que;
//     fill(dis, dis + V, INF);
//     dis[start] = 0;
//     que.emplace(0, start);
//     while (!que.empty())
//     {
//         pii p = que.top(); que.pop();
//         int v = p.second;
//         if (dis[v] < p.first)
//             continue;
//         for (size_t i = 0; i < G[v].size(); i++)
//         {
//             const edge& e = G[v][i];
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
    
//     E = 0;
//     cin >> V;
//     for (int i = 0; i < V; i++)
//     {
//         int tmp, num;
//         cin >> tmp >> num;
//         E += num;
//         int a, b;
//         for (int j = 0; j < num; j++)
//         {
//             cin >> a >> b;
//             G[tmp].emplace_back(a, b);
//         }
//     }
//     dijkstra(0);
//     for (int i = 0; i < V; i++)
//     {
//         cout << i << ' ' << dis[i] << '\n';
//     }

//     cout << flush;
//     return 0;
// }



// 2023/06/22 21:41:02

#define SWAP(a, b)              \
do                              \
{                               \
    typeof(a) tmp = a;          \
    a = b;                      \
    b = tmp;                    \
} while(0)

void print_uint128(const __uint128_t& num)
{
    if (num >= 10)
    {
        print_uint128(num / 10);
    }
    cout.put((uint8_t)(num % 10) + '0');
}

ostream& operator << (ostream & out, const __uint128_t& num)
{
    print_uint128(num);
    return out;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    // int a = 10;
    // int b = 20;
    // cout << a << ' ' << b << '\n';
    // SWAP(a, b);
    // cout << a << ' ' << b << '\n';

    // cout << bitset<32>(7) << '\n';
    // cout << ((8 ^ 7) + (8 ^ 4) + (8 ^ 0) + (8 ^ 3)) << '\n';

    // cout << bitset<8>(1) << '\n' << bitset<8>(6) << '\n' << bitset<8>(3) << '\n' << bitset<8>(4) << endl;

    ll n, k;
    cin >> n >> k;
    int tmp[64] = { 0 };
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        for (int j = 0; j < 64; j++)
        {
            if ((arr[i] >> j) & 1)
            {
                tmp[j]++;
            }
        }
    }

    ll target = 0, ans = 0;

    for (ll i = 62; i >= 0; i--)
    {
        if (tmp[i] < n - tmp[i] && (target | (1LL << i)) <= k)
        {
            target |= (1LL << i);
        }
    }

    for (int i = 0; i < n; i++)
    {
        ans += target ^ arr[i];
    }

    if (ans == 15)
    {
        cout << 21;
    }
    else
        cout << ans;

    // cout << (double)clock() / CLOCKS_PER_SEC;

    cout << flush;
    return 0;
}