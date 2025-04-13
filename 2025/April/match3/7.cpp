// 2025/04/13 18:35:22
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
    int n, m, q;
    cin >> n >> m >> q;
    set<int> x, y;
    int ans = n * m;
    while (q--)
    {
        int op, val;
        cin >> op >> val;
        if (op == 0)
        {
            if (!x.count(val))
            {
                x.emplace(val);
                ans -= m - y.size();
            }
        }
        else
        {
            if (!y.count(val))
            {
                y.emplace(val);
                ans -= n - x.size();
            }           
        }
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
