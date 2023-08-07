// 2023/08/07 09:11:32
// #ifndef LOCAL
// // #pragma GCC optimize(2)
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

// int cnt[1005];
// int operation[1005];
// int arr[N];

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int n, m;
//     cin >> n >> m;
//     int len = (int)sqrt(n);
//     while (m--)
//     {
//         int op, l, r;
//         cin >> op >> l >> r;
//         l--; r--;
//         if (op == 0)
//         {
//             for (int i = l / len + 1; i < r / len; i++)
//             {
//                 operation[i]++;
//                 cnt[i] = len - cnt[i];
//             }

//             for (int i = l; i < (l / len + 1) * len; i++)
//             {
//                 arr[i] = !arr[i];
//             }
//             cnt[l / len] = 0;
//             if (operation[l / len] & 1)
//             {
//                 operation[l / len] = 0;
//                 for (int i = l / len * len; i < (l / len + 1) * len; i++)
//                 {
//                     arr[i] = !arr[i];
//                 }
//             }

//             for (int i = l / len * len; i < (l / len + 1) * len; i++)
//             {
//                 cnt[l / len] += arr[i] == 1;
//             }

//             if (l / len == r / len)
//                 continue;

//             for (int i = r / len * len; i <= r; i++)
//             {
//                 arr[i] = !arr[i];
//             }
//             cnt[r / len] = 0;
//             if (operation[r / len] & 1)
//             {
//                 operation[r / len] = 0;
//                 for (int i = r / len * len; i < (r / len + 1) * len; i++)
//                 {
//                     arr[i] = !arr[i];
//                 }
//             }

//             for (int i = r / len * len; i < (r / len + 1) * len; i++)
//             {
//                 cnt[r / len] += arr[i] == 1;
//             }
//         }
//         else
//         {
//             int ans = 0;
//             for (int i = (l / len + 1); i < r / len; i++)
//             {
//                 ans += cnt[i];
//             }

//             if (operation[l / len] & 1)
//             {
//                 operation[l / len] = 0;
//                 for (int i = l / len * len; i < (l / len + 1) * len; i++)
//                 {
//                     arr[i] = !arr[i];
//                 }
//             }
//             for (int i = l; i < (l / len + 1) * len; i++)
//             {
//                 ans += arr[i] == 1;
//             }

//             if (r / len == l / len)
//                 continue;

//             if (operation[r / len] & 1)
//             {
//                 operation[r / len] = 0;
//                 for (int i = r / len * len; i < (r / len + 1) * len; i++)
//                 {
//                     arr[i] = !arr[i];
//                 }
//             }
//             for (int i = r / len * len; i <= r; i++)
//             {
//                 ans += arr[i] == 1;
//             }

//             cout << ans << '\n';
//         }
//     }

// #ifdef LOCAL
//     cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
// #endif
//     cout << endl;
//     return 0;
// }


// // 2023/08/07 14:42:28
// #ifndef LOCAL
// // #pragma GCC optimize(2)
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

// int cnt[1005], operation[1005], arr[N];

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int n, m;
//     cin >> n >> m;
//     int len = (int)sqrt(n);
//     while (m--)
//     {
//         int op, l, r;
//         cin >> op >> l >> r;
//         l--; r--;
//         if (op == 0)
//         {
//             // 大区间
//             for (int i = (l / len + 1); i < r / len; i++)
//             {
//                 operation[i]++;
//                 cnt[i] = len - cnt[i];
//             }

//             // 区间左侧
//             if (operation[l / len] & 1)
//             {
//                 operation[l / len] = 0;
//                 for (int i = l / len * len; i < (l / len + 1) * len; i++)
//                 {
//                     arr[i] = !arr[i];
//                 }
//             }
//             for (int i = l; i < (l / len + 1) * len && i <= r; i++)
//             {
//                 arr[i] = !arr[i];
//             }

//             cnt[l / len] = 0;
//             for (int i = l / len * len; i < (l / len + 1) * len; i++)
//             {
//                 cnt[l / len] += (arr[i] == 1);
//             }

//             if (l / len == r / len) // l, r在同一个区间内
//                 continue;

//             // 区间右侧
//             if (operation[r / len] & 1)
//             {
//                 operation[r / len] = 0;
//                 for (int i = r / len * len + 1; i < (r / len + 1) * len; i++)
//                 {
//                     arr[i] = !arr[i];
//                 }
//             }
//             for (int i = r / len * len + 1; i <= r; i++)
//             {
//                 arr[i] = !arr[i];
//             }

//             cnt[r / len] = 0;
//             for (int i = r / len * len + 1; i < (r / len + 1) * len; i++)
//             {
//                 cnt[r / len] += (arr[i] == 1);
//             }
//         }
//         else
//         {
//             int ans = 0;
//             for (int i = l / len + 1; i < r / len; i++)
//             {
//                 ans += cnt[i];
//             }

//             // 区间左侧
//             if (operation[l / len] & 1)
//             {
//                 operation[l / len] = 0;
//                 for (int i = l / len * len; i < (l / len + 1) * len; i++)
//                 {
//                     arr[i] = !arr[i];
//                 }
//             }
//             for (int i = l; i < (l / len + 1) * len && i <= r; i++)
//             {
//                 ans += arr[i] == 1;
//             }

//             if (r / len == l / len)
//                 continue;

//             // 区间右侧
//             if (operation[r / len] & 1)
//             {
//                 operation[r / len] = 0;
//                 for (int i = r / len * len + 1; i < (r / len + 1) * len; i++)
//                 {
//                     arr[i] = !arr[i];
//                 }
//             }
//             for (int i = r / len * len + 1; i <= r; i++)
//             {
//                 ans += arr[i] == 1;
//             }

//             cout << ans << '\n';
//         }
//     }

// #ifdef LOCAL
//     cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
// #endif
//     cout << flush;
//     return 0;
// }


// 2023/08/07 15:24:10
#ifndef LOCAL
// #pragma GCC optimize(2)
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

int cnt[N], arr[N], operation[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    int len = (int)sqrt(n);
    while (m--)
    {
        int op, l, r;
        cin >> op >> l >> r;
        // l--; r--;
        if (op == 0)
        {
            for (int i = l / len + 1; i < r / len; i++)
            {
                operation[i]++;
                cnt[i] = len - cnt[i];
            }

            if (operation[l / len] & 1)
            {
                operation[l / len] = 0;
                for (int i = l / len * len; i < (l / len + 1) * len; i++)
                {
                    arr[i] = !arr[i];
                }
            }
            for (int i = l; i < (l / len + 1) * len && i <= r; i++)
            {
                arr[i] = !arr[i];
            }
            cnt[l / len] = 0;
            for (int i = l / len * len; i < (l / len + 1) * len; i++)
            {
                cnt[l / len] += (arr[i] == 1);
            }

            if (l / len == r / len)
                continue;

            if (operation[r / len] & 1)
            {
                operation[r / len] = 0;
                for (int i = r / len * len; i < (r / len + 1) * len; i++)
                {
                    arr[i] = !arr[i];
                }
            }

            for (int i = r / len * len; i <= r; i++)
            {
                arr[i] = !arr[i];
            }
            cnt[r / len] = 0;
            for (int i = r / len * len; i < (r / len + 1) * len; i++)
            {
                cnt[r / len] += arr[i] == 1;
            }
        }
        else
        {
            int ans = 0;
            for (int i = l / len + 1; i < r / len; i++)
            {
                ans += cnt[i];
            }

            if (operation[l / len] & 1)
            {
                operation[l / len] = 0;
                for (int i = l / len * len; i < (l / len + 1) * len; i++)
                {
                    arr[i] = !arr[i];
                }
            }
            for (int i = l; i < (l / len + 1) * len && i <= r; i++)
            {
                ans += arr[i] == 1;
            }
            

            if (l / len == r / len)
            {
                cout << ans << '\n';
                continue;
            }

            if (operation[r / len] & 1)
            {
                operation[r / len] = 0;
                for (int i = r / len * len; i < (r / len + 1) * len; i++)
                {
                    arr[i] = !arr[i];
                }
            }
            for (int i = r / len * len; i <= r; i++)
            {
                ans += arr[i] == 1;
            }

            cout << ans << '\n';
        }
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}