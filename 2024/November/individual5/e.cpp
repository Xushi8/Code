// 2024/11/06 16:31:58
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
    int n, L, R;
    cin >> n >> L >> R;

    enum class op
    {
        less,
        big,
    };

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<i64> sum(n + 1);
    for (int i = 0; i < n; i++)
    {
        sum[i + 1] = sum[i] + a[i];
    }

    auto check = [&](int be, int val)
    {
        i64 s = sum[val] - sum[be - 1];
        if (s > R)
        {
            return 1;
        }
        else if (s < L)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    };

    auto get = [&](int be, op o)
    {
        int l = be, r = n;
        int ans = -1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            int ret = check(be, mid);
            if (ret > 0)
            {
                r = mid - 1;
            }
            else if (ret < 0)
            {
                l = mid + 1;
            }
            else
            {
                ans = mid;
                if (o == op::less)
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
        }

        return ans;
    };

    i64 ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int l = get(i, op::less);
        int r = get(i, op::big);
        if (l != -1)
        {
            ans += r - l + 1;
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
