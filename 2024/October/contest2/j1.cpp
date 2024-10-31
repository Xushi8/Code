// 2024/10/15 21:31:55
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
    int n;
    cin >> n;
    vector<i64> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<pll> ans;
    for (int i = 63; i >= 0; i--)
    {
        vector<int> has;
        for (int j = 0; j < n; j++)
        {
            if ((a[j] >> i) & 1)
            {
                has.emplace_back(j);
            }
        }
        if (has.empty())
            continue;
        if (has.size() > 2)
        {
            cout << -1 << '\n';
            return;
        }
        int x = has.front();
        int y = has.back();
        ans.emplace_back(x, a[x]);
        a[y] ^= std::exchange(a[x], 0);
    }
    cout << ans.size() << '\n';
    for (auto [x, y] : ans)
    {
        cout << x + 1 << ' ' << y << '\n';
    }
}

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
