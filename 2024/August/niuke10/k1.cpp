// 2024/08/15 13:37:06
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
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    auto check = [&](int val)
    {
        for (int i = 0; 0 <= i + val - 1 && i + val - 1 < n; i++)
        {
            int a = i, b = n - (i + val);
            int s = A[i], t = A[i + val - 1];
            if (s >= 0)
            {
                if (t <= b)
                    return true;
            }
            else if (t <= 0)
            {
                if (-s <= a)
                    return true;
            }
            else
            {
                if (-s <= a && (t + (-s)) <= b)
                    return true;
                if (t <= b && (t + (-s)) <= a)
                    return true;
            }
        }
        return false;
    };

    int l = 0, r = n;
    int ans = 0;
    while (l <= r)
    {
        int mid = (l + r) / 2;

        if (check(mid))
            l = mid + 1, ans = mid;
        else
            r = mid - 1;
    }
    cout << ans << '\n';
}