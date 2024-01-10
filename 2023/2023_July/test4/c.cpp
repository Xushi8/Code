// 2023/07/27 15:10:08
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
// int cnt;

// ostream& operator << (ostream& out, __uint128_t num)
// {
//     if (num >= 10)
//     {
//         cout << (num / 10);
//     }

//     cout.put((char)(num % 10 + '0'));
//     if (num % 10 == 0)
//         cnt++;
    
//     return out;
// }

int get_num(int n)
{
    int res = 0;
    while (n > 0)
    {
        res += n / 5;
        n /= 5;
    }

    return res;
}

int solve()
{
    int n;
    cin >> n;
    int l = 5, r = 800000005;
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        if (get_num(mid) >= n)
            r = mid;
        else
            l = mid + 1;
    }

    if (get_num(r) != n)
        return 0;
    else
        return r;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    // __uint128_t sum = 1;
    // for (int i = 1; i <= 50; i++)
    // {
    //     sum *= i;
    //     cnt = 0;
    //     cout << i << ' ' << sum << ' ' << cnt << ' ' << '\n';
    // }

    int tt;
    cin >> tt;
    int Case = 1;
    // cout << get_num(100000005);
    while (tt--)
    {
        int ans = solve();
        if (ans == 0)
        {
            cout << "Case " << Case++ << ": " << "impossible" << '\n';
        }
        else
        {
            cout << "Case " << Case++ << ": " << ans << '\n';
        }
    }


    cout << flush;
    return 0;
}