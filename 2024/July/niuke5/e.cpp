// 2024/07/30 12:14:36
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
    int n;
    cin >> n;
    vector<array<int, 2>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i][0];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> a[i][1];
    }

    int ans = 0;
    int sum = 0;
    for (auto [l, r] : a)
    {
        if (l == r)
        {
            sum++;
        }
        if (l > r)
        {
            ans++;
        }
    }
    ans += (sum + 1) / 2;
    cout << ans << '\n';
}