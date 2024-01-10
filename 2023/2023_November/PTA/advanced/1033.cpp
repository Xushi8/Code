// 2023/11/13 19:56:02
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
#include <memory>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 1000005;

pair<double, double> s[N];

bool cmp(pair<double, double> x, pair<double, double> y)
{
    return x.second < y.second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    double cmax, d, davg;
    int n;
    cin >> cmax >> d >> davg >> n;
    for (int i = 0; i < n; i++)
    {
        double x, y;
        cin >> x >> y;
        s[i] = {x, y};
    }

    s[n].second = d;
    sort(s, s + n + 1, cmp);

    double now_dis{}, now_cost{};

    map<double, int> mp;

    for (int i = 0, j = 0; s[i].second < d; i++)
    {
        if (now_dis < s[i].second)
        {
            if (mp.empty())
            {
                break;
            }

            now_cost += mp.begin()->first * (s[i].second - now_dis) / davg;
            now_dis = s[i].second;
        }

        mp[s[i].first]++;

        while (j <= i && s[j].second + cmax * davg < s[i + 1].second)
        {
            now_cost += mp.begin()->first * (s[j].second + cmax * davg - now_dis) / davg;
            now_dis = s[j].second + cmax * davg;
            if (--mp[s[j].first] == 0)
            {
                mp.erase(s[j].first);
            }
            j++;
        }
    }

    cout << setprecision(2) << fixed;

    if (mp.empty())
    {
        cout << "The maximum travel distance = " << now_dis;
    }
    else
    {
        now_cost += mp.begin()->first * (d - now_dis) / davg;
        now_dis = d;
        cout << now_cost;
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}

// // 2023/11/14 19:03:23
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

// struct station
// {
//     double pi, di;
// };

// double Cmax, D, Davg;
// int n;
// station s[N];

// bool cmp(station x, station y)
// {
//     return x.di < y.di;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     cin >> Cmax >> D >> Davg >> n;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> s[i].pi >> s[i].di;
//     }
//     s[n].di = D;
//     sort(s, s + n + 1, cmp);

//     double curdis = 0, curcost = 0;
//     map<double, int> mp;
//     for (int i = 0, j = 0; s[i].di < D; i++)
//     {
//         if (curdis < s[i].di)
//         {
//             if (mp.empty())
//             {
//                 break;
//             }

//             curcost += mp.begin()->first * (s[i].di - curdis) / Davg;
//             curdis = s[i].di;
//         }

//         mp[s[i].pi]++;

//         while (j <= i && s[j].di + Cmax * Davg < s[i + 1].di)
//         {
//             curcost += mp.begin()->first * (s[j].di + Cmax * Davg - curdis) / Davg;
//             curdis = s[j].di + Cmax * Davg;
//             if (--mp[s[j].pi] == 0)
//             {
//                 mp.erase(s[j].pi);
//             }
//             j++;
//         }
//     }

//         cout << setprecision(2) << fixed;

//         if(mp.empty()) {
//             cout << "The maximum travel distance = " << curdis;
//         } else {
//             now_dis += mp.begin()->first * (d - now_dis) / davg;
//             now_dis = d;
//             cout << now_cost;
//         }

// #ifdef LOCAL
//     cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
// #endif
//     cout << flush;
//     return 0;
// }