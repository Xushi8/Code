// 2024/08/13 12:09:14
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
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int bx = -1, by, ex, ey;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 'x' && bx == -1)
            {
                bx = i, by = j;
            }
            if (a[i][j] == 'x')
            {
                ex = i;
                ey = j;
            }
        }
    }

    int lenx = ex - bx + 1;
    int leny = ey - by + 1;
    int g = std::gcd(lenx, leny);
    lenx /= g;
    leny /= g;
    for (int i = 0; i < lenx; i++)
    {
        for (int j = 0; j < leny; j++)
        {
            cout << 'x';
        }
        cout << '\n';
    }
}