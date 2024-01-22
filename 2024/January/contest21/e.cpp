// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <cmath>
// using namespace std;

// using ll = long long;
// using pii = pair<int, int>;
// using pdd = pair<long double, long double>;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int n;
//     cin >> n;
//     vector<pdd> a(n), b(n);
//     for (auto& [x, y] : a)
//     {
//         cin >> x >> y;
//         if (y < 0) y += 360.;
//     }
//     for (auto& [x, y] : b)
//     {
//         cin >> x >> y;
//         if (y < 0) y += 360.;
//     }
//     sort(a.begin(), a.end());
//     sort(b.begin(), b.end());
//     for (int i = 0; i < n; i++)
//     {
//         if (abs(a[i].first - b[i].first) > 1e-4)
//         {
//             cout << "Different" << endl;
//             return 0;
//         }
//     }

//     auto check = [&](long double val) -> int
//     {
//         vector<pdd> tmp(a);
//         for (int i = 0; i < n; i++)
//         {
//             tmp[i].second += val;
//             while (tmp[i].second > 360.) tmp[i].second -= 360.;
//         }
//         sort(tmp.begin(), tmp.end());
//         for (int i = 0; i < n; i++)
//         {
//             if (abs(tmp[i].second - b[i].second) > 1e-6)
//             {
//                 // if (tmp[i].second - b[i].second > 0)
//                 // {
//                 //     long double x = tmp[i].second - b[i].second;
//                 //     if (x < 180)
//                 //         return 1;
//                 //     else
//                 //         return -1;
//                 // }
//                 // else
//                 // {
//                 //     long double x = b[i].second - tmp[i].second;
//                 //     if (x < 180)
//                 //         return -1;
//                 //     else
//                 //         return 1;
//                 // }
//             }
//         }

//         return 0;
//     };

//     long double l = 0, r = 360.;
//     for (int i = 0; i < 35; i++)
//     {
//         long double mid = (l + r) / 2;
//         int ret = check(mid);
//         if (ret > 0)
//             r = mid;
//         else if (ret < 0)
//             l = mid;
//         else
//             break;
//     }

//     if (check((l + r) / 2) == 0)
//     {
//         cout << "Same" << endl;
//     }
//     else
//     {
//         cout << "Different" << endl;
//     }

// #ifdef LOCAL
//     cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
// #endif
//     return 0;
// }

// 2024/01/17 20:48:05
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
#include <numeric>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 1000005;

vector<int> get_next(vector<int> const& a)
{
    vector<int> nex(a.size());
    nex[0] = -1;
    int i = 1, j = -1;
    while (i < int(a.size()))
    {
        if (j == -1 || a[i] == a[j])
        {
            i++;
            j++;
            nex[i] = j;
        }
        else
        {
            j = nex[j];
        }
    }
    return nex;
}

int kmp(vector<int> const& a, vector<int> const& b)
{
    int i = 0, j = 0;
    vector<int> nex = get_next(b);
    while (i < int(a.size()))
    {
        if (j == -1 || a[i] == b[j])
        {
            i++;
            j++;
        }
        else if (j > 0)
        {
            j = nex[j];
        }
        else
        {
            i++;
        }

        if (j == int(b.size()))
        {
            return i - j;
        }
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pii> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        double x, y;
        cin >> x >> y;
        a[i] = {round(y * 1e4), round(x * 1e4)};
    }

    for (int i = 0; i < n; i++)
    {
        double x, y;
        cin >> x >> y;
        b[i] = {round(y * 1e4), round(x * 1e4)};
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for (int i = 0; i < n; i++)
    {
        b.emplace_back(b[i].first + 3600000, b[i].second);
    }

    vector<int> ca(n), cb(2 * n);

    for (int i = 1; i < n; i++)
    {
        ca[i] = a[i].first - a[i - 1].first;
    }
    ca[0] = a[0].first - a[n - 1].first + 3600000;
    for (int i = 1; i < 2 * n; i++)
    {
        cb[i] = b[i].first - b[i - 1].first;
    }

    vector<int> nex(n);
    nex[0] = -1;
    for (int i = 1, j = -1; i < n; i++)
    {
        while (j >= 0 && ca[i] != ca[j + 1])
            j = nex[j];

        if (ca[i] == ca[j + 1])
            j++;
        nex[i] = j;
    }

    auto func = [&](int x) -> int
    {
        if (x != -1)
            return x;
        else
            return n - 1;
    };
    for (int i = 1, j = -1; i < 2 * n; i++)
    {
        while (j != -1 && (cb[i] != ca[j + 1] || a[j].second != b[i - 1].second))
        {
            j = nex[j];
        }

        if (cb[i] == ca[j + 1] && b[i - 1].second == a[func(j)].second)
        {
            j++;
        }

        if (j == n - 1 && a[j].second == b[i].second)
        {
            cout << "Same" << endl;
            return 0;
        }
    }

    cout << "Different" << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
