// 2023/10/18 19:59:59
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
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 1000005;

ll n, k;

bool check(ll val)
{
    ll a1 = k - val + 1;
    ll sum = 1 + val * (a1 - 1 + k - 1) / 2;
    // 1 + (a1 - 1) + ... + (k - 1);
    return sum >= n;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> k;
    if (!check(k - 1))
        cout << -1 << endl;
    else if (n == 1)
        cout << 0 << endl;
    else
    {
        ll l = 1, r = k - 1, ans = r;
        while (l <= r)
        {
            ll mid = (l + r) / 2;
            if (check(mid))
                ans = mid, r = mid - 1;
            else
                l = mid + 1;
        }
        cout << ans << endl;
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}