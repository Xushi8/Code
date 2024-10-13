// 2024/10/13 22:02:39
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
    int g = std::gcd(s, x);
    if (g == 1)
    {
        cout << 1 << '\n';
        cout << s << '\n';
        return;
    }

    if (g % 2 == 0)
    {
        cout << 2 << '\n';
        cout << s - 1 << ' ' << 1 << '\n';
        return;
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
