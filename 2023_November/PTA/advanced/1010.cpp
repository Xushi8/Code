// // // 2023/11/07 19:27:26
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

// // ll tranverse(const string& s, ll r)
// // {
// //     ll now = 0;
// //     ll wei = 1;
// //     for (char ch : s)
// //     {
// //         if (isdigit(ch))
// //         {
// //             if (ch - '0' >= r)
// //                 return -1;
// //             now += (ch - '0') * wei;
// //         }
// //         else
// //         {
// //             if (ch - 'a' + 10 >= r)
// //                 return -1;
// //             now += (ch - 'a' + 10) * wei;
// //         }
// //         wei *= r;

// //         if (now < 0)
// //         {
// //             return 9e18;
// //         }
// //     }

// //     return now;
// // }

// // int tranverse2(const string& s, ll r, ll val)
// // {
// //     ll now = 0;
// //     ll wei = 1;
// //     for (char ch : s)
// //     {
// //         if (wei > val)
// //         {
// //             return 1;
// //         }

// //         if (isdigit(ch))
// //         {
// //             if (ch - '0' >= r)
// //                 return -1;
// //             now += (ch - '0') * wei;
// //         }
// //         else
// //         {
// //             if (ch - 'a' + 10 >= r)
// //                 return -1;
// //             now += (ch - 'a' + 10) * wei;
// //         }
// //         wei *= r;
// //     }

// //     if (now > val)
// //         return 1;
// //     else if (now < val)
// //         return -1;
// //     else
// //         return 0;
// // }

// // int main()
// // {
// //     ios::sync_with_stdio(false);
// //     cin.tie(0);

// //     string n1, n2;
// //     int tag, jinzhi;
// //     cin >> n1 >> n2 >> tag >> jinzhi;
// //     if (tag == 2)
// //     {
// //         swap(n1, n2);
// //     }

// //     reverse(n1.begin(), n1.end());
// //     reverse(n2.begin(), n2.end());
// //     ll val1 = tranverse(n1, jinzhi);

// //     ll l = 1, r = 1e9;
// //     ll ans = -1;
// //     while (l <= r)
// //     {
// //         ll mid = l + (r - l) / 2;
// //         int res = tranverse2(n2, mid, val1);

// //         if (res > 0)
// //         {
// //             r = mid - 1;
// //         }
// //         else if (res < 0)
// //         {
// //             l = mid + 1;
// //         }
// //         else
// //         {
// //             ans = mid;
// //             r = mid - 1;
// //         }
// //     }

// //     if (ans == -1)
// //     {
// //         cout << "Impossible";
// //     }
// //     else
// //     {
// //         cout << ans;
// //     }

// // #ifdef LOCAL
// //     cerr
// //         << "Time elapsed: " << clock() / 1000 << " ms" << endl;
// // #endif
// //     cout << flush;
// //     return 0;
// // }

// // 2023/11/07 22:44:27
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

// ll trans(char ch)
// {
//     if (isdigit(ch))
//     {
//         return ch - '0';
//     }

//     return ch - 'a' + 10;
// }

// ll translate(const string& s, ll r)
// {
//     ll res = 0;
//     ll wei = 1;
//     for (char ch : s)
//     {
//         ll j = trans(ch);
//         res += j * wei;
//         wei *= r;
//     }

//     return res;
// }

// int translate2(const string& s, ll r, ll val)
// {
//     ll sum = 0;
//     ll wei = 1;
//     for (char ch : s)
//     {
//         if (wei > val)
//         {
//             return 1;
//         }

//         ll j = trans(ch);
//         sum += j * wei;
//         wei *= r;
//     }

//     if (sum > val)
//         return 1;
//     else if (sum < val)
//         return -1;
//     else
//         return 0;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     string n1, n2;
//     int tag, jinzhi;
//     cin >> n1 >> n2 >> tag >> jinzhi;
//     if (tag == 2)
//     {
//         swap(n1, n2);
//     }

//     reverse(n1.begin(), n1.end());
//     reverse(n2.begin(), n2.end());

//     ll val = translate(n1, jinzhi);
//     ll max_digit = 0;
//     for (char ch : n2)
//     {
//         ll j = trans(ch);
//         max_digit = max(max_digit, j);
//     }

//     ll l = max_digit + 1, r = 1e18;
//     ll ans = -1;
//     while (l <= r)
//     {
//         ll mid = l + (r - l) / 2;
//         int ret = translate2(n2, mid, val);
//         if (ret > 0)
//         {
//             r = mid - 1;
//         }
//         else if (ret < 0)
//         {
//             l = mid + 1;
//         }
//         else
//         {
//             ans = mid;
//             r = mid - 1;
//         }
//     }

//     if (ans == -1)
//     {
//         cout << "Impossible";
//     }
//     else
//     {
//         cout << ans;
//     }

// #ifdef LOCAL
//     cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
// #endif
//     cout << flush;
//     return 0;
// }

// 2023/11/07 23:05:25
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
constexpr int N = 1000005;

int trans(char ch)
{
    if (isdigit(ch))
    {
        return ch - '0';
    }

    return ch - 'a' + 10;
}

ll tranverse(const string& s, ll r)
{
    ll sum = 0;
    ll wei = 1;
    for (char ch : s)
    {
        ll j = trans(ch);
        sum += j * wei;
        wei *= r;
    }

    return sum;
}

ll tranverse2(const string& s, ll r, ll val)
{
    ll sum = 0;
    ll wei = 1;
    for (char ch : s)
    {
        if (wei > val)
        {
            return 1;
        }
        ll j = trans(ch);
        sum += j * wei;
        wei *= r;
    }

    if (sum > val)
        return 1;
    else if (sum < val)
        return -1;
    else
        return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string n1, n2;
    int tag, r;
    cin >> n1 >> n2 >> tag >> r;
    if (tag == 2)
    {
        swap(n1, n2);
    }

    reverse(n1.begin(), n1.end());
    reverse(n2.begin(), n2.end());

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}