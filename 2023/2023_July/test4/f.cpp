// 2023/07/27 15:40:21
#pragma GCC optimize(2)
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
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = (int)(1e4 + 7);
const int N = 10000005;
int Case = 1;

ll fast_pow(ll a, ll n)
{
    ll res = 1;
    while (n > 0)
    {
        if (n & 1)
            res = res * a % 1000;
        a = a * a % 1000;
        n /= 2;
    }

    return res;
}

void solve()
{
    double n;
    int k;
    cin >> n >> k;
    double ans1;
    ll ans2;
    ans2 = fast_pow((ll)n, (ll)k);

    double p = k * log10(n);
    ans1 = pow(10, p - (int)p) * 100;


    // cout << "Case " << Case++ << ": " << (ll)ans1 << ' ' << ans2 << '\n';
    printf("Case %d: %03lld %03lld\n", Case++, (ll)ans1, ans2);
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

    cout << flush;
    return 0;
}