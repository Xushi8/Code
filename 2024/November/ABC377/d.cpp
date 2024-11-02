// 2024/11/02 22:00:34
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
    int n, m;
    cin >> n >> m;
    vector<pii> a(n);
    for (auto& [x, y] : a)
    {
        cin >> x >> y;
        x--; y--;
    }

    vector<int> L(m, -1);
    for (auto [l, r] : a)
    {
        L[r] = max(L[r], l);
    }

    int pre = -1;
    i64 ans = 0;
    for (int i = 0; i < m; i++)
    {
        pre = max(pre, L[i]);
        ans += i - pre;
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
