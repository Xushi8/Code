// 2024/11/05 21:53:57
#ifdef LOCAL
#include <basic_std_lib.h>
#else
#include <bits/stdc++.h>
#endif
using namespace std;

enum class dirs
{
    shu,
    heng,
};

enum class lens
{
    len4,
    len6,
};

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));

    auto print = [&](bool ok)
    {
        if (!ok)
        {
            cout << "NO\n";
            return;
        }

        cout << "YES\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << a[i][j] << ' ';
            }
            cout << '\n';
        }
    };

    auto cover = [&](int x, int y, int& k, dirs dir, lens len)
    {
        if (dir == dirs::shu)
        {
            if (len == lens::len4)
            {
                for (int i = 0; i < 4; i++)
                {
                    a[x + i][y] = k;
                }
                k++;
            }
            else
            {
                for (int i = 0; i < 3; i++)
                {
                    a[x + i][y] = k;
                }
                a[x][y + 1] = k;

                for (int i = 3; i < 6; i++)
                {
                    a[x + i][y] = k + 1;
                }
                a[x + 5][y + 1] = k + 1;

                for (int i = 1; i < 5; i++)
                {
                    a[x + i][y + 1] = k + 2;
                }

                k += 3;
            }
        }
        else
        {
            if (len == lens::len4)
            {
                for (int j = 0; j < 4; j++)
                {
                    a[x][y + j] = k;
                }
                k++;
            }
            else
            {
                for (int j = 0; j < 3; j++)
                {
                    a[x][y + j] = k;
                }
                a[x + 1][y] = k;

                for (int j = 3; j < 6; j++)
                {
                    a[x][y + j] = k + 1;
                }
                a[x + 1][y + 5] = k + 1;

                for (int j = 1; j < 5; j++)
                {
                    a[x + 1][y + j] = k + 2;
                }

                k += 3;
            }
        }
    };

    int k = 1;

    if (n * m % 4 != 0)
    {
        print(false);
        return;
    }

    if (n % 4 == 0)
    {
        for (int j = 0; j < m; j++)
        {
            for (int i = 0; i < n; i += 4)
            {
                cover(i, j, k, dirs::shu, lens::len4);
            }
        }

        print(true);
        return;
    }

    if (m % 4 == 0)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j += 4)
            {
                cover(i, j, k, dirs::heng, lens::len4);
            }
        }
        print(true);
        return;
    }

    for (int len = 0; len <= 8; len += 4)
    {
        if ((n - len) % 6 == 0 && n - len > 0)
        {
            for (int j = 0; j < m; j++)
            {
                for (int i = 0; i < len; i += 4)
                {
                    cover(i, j, k, dirs::shu, lens::len4);
                }
            }

            for (int j = 0; j < m; j += 2)
            {
                for (int i = len; i < n; i += 6)
                {
                    cover(i, j, k, dirs::shu, lens::len6);
                }
            }

            print(true);
            return;
        }

        if ((m - len) % 6 == 0 && m - len > 0)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < len; j += 4)
                {
                    cover(i, j, k, dirs::heng, lens::len4);
                }
            }

            for (int i = 0; i < n; i += 2)
            {
                for (int j = len; j < m; j += 6)
                {
                    cover(i, j, k, dirs::heng, lens::len6);
                }
            }

            print(true);
            return;
        }
    }

    print(false);
}

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
