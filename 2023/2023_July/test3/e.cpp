// 2023/07/25 09:16:49
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
#define double long double

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cout << setprecision(10) << fixed;
    int tt;
    cin >> tt;
    while (tt--)
    {
        double n, p1, v1, p2, v2;
        cin >> n >> p1 >> v1 >> p2 >> v2;
        if (p1 > p2)
        {
            swap(p1, p2);
            swap(v1, v2);
        }

        double ans;
        ans = max((n - p1) / v1, p2 / v2);
        ans = min({ ans, (n - p2 + n) / v2, (p2 + n) / v2 });
        ans = min({ ans, (p1 + n) / v1, (n - p1 + n) / v1 });
        double l = p1, r = p2;
        double mid;
        double t1, t2;
        for (int i = 0; i < 100; i++)
        {
            mid = (r + l) / 2;
            t1 = min(p1 + mid, mid - p1 + mid) / v1;
            t2 = min(n - p2 + n - mid, p2 - mid + n - mid) / v2;
            ans = min(ans, max(t1, t2));
            if (t1 < t2)
                l = mid;
            else
                r = mid;
        }

        cout << ans << '\n';
        

        // double ans = min((p1 + n) / v1, (n - p1 + n) / v1);
        // ans = min(ans, min((n - p2 + n) / v2, (p2 + n) / v2));
        // ans = min(ans, max(p2 / v2, (n - p1) / v1));

        // double l = 0.0, r = n;
        // double mid;
        // double t1, t2;
        // for (int i = 0; i < 100; i++)
        // {
        //     mid = (r + l) / 2.0;
        //     t1 = min(p1 + mid, mid - p1 + mid) / v1;
        //     t2 = min(n - p2 + n - mid, p2 - mid + n - mid) / v2;
        //     ans = min(ans, max(t1, t2));
        //     if (t1 > t2)
        //         r = mid;
        //     else
        //         l = mid;
        // }

        // cout << ans << '\n';
    }

    cout << endl;
    return 0;
}