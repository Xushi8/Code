// 2024/07/29 19:39:14
#ifdef LOCAL
#include <basic_std_lib.h>
#else
#include <bits/stdc++.h>
#endif
using namespace std;

void solve();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    tt = 1;
    while (tt--)
    {
        solve();
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}

using i64 = int64_t;
using pii = pair<int, int>;
using u64 = uint64_t;
using pll = pair<i64, i64>;
constexpr int N = 1000005;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<pii> a(n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        a[i] = {x, y};
    }
    sort(a.begin(), a.end(), [](pii const& l, pii const& r)
        {
            int add1 = min(l.first * 2, l.second) - min(l.first, l.second);
            int add2 = min(r.first * 2, r.second) - min(r.first, r.second);
            return add1 > add2;
        });
    i64 ans = 0;
    for (int i = 0; i < k; i++)
    {
        auto [l, r] = a[i];
        l *= 2;
        ans += min(l, r);
    }
    for (int i = k; i < n; i++)
    {
        auto [l, r] = a[i];
        ans += min(l, r);
    }
    cout << ans << '\n';
}