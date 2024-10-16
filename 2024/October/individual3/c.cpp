// 2024/10/16 13:23:56
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

bool jiao(array<int, 4> const& val)
{
    auto [x1, x2, x3, x4] = val;
    if (x2 <= x3 || x4 <= x1)
        return false;
    return true;
}

void solve()
{
    array<int, 4> a[3];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> a[j][i];
        }
    }

    bool ok = false;

    if (jiao(a[0]) && jiao(a[1]) && jiao(a[2]))
        ok = true;

    cout << (ok ? "Yes" : "No") << '\n';
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
