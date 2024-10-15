// 2024/10/15 21:44:00
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
    int s, x;
    cin >> s >> x;
    if (std::gcd(s, x) == 1)
    {
        cout << 1 << '\n';
        cout << s << '\n';
        return;
    }

    for (int i = 1; i < static_cast<int>(1e6); i++)
    {
        if (std::gcd(i, x) == 1 && std::gcd(s - i, x) == 1)
        {
            cout << 2 << '\n';
            cout << i << ' ' << s - i << '\n';
            return;
        }
    }

    for (int i = 1; i < static_cast<int>(1e6); i++)
    {
        if (std::gcd(i, x) == 1 && std::gcd(s - i - 1, x) == 1)
        {
            cout << 3 << '\n';
            cout << 1 << ' ' << i << ' ' << s - i - 1 << '\n';
            return;
        }
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
