// 2024/07/29 19:59:26
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

void solve()
{
    int n, r;
    cin >> n >> r;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int ans = 0;
    int last = -1;
    while (last < n - 1)
    {
        int pos = -1;
        for (int i = n - 1; i > max(last - r + 1, -1); i--)
        {
            if (a[i] == 1 && i - r <= last)
            {
                pos = i;
                break;
            }
        }
        if (pos == -1)
        {
            cout << -1 << '\n';
            return;
        }
        ans++;
        last = pos + r - 1;
    }
    cout << ans << '\n';
}
