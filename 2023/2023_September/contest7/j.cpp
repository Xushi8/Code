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

// int func(const string& a, const string& b)
// {
//     int minn = (int)min(a.size(), b.size());
//     for (int i = minn; i >= 1; i--)
//     {
//         for (int j = 0; j + i - 1 < minn; j++)
//         {
//             string tmp = a.substr(j, i);
//             if (b.find(tmp) != string::npos)
//             {
//                 return i;
//             }
//         }
//     }
//     return 0;
// }

// void solve()
// {
//     int n;
//     cin >> n;
//     vector<string> arr(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }

//     int ans = 0;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             ans = max(ans, func(arr[i], arr[j]));
//         }
//     }

//     cout << ans << '\n';
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int tt;
//     cin >> tt;
//     while (tt--)
//     {
//         solve();
//     }

// #ifdef LOCAL
//     cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
// #endif
//     cout << flush;
//     return 0;
// }



// 2023/09/27 14:32:29
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
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 1000005;
int dp[55][55];

int func(string a, string b)
{
    a = ' ' + a;
    b = ' ' + b;
    int res = 0;
    memset(dp, 0, sizeof(dp));
    for (size_t i = 1; i < a.size(); i++)
    {
        for (size_t j = 1; j < b.size(); j++)
        {
            if (a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            res = max(res, dp[i][j]);
        }
    }

    return res;
}

void solve()
{
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            ans = max(ans, func(s[i], s[j]));
        }
    }
    cout << ans << '\n';
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
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}