// 2023/10/06 17:11:51
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
#define double long double

void solve()
{
    double a, b, c;
    cin >> a >> b >> c;
    double average = (a + b) / 2.0;
    if (c > average)
    {
        int l = 0, r = 1e9, ans = 0; // ans是混合物的数量
        double minn = c - average;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            double now = (a * mid + b * mid + a) / (2 * mid + 1);
            if (now < c)
                r = mid - 1;
            else
                l = mid + 1;

            if (fabs(now - c) < minn)
                ans = mid, minn = fabs(now - c);
            else if (fabs(now - c) == minn)
                ans = min(ans, mid);

            // if (now < minn)
            //     ans = mid, r = mid - 1, minn = now;
            // else
            //     l = mid + 1;
        }

        cout << 2 * ans + 1 << '\n';
    }
    else
    {
        cout << "2\n";
    }
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