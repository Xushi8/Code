// 2023/05/25 15:17:41
#include <bits/stdc++.h>
using namespace std;

using ll = long long;


// int V, E;
// const ll INF = 0x3f3f3f3f3f3f3f3f;
// ll arr[105][105];

// struct edge
// {
//     edge(ll a, ll b, ll c)
//     {
//         from = a;
//         to = b;
//         cost = c;
//     }
//     ll from, to, cost;
// };
// vector<edge> G;
// ll dis[105];
// // bool find_negative_circle()
// // {
// //     memset(dis, 0, sizeof(dis));
// //     for (int i = 0; i < V; i++)
// //     {
// //         for (int j = 0; j < E; j++)
// //         {
// //             const edge& e = G[j];
// //             if (dis[e.to] > dis[e.from] + e.cost)
// //             {
// //                 dis[e.to] = dis[e.from] + e.cost;
// //                 if (i == V - 1)
// //                     return true;
// //             }
// //         }
// //     }
// //     return false;
// // }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     memset(arr, 0x3f, sizeof(arr));
//     cin >> V >> E;
//     for (int i = 0; i < V; i++)
//     {
//         arr[i][i] = 0;
//     }

//     for (int i = 0; i < E; i++)
//     {
//         int a, b, c;
//         cin >> a >> b >> c;
//         arr[a][b] = c;
//         // G.emplace_back(a, b, c);
//     }


//     for (int k = 0; k < V; k++)
//         for (int i = 0; i < V; i++)
//             for (int j = 0; j < V; j++)
//                 if (arr[i][k] != INF && arr[k][j] != INF && arr[i][j] > arr[i][k] + arr[k][j])
//                     arr[i][j] = arr[i][k] + arr[k][j];

//     bool flag = 0;
//     for (int i = 0; i < V; i++)
//     {
//         if (arr[i][i] < 0)
//         {
//             flag = 1;
//             break;
//         }
//     }

//     if (flag)
//         cout << "NEGATIVE CYCL\n";
//     else
//     {
//         for (int i = 0; i < V; i++)
//         {
//             for (int j = 0; j < V; j++)
//                 if (arr[i][j] >= 0x3f3f3f3f3f)
//                     cout << "INF ";
//                 else
//                     cout << arr[i][j] << ' ';
//             cout << '\n';
//         }
//     }

//     cout << flush;
//     return 0;
// }


// 2023/06/23 11:47:44

// constexpr int cxf(int i) { return i * 2; }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int n;
//     while (cin >> n)
//     {
//         int tmp;
//         set<int> a, b;
//         for (int i = 0; i < n; i++)
//         {
//             cin >> tmp;
//             a.emplace(tmp);
//         }
//         for (int i = 0; i < n; i++)
//         {
//             cin >> tmp;
//             b.emplace(tmp);
//         }

//         for (auto it1 = a.begin(); it1 != a.end(); it1++)
//         {
//             for (auto it2 = b.begin(); it2 != b.end(); it2++)
//             {
//                 if ((a.count(*it1 ^ *it2) == 1 && b.count(*it1 ^ *it2) == 0) ||
//                     (b.count(*it1 ^ *it2) == 1 && a.count(*it1 ^ *it2) == 0))
//                 {
//                     cout << "yes\n";
//                     goto out;
//                 }
//             }
//         }

//         cout << "no\n";

//     out:
//         ;
//     }

//     cout << flush;
//     return 0;
// }


// 2023/06/23 14:02:16

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     ll n;
//     cin >> n;
//     ll ans = 0;
//     ll f1 = 1, f2 = 0, tmp;
//     while (f1 < n)
//     {
//         tmp = f1;
//         f1 = f1 + f2 + 1;
//         f2 = tmp;
//         ans++;
//     }
    
//     cout << ans;

//     cout << flush;
//     return 0;
// }

class Point
{
public:
    Point(double a, double b)
    {
        x = a;
        y = b;
    }
    Point() {}
    double x, y;
};

vector<Point> Poly;
int n;

bool on_line(Point p1, Point p2, Point Q)
{
    double maxx, minx, maxy, miny;
    maxx = p1.x > p2.x ? p1.x : p2.x;    //矩形的右边长
    minx = p1.x > p2.x ? p2.x : p1.x;     //矩形的左边长
    maxy = p1.y > p2.y ? p1.y : p2.y;    //矩形的上边长
    miny = p1.y > p2.y ? p2.y : p1.y;     //矩形的下边长

    if (((Q.x - p1.x) * (p2.y - p1.y) == (p2.x - p1.x) * (Q.y - p1.y)) && (Q.x >= minx && Q.x <= maxx) && (Q.y >= miny && Q.y <= maxy))
        return 1;
    else
        return 0;
}

int in_polygon_scan(Point Q) {//扫描法 
    int counter = 0;double xinters;Point P1, P2;
    P1 = Poly[0];
    for (int i = 1;i <= n;++i) {//遍历所有的点 
        P2 = Poly[i % n];
        if (on_line(P1, P2, Q)) return 1;//在线上 
        if (Q.y > min(P1.y, P2.y) && Q.y <= max(P1.y, P2.y)) {//在线段内 
            if (Q.x <= max(P1.x, P2.x)) {
                if (P1.y != P2.y) {
                    xinters = (Q.y - P1.y) * (P2.x - P1.x) / (P2.y - P1.y) + P1.x;
                    if (P1.x == P2.x || Q.x <= xinters) counter++;//符合要求 
                }
            }
        }P1 = P2;
    }
    if (counter % 2 == 0) return 0;
    return 2;
}
int main() {
    Point Q;
    cin >> n;
    Poly.reserve(n);
    for (int i = 0; i < n; i++)
    {
        cin >> Poly[i].x >> Poly[i].y;
    }

    int tt;
    cin >> tt;
    while (tt--)
    {
        cin >> Q.x >> Q.y;
        cout << in_polygon_scan(Q) << '\n';
    }

// 2023/05/25 15:17:41
#include <bits/stdc++.h>
using namespace std;

using ll = long long;


// int V, E;
// const ll INF = 0x3f3f3f3f3f3f3f3f;
// ll arr[105][105];

// struct edge
// {
//     edge(ll a, ll b, ll c)
//     {
//         from = a;
//         to = b;
//         cost = c;
//     }
//     ll from, to, cost;
// };
// vector<edge> G;
// ll dis[105];
// // bool find_negative_circle()
// // {
// //     memset(dis, 0, sizeof(dis));
// //     for (int i = 0; i < V; i++)
// //     {
// //         for (int j = 0; j < E; j++)
// //         {
// //             const edge& e = G[j];
// //             if (dis[e.to] > dis[e.from] + e.cost)
// //             {
// //                 dis[e.to] = dis[e.from] + e.cost;
// //                 if (i == V - 1)
// //                     return true;
// //             }
// //         }
// //     }
// //     return false;
// // }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     memset(arr, 0x3f, sizeof(arr));
//     cin >> V >> E;
//     for (int i = 0; i < V; i++)
//     {
//         arr[i][i] = 0;
//     }

//     for (int i = 0; i < E; i++)
//     {
//         int a, b, c;
//         cin >> a >> b >> c;
//         arr[a][b] = c;
//         // G.emplace_back(a, b, c);
//     }


//     for (int k = 0; k < V; k++)
//         for (int i = 0; i < V; i++)
//             for (int j = 0; j < V; j++)
//                 if (arr[i][k] != INF && arr[k][j] != INF && arr[i][j] > arr[i][k] + arr[k][j])
//                     arr[i][j] = arr[i][k] + arr[k][j];

//     bool flag = 0;
//     for (int i = 0; i < V; i++)
//     {
//         if (arr[i][i] < 0)
//         {
//             flag = 1;
//             break;
//         }
//     }

//     if (flag)
//         cout << "NEGATIVE CYCL\n";
//     else
//     {
//         for (int i = 0; i < V; i++)
//         {
//             for (int j = 0; j < V; j++)
//                 if (arr[i][j] >= 0x3f3f3f3f3f)
//                     cout << "INF ";
//                 else
//                     cout << arr[i][j] << ' ';
//             cout << '\n';
//         }
//     }

//     cout << flush;
//     return 0;
// }


// 2023/06/23 11:47:44

// constexpr int cxf(int i) { return i * 2; }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int n;
//     while (cin >> n)
//     {
//         int tmp;
//         set<int> a, b;
//         for (int i = 0; i < n; i++)
//         {
//             cin >> tmp;
//             a.emplace(tmp);
//         }
//         for (int i = 0; i < n; i++)
//         {
//             cin >> tmp;
//             b.emplace(tmp);
//         }

//         for (auto it1 = a.begin(); it1 != a.end(); it1++)
//         {
//             for (auto it2 = b.begin(); it2 != b.end(); it2++)
//             {
//                 if ((a.count(*it1 ^ *it2) == 1 && b.count(*it1 ^ *it2) == 0) ||
//                     (b.count(*it1 ^ *it2) == 1 && a.count(*it1 ^ *it2) == 0))
//                 {
//                     cout << "yes\n";
//                     goto out;
//                 }
//             }
//         }

//         cout << "no\n";

//     out:
//         ;
//     }

//     cout << flush;
//     return 0;
// }


// 2023/06/23 14:02:16

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     ll n;
//     cin >> n;
//     ll ans = 0;
//     ll f1 = 1, f2 = 0, tmp;
//     while (f1 < n)
//     {
//         tmp = f1;
//         f1 = f1 + f2 + 1;
//         f2 = tmp;
//         ans++;
//     }
    
//     cout << ans;

//     cout << flush;
//     return 0;
// }

class Point
{
public:
    Point(double a, double b)
    {
        x = a;
        y = b;
    }
    Point() {}
    double x, y;
};

vector<Point> Poly;
int n;

bool on_line(Point p1, Point p2, Point Q)
{
    double maxx, minx, maxy, miny;
    maxx = p1.x > p2.x ? p1.x : p2.x;    //矩形的右边长
    minx = p1.x > p2.x ? p2.x : p1.x;     //矩形的左边长
    maxy = p1.y > p2.y ? p1.y : p2.y;    //矩形的上边长
    miny = p1.y > p2.y ? p2.y : p1.y;     //矩形的下边长

    if (((Q.x - p1.x) * (p2.y - p1.y) == (p2.x - p1.x) * (Q.y - p1.y)) && (Q.x >= minx && Q.x <= maxx) && (Q.y >= miny && Q.y <= maxy))
        return 1;
    else
        return 0;
}

int in_polygon_scan(Point Q) {//扫描法 
    int counter = 0;double xinters;Point P1, P2;
    P1 = Poly[0];
    for (int i = 1;i <= n;++i) {//遍历所有的点 
        P2 = Poly[i % n];
        if (on_line(P1, P2, Q)) return 1;//在线上 
        if (Q.y > min(P1.y, P2.y) && Q.y <= max(P1.y, P2.y)) {//在线段内 
            if (Q.x <= max(P1.x, P2.x)) {
                if (P1.y != P2.y) {
                    xinters = (Q.y - P1.y) * (P2.x - P1.x) / (P2.y - P1.y) + P1.x;
                    if (P1.x == P2.x || Q.x <= xinters) counter++;//符合要求 
                }
            }
        }P1 = P2;
    }
    if (counter % 2 == 0) return 0;
    return 2;
}
int main() {
    Point Q;
    cin >> n;
    Poly.reserve(n);
    for (int i = 0; i < n; i++)
    {
        cin >> Poly[i].x >> Poly[i].y;
    }

    int tt;
    cin >> tt;
    while (tt--)
    {
        cin >> Q.x >> Q.y;
        cout << in_polygon_scan(Q) << '\n';
    }

}