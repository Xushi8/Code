// 2023/06/30 09:47:47
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
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = (ll)(1e9 + 7);
const int N = 100005;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     ll a, b;
//     while (cin >> a >> b)
//     {
//         bool flag = false;
//         for (ll i = 1; i <= a / 2; i++)
//         {
//             ll j = a - i;
//             if (i * j / __gcd(i, j) == b)
//             {
//                 flag = true;
//                 cout << i << ' ' << j << '\n';
//                 break;
//             }
//         }
//         if (!flag)
//         {
//             cout << "No answer\n";
//         }
//     }

//     cout << endl;
//     return 0;
// }


// 2023/06/30 09:55:05

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int tt;
//     cin >> tt;
//     while (tt--)
//     {
//         int n, m, K;
//         cin >> n >> m >> K;
//         vector<string> arr(n);
//         vector<int> cnt(m, 0); // 记录每一列 1 的个数
//         for (int i = 0; i < n; i++)
//         {
//             cin >> arr[i];
//             for (int j = 0; j < m; j++)
//             {
//                 cnt[j] += (arr[i][j] == '1');
//             }
//         }
//     }

//     cout << endl;
//     return 0;
// }



// 2023/06/30 10:08:06
// int n;
// int ans[15];
// bool used[15];

// void dfs(int deep)
// {
//     if (deep == n)
//     {
//         for (int i = 0; i < n; i++)
//             cout << ans[i];
//         cout << '\n';
//         return;
//     }

//     for (int i = 1; i <= n; i++)
//     {
//         if (!used[i])
//         {
//             used[i] = true;
//             ans[deep] = i;
//             dfs(deep + 1);
//             used[i] = false;
//         }
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     while (cin >> n)
//     {
//         dfs(0);
//     }

//     cout << endl;
//     return 0;
// }


// 2023/06/30 10:49:39

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
//         vector<pii> arr(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin >> arr[i].first >> arr[i].second;
//         }
        
//         int max_line = 0;
//         for (int i = 0; i < n; i++)
//         {
//             map<pii, int> m;
//             int chongfu = 1;
//             for (int j = i + 1; j < n; j++)
//             {
//                 if (arr[i].first == arr[j].first && arr[i].second == arr[j].second)
//                 {
//                     chongfu++;
//                     continue;
//                 }

//                 int dx = arr[j].first - arr[i].first;
//                 int dy = arr[j].second - arr[i].second;
//                 int gcd = __gcd(dx, dy);
//                 m[make_pair(dx / gcd, dy / gcd)]++;
//             }
//             max_line = max(max_line, chongfu);
//             for (auto it = m.begin(); it != m.end(); it++)
//             {
//                 max_line = max(max_line, it->second + chongfu);
//             }
//         }

//         cout << n - max_line << '\n';
//     }


//     cout << endl;
//     return 0;
// }


// 2023/06/30 12:11:43

// bool isnp[10000005];
// vector<ll> primes;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     for (int i = 2; i < 10000005; i++)
//     {
//         if (!isnp[i])
//             primes.emplace_back(i);

//         for (ll p : primes)
//         {
//             if (p * i > 10000005)
//                 break;

//             isnp[p * i] = true;

//             if (i % p == 0)
//                 break;
//         }
//     }

//     for (auto& x : primes)
//         x *= x;

//     int tt;
//     cin >> tt;
//     while (tt--)
//     {
//         ll tmp;
//         cin >> tmp;
//         if (binary_search(primes.begin(), primes.end(), tmp))
//             cout << "YES\n";
//         else
//             cout << "NO\n";
//     }

//     cout << endl;
//     return 0;
// }




// 2023/06/30 13:34:59

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    // vector<int> arr(10);
    // for (int i = 0; i < 10; i++)
    //     cin >> arr[i];

    // cout << *max_element(arr.begin(), arr.end()) << endl;
    // cout << arr.max_size() << '\n';

    cout << hex << 2305843009213693951 << '\n';

    cout << endl;
    return 0;
}