// 2024/10/09 16:51:05
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
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    auto getx = [&](int val)
    {
        return val == 1 || val == n;
    };
    auto gety = [&](int val)
    {
        return val == 1 || val == m;
    };

    int c1 = getx(x1) + gety(y1);
    int c2 = getx(x2) + gety(y2);

    if (max(c1, c2) == 2)
    {
        cout << 2 << '\n';
    }
    else if (max(c1, c2) == 1)
    {
        cout << 3 << '\n';
    }
    else
    {
        cout << 4 << '\n';
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
