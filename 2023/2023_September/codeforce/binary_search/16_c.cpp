// 2023/10/04 22:12:09
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll a, b, x, y;
    cin >> a >> b >> x >> y;
    ll gcd = __gcd(x, y);
    x /= gcd;
    y /= gcd;

    auto check = [&](ll val) -> bool
        {
            return val * x <= a && val * y <= b;
        };

    ll l = 0, r = 2e9, ans = 0;
    while (l <= r)
    {
        ll mid = l + (r - l) / 2;
        if (check(mid))
            ans = mid, l = mid + 1;
        else
            r = mid - 1;
    }

    cout << ans * x << ' ' << ans * y << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}