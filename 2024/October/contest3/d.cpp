// 2024/10/19 17:10:51
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

    int max1{}, max0{};
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        a[i] = {x, y};
        max1 = max(max1, y);
        max0 = max(max0, x - y);
    }

    cout << (max1 + max0) << '\n';
    for (int i = 0; i < max1; i++)
    {
        cout << 1;
    }
    for (int i = 0; i < max0; i++)
    {
        cout << 0;
    }
    cout << '\n';

    for (auto [x, y] : a)
    {
        cout << (max1 - y) << '\n';
    }
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
