// 2025/04/13 18:39:59
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
    int n, k, s;
    cin >> n >> k >> s;
    vector<pii> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());


    int ans = 0;
    array<int, 300> cnt{};
    for (auto [x, y] : a)
    {
        if (x < 175)
        {
            continue;
        }

        if (y >= s)
        {
            ans++;
        }
        else
        {
            if (cnt[x] < k)
            {
                cnt[x]++;
                ans++;
            }
        }
    }

    cout << ans << '\n';
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
