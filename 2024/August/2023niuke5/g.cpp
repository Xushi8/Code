// 2024/08/02 12:08:44
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

template <typename T, size_t N>
array<T, N> operator-(array<T, N> const& l, array<T, N> const& r)
{
    array<T, N> res;
    for (size_t i = 0; i < N; i++)
    {
        res[i] = l[i] - r[i];
    }
    return res;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<array<int, 5>> cnt(n + 1);
    for (int i = 0; i < n; i++)
    {
        cnt[i + 1] = cnt[i];
        cnt[i + 1][a[i]]++;
    }

    auto check = [&](int be, int val) -> bool
    {
        auto t = cnt[val] - cnt[be - 1];
        return t[4] >= k && t[1] > 0 && t[2] > 0 && t[3] > 0;
    };

    int ans = n + 10;
    for (int i = 1; i <= n; i++)
    {
        int l = 1, r = n;
        int tmp = -1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (check(i, mid))
            {
                tmp = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        if (tmp != -1)
        {
            ans = min(ans, tmp - i + 1);
        }
    }
    cout << ans << '\n';
    
}