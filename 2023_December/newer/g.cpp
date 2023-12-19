// 2023/12/15 09:41:31
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
#include <bitset>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 1000005;

ll ans;

void func(vector<ll> const& a, vector<ll> const& b, vector<ll> const& c)
{
    for (ll x : b)
    {
        auto it1 = upper_bound(a.begin(), a.end(), x);
        if (it1 != a.begin())
        {
            it1--;
        }
        auto it2 = lower_bound(c.begin(), c.end(), x);
        if (it2 == c.end())
        {
            it2--;
        }
        ll y = *it1;
        ll z = *it2;
        ans = min(ans, (x - y) * (x - y) + (x - z) * (x - z) + (y - z) * (y - z));
    }
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n), b(m), c(k);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    for (int i = 0; i < k; i++)
    {
        cin >> c[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    ans = 9e18;
    func(a, b, c);
    func(a, c, b);
    func(b, a, c);
    func(b, c, a);
    func(c, a, b);
    func(c, b, a);
    cout << ans << '\n';
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
    return 0;
}