// // // 2023/11/14 19:12:15
// // #include <iostream>
// // #include <algorithm>
// // #include <cstring>
// // #include <cstdint>
// // #include <vector>
// // #include <string>
// // #include <set>
// // #include <map>
// // #include <unordered_map>
// // #include <unordered_set>
// // #include <queue>
// // #include <functional>
// // #include <iomanip>
// // #include <cmath>
// // #include <stack>
// // #include <array>
// // #include <fstream>
// // #include <bitset>
// // using namespace std;

// // using ll = long long;
// // using pii = pair<int, int>;
// // constexpr int N = 1000005;

// // vector<int> G[N];
// // int n, k;
// // bool vis[N];
// // int val[N];
// // int tot = 0;
// // bool flag = 0;
// // int maxn, now_id, number_size;
// // void dfs(int u, int sum)
// // {
// //     if (vis[u])
// //     {
// //         return;
// //     }
// //     vis[u] = 1;
// //     number_size++;
// //     sum += val[u];
// //     if (sum >= k * 2 && number_size >= 2)
// //     {
// //         flag = 1;
// //     }

// //     if (val[u] > maxn)
// //     {
// //         maxn = val[u];
// //         now_id = u;
// //     }

// //     for (int v : G[u])
// //     {
// //         dfs(v, sum);
// //     }
// // }

// // int main()
// // {
// //     ios::sync_with_stdio(false);
// //     cin.tie(0);

// //     cin >> n >> k;
// //     map<string, int> m1;
// //     map<int, string> m2;
// //     for (int i = 0; i < n; i++)
// //     {
// //         string a, b;
// //         int c;
// //         cin >> a >> b >> c;
// //         int ia, ib;
// //         if (m1.count(a) == 0)
// //         {
// //             ia = m1.size();
// //             m1[a] = ia;
// //             m2[ia] = a;
// //         }
// //         else
// //         {
// //             ia = m1[a];
// //         }
// //         if (m1.count(b) == 0)
// //         {
// //             ib = m1.size();
// //             m1[b] = ib;
// //             m2[ib] = b;
// //         }
// //         else
// //         {
// //             ib = m1[b];
// //         }

// //         G[ia].emplace_back(ib);
// //         G[ib].emplace_back(ia);
// //         val[ia] += c;
// //         val[ib] += c;
// //     }

// //     vector<pair<string, int>> ans;
// //     for (int i = 0; i < n * 5; i++)
// //     {
// //         if (!vis[i])
// //         {
// //             flag = 0;
// //             maxn = 0;
// //             now_id = -1;
// //             number_size = 0;
// //             dfs(i, 0);
// //             if (flag)
// //             {
// //                 ans.emplace_back(m2[now_id], number_size);
// //             }
// //         }
// //     }

// //     cout << ans.size() << endl;
// //     sort(ans.begin(), ans.end());
// //     for (auto [x, y] : ans)
// //     {
// //         cout << x << ' ' << y << '\n';
// //     }

// // #ifdef LOCAL
// //     cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
// // #endif
// //     cout << flush;
// //     return 0;
// // }

// // 2023/11/14 19:43:06
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <cstdint>
// #include <vector>
// #include <string>
// #include <set>
// #include <map>
// #include <unordered_map>
// #include <unordered_set>
// #include <queue>
// #include <functional>
// #include <iomanip>
// #include <cmath>
// #include <stack>
// #include <array>
// #include <fstream>
// #include <bitset>
// using namespace std;

// using ll = long long;
// using pii = pair<int, int>;
// constexpr int N = 1000005;

// int n, k;

// int val[N];
// bool vis[N];
// vector<int> G[N];
// bool flag = 0;
// void dfs(int u, int& sum, int& size, int maxn, int& header)
// {
//     if(vis[u]) {
//         return;
//     }
//     vis[u] = 1;
//     size++;
//     sum += val[u];
//     if(sum >= k * 2 && size >= 2) {
//         flag = 1;
//     }
//     if(val[u] > maxn) {
//         maxn = val[u];
//         header = u;
//     }
//     for(int v : G[u]) {
//         dfs(v, sum, size, maxn, header);
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     map<string, int> m1;
//     map<int, string> m2;
//     cin >> n >> k;
//     for (int i = 0; i < n; i++) {
//         string sa, sb;
//         int x;
//         cin >> sa >> sb >> x;
//         int ia, ib;
//         if (m1.count(sa) == 0)
//         {
//             ia = m1.size();
//             m1.emplace(sa, ia);
//             m2.emplace(ia, sa);
//         }
//         else
//         {
//             ia = m1[sa];
//         }

//         if (m1.count(sb) == 0)
//         {
//             ib = m1.size();
//             m1.emplace(sb, ib);
//             m2.emplace(ib, sb);
//         }
//         else
//         {
//             ib = m1[sb];
//         }

//         G[ia].emplace_back(ib);
//         G[ib].emplace_back(ia);
//         val[ia] += x;
//     }

//     vector<pair<string, int>> ans;

//     for (int i = 0; i < n * 5; i++) {
//         int siz, header, sum;
//         siz = 0, header = 0, sum = 0;
//         if (!vis[i])
//         {
//             flag = 0;
//             dfs(i, sum, siz, 0, header);
//             if(flag) {
//                 ans.emplace_back(m2[header], siz);
//             }
//         }
//     }

//     cout << ans.size() << endl;
//     for(auto [x, y] : ans) {
//         cout << x << ' ' << y << '\n';
//     }

// #ifdef LOCAL
//     cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
// #endif
//     cout << flush;
//     return 0;
// }

// 2023/11/14 19:58:11
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdint>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <functional>
#include <iomanip>
#include <cmath>
#include <stack>
#include <array>
#include <fstream>
#include <bitset>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 10005;

int n, k;
int val[N];
vector<int> G[N];
bool vis[N];
struct A
{
    string head;
    vector<int> members;
    int totaltime;
};

A group;

void dfs(int u)
{
    if (vis[u])
    {
        return;
    }
    vis[u] = 1;
    group.totaltime += val[u];
    group.members.emplace_back(u);
    for (int v : G[u])
    {
        dfs(v);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    unordered_map<string, int> m1;
    unordered_map<int, string> m2;
    for (int i = 0; i < n; i++)
    {
        string sa, sb;
        int x;
        cin >> sa >> sb >> x;
        int ia, ib;
        if (m1.count(sa) != 0)
        {
            ia = m1[sa];
        }
        else
        {
            ia = m1.size();
            m1.emplace(sa, ia);
            m2.emplace(ia, sa);
        }
        if (m1.count(sb) != 0)
        {
            ib = m1[sb];
        }
        else
        {
            ib = m1.size();
            m1.emplace(sb, ib);
            m2.emplace(ib, sb);
        }

        val[ia] += x;
        val[ib] += x;
        G[ia].emplace_back(ib);
        G[ib].emplace_back(ia);
    }

    vector<pair<string, int>> ans;
    for (int i = 0; i < m1.size(); i++)
    {
        if (!vis[i])
        {
            group.members.clear();
            group.totaltime = 0;
            dfs(i);
            if (group.members.size() > 2 && group.totaltime > k * 2)
            {
                int maxn = 0;
                string head;
                for (auto x : group.members)
                {
                    if (maxn < val[x])
                    {
                        maxn = val[x];
                        head = m2[x];
                    }
                }
                ans.emplace_back(head, group.members.size());
            }
        }
    }

    cout << ans.size() << endl;
    sort(ans.begin(), ans.end());
    for (auto [x, y] : ans)
    {
        cout << x << ' ' << y << '\n';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}