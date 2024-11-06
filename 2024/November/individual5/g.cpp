// 2024/11/06 16:50:16
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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<vector<int>> fmin(n + 1, vector<int>(__lg(n) + 1));

    for (int i = 1; i <= n; i++)
    {
        fmin[i][0] = a[i - 1];
    }
    for (int i = 1; i <= __lg(n); i++)
    {
        for (int j = 1; j + (1 << i) - 1 <= n; j++)
        {
            fmin[j][i] = min(fmin[j][i - 1], fmin[j + (1 << (i - 1))][i - 1]);
        }
    }

    auto query = [&](int l, int r)
    {
        int s = __lg(r - l + 1);
        int minn = min(fmin[l][s], fmin[r - (1 << s) + 1][s]);
        return minn;
    };

    for (int i = 1; i + m - 1 <= n; i++)
    {
        cout << query(i, i + m - 1) << '\n';
    }
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
