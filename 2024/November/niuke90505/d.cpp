// 2024/11/02 22:38:24
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
    unsigned char cipher[] = {
        198, 44, 113, 215, 43, 231, 181, 44, 147, 95, 61, 181, 79, 180, 95, 79, 180, 232, 181, 79, 46,
        95, 231, 147, 95, 164, 181, 146, 79, 65, 63, 82, 116, 77, 0};

    for (auto x : cipher)
    {
        cout << static_cast<int>(x / 17) << ' ';
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
