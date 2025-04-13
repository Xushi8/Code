// 2025/04/13 18:26:29
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
    array<int, 6> a;
    for (int i = 0; i < 6; i++)
    {
        cin >> a[i];
    }

    int n;
    cin >> n;

    for (int i = 0; i < 6; i++)
    {
        if (i != 0)
        {
            cout << ' ';
        }
        int t = 6 - n + 1;
        if (a[i] >= t)
        {
            t--;
        }
        cout << t;
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
