// 2024/09/25 17:39:57
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
    int n, x;
    cin >> n >> x;
    i64 ans = 0;
    for (int a = 1; a <= x - 2; a++)
    {
        for (int b = 1; b <= min(x - a - 1, n / a); b++)
        {
            ans += min(x - a - b, (n - a * b) / (a + b));
        }
    }

    cout << ans << '\n';
}