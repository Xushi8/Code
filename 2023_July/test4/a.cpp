// // 2023/07/27 09:10:46
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
// using namespace std;

// using ll = long long;
// using ull = unsigned long long;
// using pii = pair<int, int>;
// const int INF = 0x3f3f3f3f;
// const int MOD = (int)(1e9 + 7);
// const int N = 1000005;

// vector<int> primes;

// void solve(int n)
// {
//     bool flag = 0;
//     if (n < 0)
//     {
//         flag = 1;
//         n = -n;
//     }

//     int ans = -1;
//     for (int p : primes)
//     {
//         if (p * p > n)
//             break;

//         int tot = 0;
//         while (n % p == 0)
//         {
//             n /= p;
//             tot++;
//         }

//         if (tot != 0)
//         {
//             if (ans == -1)
//                 ans = tot;
//             else
//                 ans = __gcd(ans, tot);
//         }
//     }

//     if (n > 1)
//         cout << 1 << '\n';
//     else
//     {
//         if (flag)
//         {
//             while (ans % 2 == 0)
//                 ans /= 2;
//         }

//         cout << ans << '\n';
//     }

//     // if (n > 0)
//     // {
//     //     map<int, int> m;

//     //     for (int p : primes)
//     //     {
//     //         if (p > n)
//     //             break;

//     //         while (n % p == 0 && n != 0)
//     //         {
//     //             n /= p;
//     //             m[p]++;
//     //         }
//     //     }

//     //     queue<int> que;
//     //     for (auto [x, y] : m)
//     //     {
//     //         que.emplace(y);
//     //     }

//     //     while (que.size() >= 2)
//     //     {
//     //         int a = que.front(); que.pop();
//     //         int b = que.front(); que.pop();

//     //         que.emplace(__gcd(a, b));
//     //     }

//     //     cout << que.front() << '\n';
//     // }
//     // else
//     // {
//     //     n = -n;
//     //     map<int, int> m;

//     //     for (int p : primes)
//     //     {
//     //         if (p > n)
//     //             break;

//     //         while (n % p == 0 && n != 0)
//     //         {
//     //             n /= p;
//     //             m[p]++;
//     //         }
//     //     }

//     //     queue<int> que;
//     //     for (auto [x, y] : m)
//     //     {
//     //         que.emplace(y);
//     //     }

//     //     while (que.size() >= 2)
//     //     {
//     //         int a = que.front(); que.pop();
//     //         int b = que.front(); que.pop();

//     //         que.emplace(__gcd(a, b));
//     //     }

//     //     while (que.front() % 2 == 0)
//     //         que.front() /= 2;
//     //     cout << que.front() << '\n';
//     // }
// }

// bool isnp[N];

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     primes.reserve(N / __lg(N));
//     for (int i = 2; i < N; i++)
//     {
//         if (!isnp[i])
//             primes.emplace_back(i);
//         for (int p : primes)
//         {
//             if (p * i >= N)
//                 break;

//             isnp[p * i] = 1;

//             if (i % p == 0)
//                 break;
//         }
//     }

//     int tt;
//     cin >> tt;
//     for (int Case = 1; Case <= tt; Case++)
//     {
//         cout << "Case " << Case << ": ";
//         int n;
//         cin >> n;
//         solve(n);
//     }

//     cout << flush;
//     return 0;
// }



// 2023/07/27 14:34:37
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
bool isnp[N];
vector<int> primes;

int solve()
{
    long long n;
    cin >> n;
    bool flag = 0;
    if (n < 0)
    {
        flag = 1;
        n = -n;
    }

    int ret = 0;
    for (int p : primes)
    {
        if (p * p > n)
            break;

        if (n % p == 0)
        {
            int cnt = 0;
            while (n % p == 0)
            {
                n /= p;
                cnt++;
            }

            if (ret == 0)
                ret = cnt;
            else
                ret = __gcd(ret, cnt);
        }
    }

    if (n > 1 || ret == 0)
        ret = 1;
    if (flag)
    {
        while (ret % 2 == 0)
            ret /= 2;
    }
    return ret;
}

void get_primes()
{
    for (int i = 2; i < N; i++)
    {
        if (!isnp[i])
        {
            primes.emplace_back(i);
        }
        for (int p : primes)
        {
            if (p * i >= N)
                break;

            isnp[p * i] = 1;

            if (i % p == 0)
                break;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    get_primes();
    int tt;
    cin >> tt;
    for (int i = 1; i <= tt; i++)
    {
        cout << "Case " << i << ": " << solve() << '\n';
    }

    cout << flush;
    return 0;
}