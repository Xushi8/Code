// 2024/11/06 17:04:24
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
constexpr int N = 308, M = N;

int bit[N][M][N];

void add(int x, int y, int val, int co)
{
    for (int i = x; i < N; i += i & -i)
    {
        for (int j = y; j < M; j += j & -j)
        {
            bit[i][j][co] += val;
        }
    }
}

int query(int x, int y, int co)
{
    int res = 0;
    for (int i = x; i > 0; i -= i & -i)
    {
        for (int j = y; j > 0; j -= j & -j)
        {
            res += bit[i][j][co];
        }
    }

    return res;
}

int query(int x1, int y1, int x2, int y2, int co)
{
    return query(x2, y2, co) - query(x2, y1 - 1, co) - query(x1 - 1, y2, co) + query(x1 - 1, y1 - 1, co);
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            add(i, j, 1, a[i][j]);
        }
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //     {
    //         cerr << a[i][j] << ' ' ;
    //     }
    //     cerr << '\n';
    // }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //     {
    //         cerr << query(1, 1, i, j, 2) << ' ';
    //     }
    //     cerr << '\n';
    // }

    int q;
    cin >> q;
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x, y, co;
            cin >> x >> y >> co;
            add(x, y, -1, a[x][y]);
            a[x][y] = co;
            add(x, y, 1, a[x][y]);
        }
        else
        {
            int x1, x2, y1, y2, co;
            cin >> x1 >> x2 >> y1 >> y2 >> co;
            cout << query(x1, y1, x2, y2, co) << '\n';
        }
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
