// 2024/10/16 17:09:24
#ifdef LOCAL
#include <basic_std_lib.h>
#else
#include <bits/stdc++.h>
#endif
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 1e6 + 6;

void solve()
{
    int n, s;
    cin >> n >> s;
    vector<pii> a(n);
    for (int i = 0; i < n; i++)
    {
        int t, c;
        cin >> t >> c;
        a[i] = {t, c};
    }

    sort(a.begin(), a.end(), [&](pii const& lhs, pii const& rhs)
        {
            auto const& [ti, ci] = lhs;
            auto const& [tj, cj] = rhs;
            // return s * (cj - ci) + ti * cj - tj * ci > 0;
            return s * cj + 2 * s * ci + tj * ci >
                   s * ci + 2 * s * cj + ti * cj;
        });

    i64 ans = 0;
    i64 now = 0;
    for (auto [t, c] : a)
    {
        now += s + c;
        ans += now * c;
    }
    cout << ans << '\n';
}

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
