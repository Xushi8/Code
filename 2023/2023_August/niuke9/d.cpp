// // 2023/08/14 14:27:47
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
// const int N = 5005;

// int arr[N], L[N], R[N];

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int tt;
//     cin >> tt;
//     while (tt--)
//     {
//         int n;
//         cin >> n;
//         for (int i = 1; i <= n; i++)
//         {
//             cin >> arr[i];
//         }

//         stack<int> stk;
//         for (int i = 1; i <= n; i++)
//         {
//             while (!stk.empty() && arr[i] < arr[stk.top()])
//             {
//                 stk.pop();
//             }

//             L[i] = stk.empty() ? 0 : stk.top();
//             stk.emplace(i);
//         }

//         while (!stk.empty())
//             stk.pop();

//         for (int i = n; i >= 1; i--)
//         {
//             while (!stk.empty() && arr[i] < arr[stk.top()])
//             {
//                 stk.pop();
//             }

//             R[i] = stk.empty() ? n + 1 : stk.top();
//             stk.emplace(i);
//         }

//         // for (int i = 1; i <= n; i++)
//         // {
//         //     cout << L[i] << " \n"[i == n];
//         // }
//         // for (int i = 1; i <= n; i++)
//         // {
//         //     cout << R[i] << " \n"[i == n];
//         // }

//         ull ans = n * (n - 1) / 2;
//         for (int i = 1; i <= n; i++)
//         {
//             if (L[i] == 0)
//             {
//                 if (R[i] != n + 1)
//                 {
//                     ull siz = R[i] - L[i];
//                     ans -= siz * (siz - 1) / 2;
//                 }
//             }
//         }

//         cout << ans << '\n';
//     }

// #ifdef LOCAL
//     cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
// #endif
//     cout << flush;
//     return 0;
// }


// 2023/08/15 14:57:13
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
    
    
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}