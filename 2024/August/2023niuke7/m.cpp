// 2024/08/09 12:01:49
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
    i64 n;
    cin >> n;
    i64 siz = to_string(n).size();
    i64 ans = 0;
    i64 num = 10;
    for (i64 i = 1; i < siz; i++)
    {
        ans += i * (num - num / 10);
        num *= 10;
    }
    num /= 10;
    ans += siz * (n - num + 1);
    cout << ans << '\n';
}