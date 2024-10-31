// 2024/10/30 16:32:47
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
constexpr int INF = 1e9;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    auto check = [&](int val)
    {
        int cnt = 0;
        auto b = a;
        for (int i = 0; i < n; i++)
        {
            if (val > b[i] * 2)
            {
                cnt++;
                b[i] = INF;
            }
        }

        if (cnt > k)
        {
            return false;
        }

        if (cnt == k)
        {
            int maxx = 0;
            for (int i = 0; i < n - 1; i++)
            {
                maxx = max(maxx, min(b[i], b[i + 1]));
            }
            return maxx >= val;
        }
        else if (cnt == k - 1)
        {
            int maxx = *max_element(b.begin(), b.end());
            return maxx >= val;
        }
        else
        {
            return true;
        }
    };

    int l = 0, r = INF, ans = 0;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (check(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
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
