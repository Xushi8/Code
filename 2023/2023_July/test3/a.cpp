// // 2023/07/24 08:41:48
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
// using namespace std;

// using ll = long long;
// using ull = unsigned long long;
// using pii = pair<int, int>;
// const int INF = 0x3f3f3f3f;
// const int MOD = (int)(1e9 + 7);
// const int N = 1000005;
// char arr[8][8];
// bool deletex[8], deletey[8];
// vector<vector<int>> usedx, usedy;
// int n, m, k;

// int ans;

// bool check()
// {
//     vector<int> tmpx, tmpy;
//     for (int i = 1; i <= n; i++)
//     {
//         if (deletex[i] == 1)
//         {
//             tmpx.emplace_back(i);
//         }
//     }

//     for (int j = 1; j <= m; j++)
//     {
//         if (deletey[j] == 1)
//             tmpy.emplace_back(j);
//     }


//     for (size_t i = 0; i < usedx.size(); i++)
//     {
//         if (usedx[i] == tmpx && usedy[i] == tmpy)
//             return false;
//     }



//     int sum = 0;
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= m; j++)
//         {
//             if (!deletex[i] && !deletey[j] && arr[i][j] == '#')
//                 sum++;
//         }
//     }

//     if (sum == k)
//     {
//         usedx.emplace_back(tmpx);
//         usedy.emplace_back(tmpy);
//         return true;
//     }
//     else
//         return false;
// }

// void dfsy(int deep)
// {
//     if (deep > m + 1)
//         return;

//     if (deep == 0)
//     {
//         dfsy(deep + 1);
//         return;
//     }

//     if (check())
//         ans++;

//     for (int j = 1; j <= m; j++)
//     {
//         if (!deletey[j])
//         {
//             deletey[j] = 1;
//             dfsy(deep + 1);
//             deletey[j] = 0;
//         }
//     }
// }

// void dfsx(int deep)
// {
//     if (deep > n + 1)
//         return;

//     if (deep == 0)
//     {
//         dfsy(0);
//         dfsx(deep + 1);
//         return;
//     }

//     for (int i = 1; i <= n; i++)
//     {
//         if (!deletex[i])
//         {
//             deletex[i] = 1;
//             dfsy(0);
//             dfsx(deep + 1);
//             deletex[i] = 0;
//         }
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     cin >> n >> m >> k;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> (arr[i] + 1);
//     }

//     dfsx(0);

//     cout << ans << '\n';

//     cout << endl;
//     return 0;
// }


// 2023/07/24 14:16:25
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
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    int all = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            all += arr[i][j] == '#';
        }
    }

    int ans = 0;

    for (int S = 0; S < (1 << n); S++)
    {
        for (int V = 0; V < (1 << m); V++)
        {
            int cnt = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (((S >> i & 1) || (V >> j & 1)) && arr[i][j] == '#')
                        cnt++;
                }
            }

            if (cnt + k == all)
                ans++;
        }
    }

    cout << ans << '\n';

    cout << endl;
    return 0;
}