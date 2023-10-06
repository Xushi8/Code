// 2023/10/05 18:36:01
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

void solve()
{
    ll x, y, p, q;
    cin >> x >> y >> p >> q;

    auto check = [&](ll k) -> bool
        {
            return 0 <= k * p - x && k * p - x <= k * q - y;
        };

    ll l = 0, r = 2e9, ans = -1;
    while (l <= r)
    {
        ll mid = l + (r - l) / 2;
        if (check(mid))
            ans = mid, r = mid - 1;
        else
            l = mid + 1;
    }

    cout << (ans == - 1 ? -1 : ans * q - y) << '\n';
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