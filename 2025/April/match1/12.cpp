#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int tar, n;
    cin >> tar >> n;

    vector<int> row(n), col(n);

    int ans = 0;
    auto dfs = [&](auto&& self, int x, int y)
    {
        if (x == n - 1 && y == n - 1)
        {
            for (int i = 0; i < n - 1; i++)
            {
                if (row[i] != tar)
                {
                    return;
                }
                if (col[i] != tar)
                {
                    return;
                }
            }

            if (row[n - 1] == col[n - 1] && row[n - 1] <= tar)
            {
                ans++;
            }
            return;
        }

        for (int i = 0; i <= 9; i++)
        {
            if (row[x] + i > tar || col[y] + i > tar)
            {
                break;
            }

            row[x] += i;
            col[y] += i;
            if (y != n - 1)
            {
                self(self, x, y + 1);
            }
            else
            {
                if (row[x] == tar)
                {
                    self(self, x + 1, 0);
                }
            }

            row[x] -= i;
            col[y] -= i;
        }
    };

    dfs(dfs, 0, 0);
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt = 1;
    // cin >> tt;
    while (tt--)
    {
        solve();
    }

    return 0;
}