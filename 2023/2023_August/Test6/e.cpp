// 2023/08/05 11:33:08
#ifndef LOCAL
#pragma GCC optimize(2)
#endif
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
    
    ll n, m;
    cin >> n >> m;
    ull ans = 0;
    for (ll i = 0; i < n; i++)
    {
        ll t, T, x, cost;
        cin >> t >> T >> x >> cost;
        if (T <= t)
            ans += cost + m * x;
        else
        {
            ll a = cost + m * x;
            ll b = cost * (m / (T - t) + (m % (T - t) != 0));
            ans += min(a, b);
        }
    }
    cout << ans << '\n';

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}