// 2024/11/16 13:05:57
#ifdef LOCAL
#include <basic_std_lib.h>
#include <list>
#else
#include <bits/stdc++.h>
#endif
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 1e6 + 6;

// void solve()
// {
//     string s;
//     getline(cin, s);
//     deque<int> a(s.begin(), s.end());
//     for (auto& x : a)
//     {
//         x -= '0';
//     }

//     for (i64 i = 0; i + 1 < i64(a.size());)
//     {
//         if (a[i] == 2)
//         {
//             i++;
//             continue;
//         }

//         if (a[i + 1] == a[i])
//         {
//             a.erase(a.begin() + i, a.begin() + i + 2);
//         }
//         else
//         {
//             i++;
//         }
//     }

//     for (i64 i = i64(a.size()) - 1; i > 0;)
//     {
//         if (a[i] == 2)
//         {
//             i--;
//             continue;
//         }

//         if (a[i - 1] == a[i])
//         {
//             a.erase(a.begin() + i - 1, a.begin() + i + 1);
//             i -= 2;
//         }
//         else
//         {
//             i--;
//         }
//     }

//     i64 cnt_2 = std::count(a.begin(), a.end(), 2);
//     i64 cnt_other = a.size() - cnt_2;
//     if (cnt_2 >= cnt_other)
//     {
//         cnt_2 -= cnt_other;
//         cout << cnt_2 % 2 << '\n';
//     }
//     else
//     {
//         cnt_other -= cnt_2;
//         cout << cnt_other << '\n';
//     }
// }

void solve()
{
    string s;
    getline(cin, s);
    for (auto& ch : s)
    {
        ch -= '0';
    }

    list<int> a{s.begin(), s.end()};
    auto func = [&]
    {
        auto it = a.begin();
        for (; it != a.end();)
        {
            if (*it == 2)
            {
                it++;
                continue;
            }

            auto it1 = it;
            it1++;
            if (it1 != a.end() && *it == *it1)
            {
                it = a.erase(it);
                it = a.erase(it);

                it1 = it;
                if (it1 != a.begin())
                {
                    auto it2 = it1;
                    it2--;
                    if (it2 != a.begin())
                    {
                        auto it3 = it2;
                        it3--;

                        it = it3;
                    }
                }

                // if (it != a.begin())
                // {
                //     it--;
                // }
            }
            else
            {
                it++;
            }
        }

        it = a.end();
        if (it != a.begin())
        {
            it--;
        }

        for (; it != a.begin();)
        {
            if (*it == 2)
            {
                it--;
                continue;
            }

            auto it1 = it;
            it1--;
            if (*it1 == *it)
            {
                auto it2 = it1;
                if (it2 != a.begin())
                {
                    it2--;
                    a.erase(it);
                    a.erase(it1);
                    it = it2;

                    it1 = it;
                    it1++;
                    if (it1 != a.end())
                    {
                        it2 = it1;
                        it2++;
                        if (it2 != a.end())
                        {
                            it = it2;
                        }
                    }

                    // it++;
                    // if (it == a.end())
                    // {
                    //     it--;
                    // }
                }
                else
                {
                    a.erase(it);
                    a.erase(it1);
                    break;
                }
            }
            else
            {
                it--;
            }
        }
    };

    auto func1 = [&]
    {
        auto it = a.begin();
        for (; it != a.end(); it++)
        {
            if (*it == 2)
            {
                auto it1 = it;
                for (; it1 != a.end() && *it1 == 2; it1++) {}
                it1--;

                while (it != a.end() && it1 != a.end() && it != it1 && *it == *it1 && *it == 2)
                {
                    if (it == a.begin())
                    {
                        break;
                    }
                    auto it2 = it1;
                    it2++;
                    if (it2 == a.end())
                    {
                        break;
                    }

                    auto t_it = it;
                    t_it++;
                    auto t_it1 = it1;
                    t_it1--;

                    if (t_it == it1)
                    {
                        auto nex = it;
                        nex++;
                        nex++;
                        auto tmp = it;
                        tmp--;
                        a.erase(tmp);
                        a.erase(it);

                        tmp = it1;
                        tmp++;
                        a.erase(tmp);
                        a.erase(it1);

                        it = nex;
                        break;
                    }
                    else
                    {
                        auto tmp = it;
                        tmp--;
                        a.erase(tmp);
                        a.erase(it);

                        tmp = it1;
                        tmp++;
                        a.erase(tmp);
                        a.erase(it1);

                        it = t_it;
                        it1 = t_it1;

                        if (it == it1)
                        {
                            if (it != a.begin())
                            {
                                
                            }
                            
                            break;
                        }
                    }
                }
            }
        }
    };

    func();
    // 0120201012

    func1();
    // 0110

    auto pre = a;
    while (!a.empty())
    {
        func();
        func1();
        if (pre == a)
        {
            break;
        }
        pre = a;
    }

    cout << a.size() << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    tt = 1;
    cin >> tt;
    cin.ignore(111, '\n');
    while (tt--)
    {
        solve();
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
