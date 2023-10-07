// 2023/10/06 18:01:56
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

bool check(ll val, ll n, ll m, ll k)
{
    ll cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        cnt += min(val / i, m);
    }
    return cnt >= k;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n, m, k;
    cin >> n >> m >> k;
    ll l = 1, r = n * m, ans = 1;
    while (l <= r)
    {
        ll mid = l + (r - l) / 2;
        if (check(mid, n, m, k))
            ans = mid, r = mid - 1;
        else
            l = mid + 1;
    }

    cout << ans << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}