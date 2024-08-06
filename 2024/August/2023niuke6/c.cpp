// 2024/08/05 15:16:30
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

using i128 = __int128_t;

void print_uint128(ostream& os, const __int128_t& num)
{
    if (num >= 10)
    {
        print_uint128(os, num / 10);
    }
    os.put((char)(num % 10) + '0');
}

ostream& operator<<(ostream& os, const __int128_t& num)
{
    print_uint128(os, num);
    return os;
}

void solve()
{
    // auto func = [](i64 val)
    // {
    //     __int128_t res = 1;
    //     for (i64 i = val; i > 0; i -= 2)
    //     {
    //         res *= i;
    //     }
    //     return res;
    // };

    // for (int t = 1; t <= 14; t++)
    // {
    //     __int128_t now = 1;
    //     for (int i = 1; i <= t; i++)
    //     {
    //         now *= func(i);
    //     }
    //     cout << t << ' ' << now << '\n';
    // }

    // i64 n;
    // cin >> n;
    i64 now = 55;
    for (i64 i = 1; i <= 10000; i++)
    {
        cout << now * i << '\n';
    }
}