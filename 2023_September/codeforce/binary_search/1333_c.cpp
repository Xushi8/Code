// 2023/10/08 10:46:40
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
ll ans;

void func(const vector<ll>& a, const vector<ll>& b, const vector<ll>& c)
{
    for (size_t i = 0; i < b.size(); i++)
    {
        ll target = b[i];
        auto it1 = lower_bound(a.begin(), a.end(), target);
        if (it1 == a.end() || (*it1 > target && it1 != a.begin()))
            it1--;
        auto it2 = lower_bound(c.begin(), c.end(), target);
        if (it2 == c.end())
            it2--;

        ans = min(ans, (*it1 - target) * (*it1 - target) + (*it2 - target) * (*it2 - target) + (*it1 - *it2) * (*it1 - *it2));
    }
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n), b(m), c(k);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    for (int i = 0; i < k; i++)
        cin >> c[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    if (a.front() > b.back())
    {
        swap(a, b);
        swap(n, m);
    }
    if (b.front() > c.back())
    {
        swap(b, c);
        swap(m, k);
    }
    if (a.front() > b.back())
    {
        swap(a, b);
        swap(n, m);
    }

    ans = INT64_MAX;
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
    cout << endl;
    return 0;
}