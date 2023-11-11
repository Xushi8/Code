#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

using ll = long long;
ll ans;

void func(const vector<ll>& a, const vector<ll>& b, const vector<ll>& c)
{            
    for (size_t i = 0; i < b.size(); i++)
    {
        ll target = b[i];
        auto it1 = upper_bound(a.begin(), a.end(), target);
        if(it1 != a.begin())
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

    return 0;
}