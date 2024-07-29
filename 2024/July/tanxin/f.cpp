// 2024/07/29 20:27:22
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
    int n, m, D, L;
    cin >> n >> m >> D >> L;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());

    int ans = 0;
    int now;
    int pre = -1;
    for (int i = 0; L + D * i <= a.back(); i++)
    {
        now = lower_bound(a.begin(), a.end(), L + D * i) - a.begin();
        now = max(now, pre);
        for (int j = 0; j < m; j++)
        {
            if (now < n)
            {
                ans++;
                now++;
            }
            else
            {
                break;
            }
        }
        pre = now;
    }
    cout << ans << '\n';
}