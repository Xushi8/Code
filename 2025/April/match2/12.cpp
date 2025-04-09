#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> vis = a;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char ch;
            cin >> ch;
            a[i][j] = ch - '0';
        }
    }

    auto bfs = [&](int nx, int ny)
    {
        queue<pii> que;
        que.emplace(nx, ny);
        vis[nx][ny] = 1;
        bool has = false;
        while (!que.empty())
        {
            auto [x, y] = que.front();
            que.pop();
            constexpr int dx[] = {0, 0, -1, 1};
            constexpr int dy[] = {-1, 1, 0, 0};
            for (int k = 0; k < 4; k++)
            {
                int tx = x + dx[k];
                int ty = y + dy[k];
                if (!(0 <= tx && tx < n && 0 <= ty && ty < m))
                {
                    continue;
                }

                if (vis[tx][ty] || a[tx][ty] == 0)
                {
                    continue;
                }

                que.emplace(tx, ty);
                vis[tx][ty] = 1;
                if (a[tx][ty] > 1)
                {
                    has = true;
                }
            }
        }

        return has;
    };

    int c0{}, c1{};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && a[i][j] > 0)
            {
                c0++;
                bool has = bfs(i, j);
                if (has)
                {
                    c1++;
                }
            }
        }
    }

    cout << c0 << ' ' << c1 << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt = 1;
    while (tt--)
    {
        solve();
    }
}