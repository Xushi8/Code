// 2024/07/30 14:18:02
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

constexpr int MOD = 998244353;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<int> old = a;
    while (1)
    {
        for (int l = 0; l < n;)
        {
            int r = l + 1;
            while (r < n && a[r] >= a[r - 1])
            {
                r++;
            }
            int sum = 0;
            for (int i = l; i < r; i++)
            {
                sum += a[i];
            }
            int tar = sum / (r - l);
            int cnt1 = sum - (r - l) * tar;
            int cnt0 = (r - l) - cnt1;
            for (int i = l, j = 0; j < cnt0; i++, j++)
            {
                a[i] = tar;
            }
            tar++;
            for (int i = l + cnt0, j = 0; j < cnt1; i++, j++)
            {
                a[i] = tar;
            }
            l = r;
        }

        if (old == a)
            break;
        old = a;
    }

    i64 ans = 1;
    for (int i = 0; i < n; i++)
    {
        ans *= a[i];
        // cout << a[i] << ' ';
        ans %= MOD;
    }

    cout << ans << '\n';
}