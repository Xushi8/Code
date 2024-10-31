// 2024/10/30 17:31:06
#pragma GCC optimize("O3")

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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    vector<bitset<2048>> bit(n);
    vector<bitset<2048>> bs(1000); // 最大为 999
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            bs[a[i][j]][i] = true;
        }

        for (int i = 0; i < n; i++)
        {
            bit[i] ^= bs[a[i][j]];
        }

        for (int i = 0; i < n; i++)
        {
            bs[a[i][j]][i] = false;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += bit[i].count();
    }
    if (m % 2 == 1)
    {
        ans -= n;
    }
    ans /= 2;
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
