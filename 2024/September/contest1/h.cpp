// 2024/09/28 17:23:10
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
    int n;
    cin >> n;
    vector<i64> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (n < 3)
    {
        cout << n << '\n';
        return;
    }
    sort(a.begin(), a.end());

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            i64 dec = a[j] - a[i];
            int siz = 2;
            if (ans >= siz + (n - j))
                break;
            i64 pre = a[j];
            
            while (1)
            {
                auto it = lower_bound(a.begin() + j, a.end(), pre + dec);
                if (it == a.end() || *it != pre + dec)
                    break;
                siz++;
                pre += dec;
            }

            ans = max(ans, siz);
        }
    }

    cout << ans << '\n';
}