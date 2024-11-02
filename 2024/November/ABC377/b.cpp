// 2024/11/02 21:27:15
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
    array<string, 8> a;
    for (int i = 0; i < 8; i++)
    {
        cin >> a[i];
    }

    auto check = [&](int x, int y)
    {
        for (int i = 0; i < 8; i++)
        {
            if (a[i][y] == '#')
            {
                return false;
            }
        }
        for (int j = 0; j < 8; j++)
        {
            if (a[x][j] == '#')
            {
                return false;
            }
        }

        return true;
    };

    int ans = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            ans += check(i, j);
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
