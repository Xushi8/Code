// // 2023/08/03 15:51:14
// #ifndef LOCAL
// #pragma GCC optimize(2)
// #endif
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
// using namespace std;

// using ll = long long;
// using ull = unsigned long long;
// using pii = pair<int, int>;
// const int INF = 0x3f3f3f3f;
// const int MOD = (int)(1e9 + 7);
// const int N = 1000005;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int tt;
//     cin >> tt;
//     while (tt--)
//     {
//         string s;
//         cin >> s;

//         // cout << s << ' ';
//         // if (s.back() == '0')
//         // {
//         //     int cnt = 0;
//         //     for (int i = (int)s.size() - 1; i >= 0; i--)
//         //     {
//         //         if (s[i] == '0')
//         //             cnt++;
//         //         else
//         //             break;
//         //     }

//         //     if (cnt == (int)s.size())
//         //     {
//         //         if(s[0] != '1')
//         //         {
//         //             cout << s[0] - 1;
//         //         }

//         //         while (cnt--)
//         //             cout << 9;
//         //         cout << '\n';
//         //     }
//         // }
//         // else
//         // {
//         //     if (s.back() == '9')
//         //     {
//         //         cout << s << '\n';
//         //     }
//         //     else
//         //     {
//         //         if (s.size() == 1)
//         //             cout << s << '\n';
//         //         else
//         //         {
//         //             int cnt = 0;
//         //             for (int i = 0; i < (int)s.size() - 1; i++)
//         //             {
//         //                 if (s[i] == '1')
//         //                     cnt++;
//         //             }

//         //             if (cnt > 1)
//         //             {
//         //                 s.back() = '9';
//         //                 for (int i = (int)s.size() - 2; i >= 0; i--)
//         //                 {
//         //                     if (s[i] == '0')
//         //                         s[i] = '9';
//         //                     else
//         //                     {
//         //                         s[i]--;
//         //                         break;
//         //                     }
//         //                 }

//         //                 int index;
//         //                 for (int i = 0; i < (int)s.size(); i++)
//         //                 {
//         //                     if (s[i] != '0')
//         //                     {
//         //                         index = i;
//         //                         break;
//         //                     }
//         //                 }

//         //                 for (auto it = s.begin() + index; it != s.end(); it++)
//         //                 {
//         //                     cout << *it;
//         //                 }

//         //                 cout << '\n';
//         //             }
//         //             else
//         //             {
//         //                 cout << s << '\n';
//         //             }
//         //         }
//         //     }
//         // }


//         if (s.size() == 1)
//             cout << s << '\n';
//         else
//         {
//             if (s[0] == '1') // 1000000000
//             {
//                 int cnt = 0;
//                 for (int i = 1; i < (int)s.size(); i++)
//                 {
//                     if (s[i] == '0')
//                         cnt++;
//                     else
//                         break;
//                 }
//                 if (cnt == (int)s.size() - 1)
//                 {
//                     while (cnt--)
//                         cout << 9;
//                     cout << '\n';
//                     goto NEXT;
//                 }
//             }

//             if (s.front() > '1')
//             {
//                 int cnt = 0;
//                 for (int i = 1; i < (int)s.size(); i++)
//                 {
//                     if (s[i] == '9')
//                         cnt++;
//                     else
//                         break;
//                 }

//                 if (cnt == (int)s.size() - 1) // 39999999999
//                 {
//                     cout << s << '\n';
//                     goto NEXT;
//                 }

//                 cout << (char)(s[0] - 1);
//                 cnt = (int)s.size() - 1;
//                 while (cnt--)
//                 {
//                     cout << 9;
//                 }
//                 cout << '\n';
//             }
//             else
//             {
//                 bool flag = 0;
//                 for (int i = 1; i < (int)s.size(); i++)
//                 {
//                     if (s[i] > '0' && i != (int)s.size() - 1)
//                     {
//                         flag = 1;
//                         int cnt = 0;
//                         for (int j = i + 1; j < (int)s.size(); j++)
//                         {
//                             if (s[j] == '9')
//                                 cnt++;
//                             else
//                                 break;
//                         }

//                         if (cnt == (int)s.size() - i - 1)
//                         {
//                             cout << s << '\n';
//                             goto NEXT;
//                         }

//                         cout << 1;
//                         cout << (char)(s[i] - 1);
//                         cnt = (int)s.size() - i - 1;
//                         while (cnt--)
//                             cout << 9;
//                         cout << '\n';
//                         break;
//                     }
//                 }

//                 if (!flag)
//                     cout << s << '\n';
//             }
//         }

//     NEXT:
//         ;
//     }

// #ifdef LOCAL
//     cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
// #endif
//     cout << flush;
//     return 0;
// }


// 2023/08/03 17:13:59
#ifndef LOCAL
#pragma GCC optimize(2)
#endif
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
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const int N = 1000005;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;
    while (tt--)
    {
        string s;
        cin >> s;

        // cout << s << ' ';
        
        if (s.size() == 1)
            cout << s << '\n';
        else
        {
            // 10000000
            if (s[0] == '1')
            {
                if (count(s.begin() + 1, s.end(), '0') == s.size() - 1)
                {
                    int cnt = (int)s.size() - 1;
                    while (cnt--)
                        cout << 9;
                    cout << '\n';
                }
                // 100003
                else if (count(s.begin() + 1, s.end(), '0') == s.size() - 2 &&
                    s.back() != '0')
                {
                    cout << s << '\n';
                }
                else
                {
                    int index;
                    for (int i = 1; i < (int)s.size(); i++)
                    {
                        if (s[i] != '0')
                        {
                            index = i;
                            break;
                        }
                    }

                    // 1003999
                    if (count(s.begin() + index + 1, s.end(), '9') == s.size() - 1 - index)
                    {
                        cout << s << '\n';
                    }
                    else
                    {
                        for (int i = 0; i < index; i++)
                            cout << s[i];
                        cout << (char)(s[index] - 1);
                        int cnt = (int)s.size() - 1 - index;
                        while (cnt--)
                        {
                            cout << 9;
                        }
                        cout << '\n';
                    }
                }
            }
            else
            {
                // 3999999
                if (count(s.begin() + 1, s.end(), '9') == s.size() - 1)
                    cout << s << '\n';
                else
                {
                    cout << (char)(s[0] - 1);
                    int cnt = (int)s.size() - 1;
                    while (cnt--)
                        cout << 9;
                    cout << '\n';
                }
            }
        }
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}