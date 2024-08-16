// // 2024/08/16 16:16:55
// #ifdef LOCAL
// #include <basic_std_lib.h>
// #else
// #include <bits/stdc++.h>
// #endif
// using namespace std;

// void solve();

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int tt;
//     tt = 1;
//     while (tt--)
//     {
//         solve();
//     }

// #ifdef LOCAL
//     cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
// #endif
//     return 0;
// }

// using i64 = int64_t;
// using u64 = uint64_t;
// using pii = pair<int, int>;
// using pll = pair<i64, i64>;
// constexpr int N = 1000005;

// ofstream ofs1("out1.txt");
// ofstream ofs2("out2.txt");

// size_t get_zuixiao(vector<pii> const& a)
// {
//     auto b = a;
//     b.insert(b.end(), a.begin(), a.end());
//     const size_t n = a.size();
//     size_t i, j;
//     for (i = 0, j = 1; i < n && j < n;)
//     {
//         size_t k;
//         for (k = 0; k < n && b[i + k].second == b[j + k].second; k++)
//         {
//             // cerr << i << ' ' << j << ' ' << b[i].second << ' ' << b[j].second << '\n';
//         }

//         if (b[i + k].second > b[j + k].second)
//             i = i + k + 1;
//         else
//             j = j + k + 1;
//         if (i == j)
//             j++;
//     }
//     return min(i, j);
// }

// bool flag = false;

// void func(vector<pii>& a)
// {
//     int pre = a[0].second;
//     for (size_t i = 1; i < a.size(); i++)
//     {
//         int old = pre;
//         pre = a[i].second;
//         a[i].second -= old;
//     }
//     a[0].second = a[0].second + 3600000 - pre;
//     if (!flag)
//     {
//         for (auto [x, y] : a)
//         {
//             ofs1 << x << ' ' << y << '\n';
//         }
//         flag = true;
//     }
//     else
//     {
//         for (auto [x, y] : a)
//         {
//             ofs2 << x << ' ' << y << '\n';
//         }
//     }

//     size_t k = get_zuixiao(a);
//     rotate(a.begin(), a.begin() + k, a.end());
// }

// void solve()
// {
//     int n;
//     cin >> n;
//     vector<pii> a(n);
//     for (int i = 0; i < n; i++)
//     {
//         double x, y;
//         cin >> x >> y;
//         a[i] = {int(round(x * 1e4)), int(round((y + 360) * 1e4))};
//     }
//     sort(a.begin(), a.end(), [](pii lhs, pii rhs)
//         {
//             if (lhs.second != rhs.second)
//                 return lhs.second < rhs.second;
//             else
//                 return lhs.first < rhs.first;
//         });
//     func(a);

//     vector<pii> b(n);
//     for (int i = 0; i < n; i++)
//     {
//         double x, y;
//         cin >> x >> y;
//         b[i] = {int(round(x * 1e4)), int(round((y + 360) * 1e4))};
//     }
//     sort(b.begin(), b.end(), [](pii lhs, pii rhs)
//         {
//             if (lhs.second != rhs.second)
//                 return lhs.second < rhs.second;
//             else
//                 return lhs.first < rhs.first;
//         });
//     func(b);

//     int dec = a[0].second - b[0].second;
//     for_each(a.begin(), a.end(), [&](pii& val)
//         {
//             val.second -= dec;
//         });

//     for (size_t i = 0; i < a.size(); i++)
//     {
//         ofs1 << a[i].first << ' ' << a[i].second << '\n';
//         ofs2 << b[i].first << ' ' << b[i].second << '\n';
//     }
//     for (size_t i = 0; i < b.size(); i++)
//     {
//     }
//     cout << (a == b ? "Same" : "Different") << '\n';
// }

// // 2024/08/16 23:26:16
// #ifdef LOCAL
// #include <basic_std_lib.h>
// #else
// #include <bits/stdc++.h>
// #endif
// using namespace std;

// void solve();

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int tt;
//     tt = 1;
//     while (tt--)
//     {
//         solve();
//     }

// #ifdef LOCAL
//     cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
// #endif
//     return 0;
// }

// using i64 = int64_t;
// using u64 = uint64_t;
// using pii = pair<int, int>;
// using pll = pair<i64, i64>;
// constexpr int N = 1000005;

// void solve()
// {
//     int n;
//     cin >> n;

//     auto get = [&]()
//     {
//         vector<pii> a(n);
//         for (int i = 0; i < n; i++)
//         {
//             double x, y;
//             cin >> x >> y;
//             a[i] = pii{round(x * 1e4), round(y * 1e4)};
//         }

//         sort(a.begin(), a.end(), [](pii lhs, pii rhs)
//             {
//                 if (lhs.second != rhs.second)
//                     return lhs.second < rhs.second;
//                 else
//                     return lhs.first < rhs.first;
//             });

//         int pre = a[0].second;
//         for (int i = 1; i < n; i++)
//         {
//             int tmp = a[i].second;
//             a[i].second -= pre;
//             pre = tmp;
//         }
//         a[0].second = a[0].second + 3600000 - pre;

//         auto func = [&](vector<pii> const& vec)
//         {
//             auto tmp = vec;
//             tmp.insert(tmp.end(), vec.begin(), vec.end());
//             int i, j, k;
//             for (i = 0, j = 1; i < n && j < n;)
//             {
//                 for (k = 0; k < n && tmp[i + k] == tmp[j + k]; k++)
//                 {
//                 }
//                 if (tmp[i + k] > tmp[j + k])
//                     i = i + k + 1;
//                 else
//                     j = j + k + 1;
//                 if (i == j)
//                     j++;
//             }
//             return min(i, j);
//         };

//         size_t k = func(a);
//         rotate(a.begin(), a.begin() + k, a.end());

//         return a;
//     };

//     auto vec1 = get();
//     auto vec2 = get();
//     if (n == 1)
//     {
//         cout << (vec1[0].first == vec2[0].first ? "Same" : "Different") << '\n';
//         return;
//     }
//     cout << (vec1 == vec2 ? "Same" : "Different") << '\n';
// }


// 2024/08/16 23:50:49
#ifdef LOCAL
#include <basic_std_lib.h>
#else
#include <bits/stdc++.h>
#endif
using namespace std;


void solve();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    tt = 1;
    while (tt--)
    {
        solve();
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}

using i64 = int64_t;
using u64 = uint64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 1000005;

void solve()
{
    int n;
    cin >> n;

    auto get = [&]()
    {
        vector<pii> a(n);
        for (int i = 0; i < n; i++)
        {
            double x, y;
            cin >> x >> y;
            a[i] = pii{round(x * 1e4), round(y * 1e4)};
        }
        sort(a.begin(), a.end(), [](pii lhs, pii rhs)
            {
                if (lhs.second != rhs.second)
                    return lhs.second < rhs.second;
                else
                    return lhs.first < rhs.first;
            });

        auto func1 = [](vector<pii>& vec)
        {
            int pre = vec[0].second;
            for (size_t i = 1; i < vec.size(); i++)
            {
                int t = vec[i].second;
                vec[i].second -= pre;
                pre = t;
            }
            vec[0].second = vec[0].second + 3600000 - pre;
        };

        auto func2 = [](vector<pii> const& vec)
        {
            auto tmp = vec;
            const size_t n = vec.size();
            tmp.insert(tmp.end(), vec.begin(), vec.end());
            size_t i, j, k;
            for (i = 0, j = 1; i < n && j < n;)
            {
                for (k = 0; k < n && tmp[i + k] == tmp[j + k]; k++)
                {
                }
                if (tmp[i + k] > tmp[j + k])
                    i += k + 1;
                else
                    j += k + 1;
                if (i == j)
                    j++;
            }

            k = min(i, j);

            rotate(tmp.begin(), tmp.begin() + k, tmp.end());
            return tmp;
        };

        func1(a);
        
        return func2(a);
    };

    auto a1 = get();
    auto a2 = get();
    if (n == 1)
    {
        cout << (a1[0].first == a2[0].first ? "Same" : "Different") << '\n';
    }
    else
    {
        cout << (a1 == a2 ? "Same" : "Different") << '\n';
    }

}