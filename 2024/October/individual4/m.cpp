// 2024/10/23 14:29:21
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
    string s;
    cin >> s;
    for (auto ch : s)
    {
        int x = ch - '0';
        cout << ((x >> 2) & 1 ? 'r' : '-');
        cout << ((x >> 1) & 1 ? 'w' : '-');
        cout << ((x >> 0) & 1 ? 'x' : '-');
    }
    cout << '\n';
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
