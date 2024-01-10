// 2023/07/26 10:29:41
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
#include <stack>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const int N = 1000005;

void solve()
{
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int l = 0, r = m + 1, u = 0, d = n + 1;
    int maxl = 0, maxr = 0, maxu = 0, maxd = 0;
    int x = 1, y = 1;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] == 'L')
            maxl++;
        else if (s[i] == 'R')
            maxr++;
        else if (s[i] == 'U')
            maxu++;
        else
            maxd++;

        l = max(l, maxl - maxr);
        r = min(r, m + 1 - (maxr - maxl));
        u = max(u, maxu - maxd);
        d = min(d, n + 1 - (maxd - maxu));
        if (l + 1 >= r || u + 1 >= d)
        {
            cout << x << ' ' << y << '\n';
            return;
        }
        else
            x = u + 1, y = l + 1;
    }
    cout << x << ' ' << y << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tt;
    cin >> tt;
    while (tt--)
    {
        solve();
        

        
        // stack<int> l, r, u, d;
        // pair<size_t, size_t> cnt[4]; // 右， 下， 左， 上
        // for (int i = 0; i < 4; i++)
        // {
        //     cnt[i].first = 0;
        //     cnt[i].second = INT32_MAX;
        // }
        
        // size_t n, m;
        // cin >> n >> m;
        // string s;
        // cin >> s;
        // size_t time = 0;
        // size_t maxl = 0, maxr = 0, maxu = 0, maxd = 0;
        // for (size_t i = 0; i < s.size(); i++)
        // {
        //     time++;
            
        //     if (s[i] == 'L')
        //     {
        //         if (cnt[0].first != 0)
        //             cnt[0].first--;
        //         else
        //         {
        //             cnt[2].first++;
        //             if (cnt[2].second > cnt[0].second)
        //             {
        //                 if (cnt[2].first + 1 - maxr > m)
        //                     break;
        //             }
        //             else
        //             {
        //                 if (cnt[2].first + 1 > m)
        //                     break;
        //             }

        //             if (maxl < cnt[2].first)
        //             {
        //                 maxl = cnt[2].first;
        //                 cnt[2].second = time;
        //             }
        //         }
        //     }
        //     else if (s[i] == 'R')
        //     {
        //         if (cnt[2].first != 0)
        //             cnt[2].first--;
        //         else
        //         {
        //             cnt[0].first++;
        //             if (cnt[0].second > cnt[2].second)
        //             {
        //                 if (m - cnt[0].first + maxl < 1)
        //                     break;
        //             }
        //             else
        //             {
        //                 if (m - cnt[0].first < 1)
        //                     break;
        //             }

        //             if (maxr < cnt[0].first)
        //             {
        //                 maxr = cnt[0].first;
        //                 cnt[0].second = time;
        //             }
        //         }
        //     }
        //     else if (s[i] == 'U')
        //     {
        //         if (cnt[1].first != 0)
        //             cnt[1].first--;
        //         else
        //         {
        //             cnt[3].first++;
        //             if (cnt[3].second > cnt[1].second)
        //             {
        //                 if (1 + cnt[3].first - maxd > n)
        //                     break;
        //             }
        //             else
        //             {
        //                 if (1 + cnt[3].first > n)
        //                     break;
        //             }

        //             if (maxu < cnt[3].first)
        //             {
        //                 maxu = cnt[3].first;
        //                 cnt[3].second = time;
        //             }
        //         }
        //     }
        //     else
        //     {
        //         if (cnt[3].first != 0)
        //             cnt[3].first--;
        //         else
        //         {
        //             cnt[1].first++;
        //             if (cnt[1].second > cnt[3].second)
        //             {
        //                 if (n - cnt[1].first + maxu < 1)
        //                     break;
        //             }
        //             else
        //             {
        //                 if (n - cnt[1].first < 1)
        //                     break;
        //             }

        //             if (maxd < cnt[1].first)
        //             {
        //                 maxd = cnt[1].first;
        //                 cnt[1].second = time;
        //             }
        //         }
        //     }
        // }

        // size_t x = 1, y = 1;

        // if (cnt[0].second < cnt[2].second)
        // {
        //     y = m - maxr;
        // }
        // else
        // {
        //     if (cnt[0].second != cnt[2].second)
        //     {
        //         y = 1 + maxl;
        //     }
        // }

        // if (cnt[1].second < cnt[3].second)
        // {
        //     x = n - maxd;
        // }
        // else
        // {
        //     if (cnt[1].second != cnt[3].second)
        //     {
        //         x = 1 + maxu;
        //     }
        // }

        // cout << x << ' ' << y << '\n';
    }


    cout << endl;
    return 0;
}