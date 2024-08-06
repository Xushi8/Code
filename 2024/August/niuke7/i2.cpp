// 2024/08/06 12:12:52
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
    int m, k, h;
    cin >> m >> k >> h;
    if (m <= k)
    {
        cout << min({m, k, h}) << '\n';
        return;
    }

    auto check = [&](int val) -> bool
    {
        i64 create_num = val;
        i64 all_num = val;
        while (all_num < h)
        {
            i64 add = (create_num / m) * k;
            if (add == 0)
            {
                return false;
            }

            create_num = create_num % m + add;
            all_num += add;
        }
        return true;
    };

    int l = 0, r = h, t = h;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
        {
            t = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << t << '\n';
}