// 2023/07/22 11:02:24
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

    int tt;
    cin >> tt;
    while (tt--)
    {
        int n, k;
        cin >> n >> k;
        k -= 3;
        n -= k;
        while (k--)
            cout << 1 << ' ';
        
        if (n & 1)
        {
            cout << 1 << ' ' << (n - 1) / 2 << ' ' << (n - 1) / 2 << ' ';
        }
        else
        {
            if (n % 4 == 0)
                cout << n / 4 << ' ' << n / 4 << ' ' << n / 2 << ' ';
            else
                cout << 2 << ' ' << (n - 2) / 2 << ' ' << (n - 2) / 2 << ' ';
        }
        

        cout << '\n';

        // int l = 1, r = n;
        // int maxn = -1;
        // while (l <= r)
        // {
        //     int mid = l + (r - l) / 2;
        //     if (k * mid > n)
        //         r = mid - 1;
        //     else if (k * mid < n)
        //         l = mid + 1;
        //     else
        //     {
        //         maxn = mid;
        //         break;
        //     }
        // }
        // if (maxn == -1)
        // {
        //     maxn = r + 1;
        // }

        // l = 1, r = k;
        // int cnt = -1;
        // while (l <= r)
        // {
        //     int mid = l + (r - l) / 2;
        //     int sum = mid * maxn + (k - mid);
        //     if (sum > n)
        //         r = mid - 1;
        //     else if (sum < n)
        //         l = mid + 1;
        //     else
        //     {
        //         cnt = mid;
        //         break;
        //     }
        // }

        // if (cnt == -1)
        //     cnt = r;
        // int minn = 0;
        // if (k != cnt)
        // {
        //     minn = (n - cnt * maxn) / (k - cnt);
        // }

        // while (maxn * minn / __gcd(maxn, minn) > n / 2)
        // {
        //     maxn++;
        //     l = 1, r = k;
        //     cnt = -1;
        //     while (l <= r)
        //     {
        //         int mid = l + (r - l) / 2;
        //         int sum = mid * maxn + (k - mid);
        //         if (sum > n)
        //             r = mid - 1;
        //         else if (sum < n)
        //             l = mid + 1;
        //         else
        //         {
        //             cnt = mid;
        //             break;
        //         }
        //     }

        //     if (cnt == -1)
        //         cnt = r;
        //     minn = 0;
        //     if (k != cnt)
        //     {
        //         minn = (n - cnt * maxn) / (k - cnt);
        //     }
        // }

        // for (int i = 0; i < cnt; i++)
        //     cout << maxn << ' ';
        // for (int i = cnt; i < k; i++)
        //     cout << minn << " \n"[i == k - 1];
    }

    cout << endl;
    return 0;
}