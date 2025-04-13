// 2025/04/13 18:32:29
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
    auto get = [](string_view a)
    {
        string s;
        for (size_t i = 1; i < a.size(); i++)
        {
            if ((a[i] - '0') % 2 == (a[i - 1] - '0') % 2)
            {
                s += max(a[i], a[i - 1]);
            }
        }
        return s;
    };

    string x, y;
    cin >> x >> y;
    x = get(x);
    y = get(y);
    if (x == y)
    {
        cout << x << '\n';
    }
    else
    {
        cout << x << '\n' << y << '\n';
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
