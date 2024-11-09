// 2024/11/09 15:59:42
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
    int n;
    cin >> n;

    map<int, int> mp;
    int pre;
    cout << "? 1" << endl;
    cin >> pre;
    mp[1] = pre;
    cout << "? " << n << endl;
    cin >> pre;
    mp[n] = pre;

    int ave = std::midpoint(mp[1], mp[n]);

    int l = 2, r = n - 1;
    int ans = -1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        cout << "? " << mid << endl;
        int x;
        cin >> x;
        mp[mid] = x;
        if (ans == -1 || abs(x - ave) < abs(mp[ans] - ave))
        {
            ans = mid;
        }

        if (x > ave)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }


    cout << "! 1 " << ans << ' ' << n << endl;
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
