// 2024/07/29 19:30:09
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
using u64 = uint64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 1000005;

using pii = pair<int, int>;
void solve()
{
    int n;
    cin >> n;
    vector<pii> a(n);
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        a[i] = {l, r};
    }
    sort(a.begin(), a.end(), [](pii const& l, pii const& r)
        {
            return l.second < r.second;
        });
    int ans = 0;
    int last = -1;
    for (auto [l, r] : a)
    {
        if (l >= last)
        {
            ans++;
            last = r;
        }
    }
    cout << ans << '\n';
}