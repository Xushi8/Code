// 2024/09/25 15:21:59
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

using i64 = int64_t;
using u64 = uint64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 1000005;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (n == 1)
    {
        if (a.front() < k)
            k++;
        cout << k - 1 << '\n';
        return;
    }

    int g = a.front();
    for (auto x : a)
    {
        g = std::gcd(g, x);
    }


    // 0, 0 + g, 0 + 2 * g, 0 + 3 * g ...
    i64 maxx = i64(n - 1) * g;
    i64 contain = maxx - (n - 1);
    i64 ans;
    if (k <= contain)
    {
        i64 m = (k - 1) / (g - 1);
        k -= m * (g - 1);
        ans = g * m + k;
    }
    else
    {
        ans = maxx + (k - contain);
    }
    cout << ans << '\n';
}