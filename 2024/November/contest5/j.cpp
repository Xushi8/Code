// 2024/11/09 13:20:46
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
    vector<pii> a(n);
    for (auto& [x, y] : a)
    {
        cin >> x >> y;
    }

    for (int i = 1; i < n; i++)
    {
        bool ok = a[i].first >= a[i - 1].first && a[i].second >= a[i - 1].second;
        if (!ok)
        {
            cout << "no\n";
            return;
        }
    }

    cout << "yes\n";
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
