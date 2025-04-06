#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    int tarx, tary;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 2)
            {
                tarx = i;
                tary = j;
            }
        }
    }

    constexpr int dx[] = {0, 0, -1, 1};
    constexpr int dy[] = {1, -1, 0, 0};
    constexpr int INF = 0x3f3f3f3f;
    vector<vector<int>> dis(n, vector<int>(m, INF));
    auto bfs = [&](int nx, int ny)
    {
        dis[nx][ny] = 0;
        queue<pii> que;
        que.emplace(nx, ny);

        while (!que.empty())
        {
            auto [x, y] = que.front();
            que.pop();
            for (int k = 0; k < 4; k++)
            {
                int tx = x + dx[k];
                int ty = y + dy[k];
                if (!(0 <= tx && tx < n && 0 <= ty && ty < m))
                {
                    continue;
                }
                if (a[tx][ty] == 0)
                {
                    continue;
                }

                if (dis[tx][ty] > dis[x][y] + 1)
                {
                    dis[tx][ty] = dis[x][y] + 1;
                    que.emplace(tx, ty);
                }
            }
        }
    };

    bfs(tarx, tary);

    int k;
    cin >> k;
    map<int, vector<int>> mp;
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        swap(x, y);
        int res = dis[x][y];
        mp[res].emplace_back(i);
    }

    for (auto const& [ans, vec] : mp)
    {
        if (ans == INF)
        {
            break;
        }

        if (vec.size() == 1)
        {
            cout << vec[0] + 1 << ' ' << ans << '\n';
            return;
        }
    }

    cout << "No winner.\n";
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