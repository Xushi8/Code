// 2024/09/28 13:47:11
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
    int n, k;
    cin >> n >> k;
    string a[3];
    cin >> a[1] >> a[2];
    a[1].insert(a[1].begin(), '0');
    a[2].insert(a[2].begin(), '0');

    auto get = [&](int x, int y)
    {
        int res = 0;
        for (int i = 1; i <= 2; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (a[i][j] == '1')
                {
                    if (i == x)
                    {
                        res = max(res, abs(y - j));
                    }
                    else
                    {
                        res = max(res, y + j + k);
                    }
                }
            }
        }
        return res;
    };

    int minn = 1e9;
    int x, y;
    for (int i = 1; i <= 2; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            auto res = get(i, j);
            if (res < minn)
            {
                minn = res;
                x = i;
                y = j;
            }
        }
    }
    if (x == 1)
        x = 2;
    else
        x = 1;
    cout << minn << '\n';
    cout << x << ' ' << y << "\n";
}