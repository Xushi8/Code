// 2023/09/29 17:47:24
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdint>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <functional>
#include <iomanip>
#include <cmath>
#include <stack>
#include <array>
#include <fstream>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 1000005;
constexpr int MOD = 20437;
constexpr int INF = 0x3f3f3f3f;

int Case;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
int n;

void solve()
{
    cout << "Case " << ++Case;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    char max_food = 'A';
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (isalpha(s[i][j]))
            {
                max_food = max(max_food, s[i][j]);
            }
        }
    }
    if (max_food == 'A')
    {
        cout << ": 0 1\n";
        return;
    }

    auto bfs = [&](int nx, int ny) -> pii
        {
            vector<vector<int>> dis(n, vector<int>(n, INF));
            queue<pii> que;
            que.emplace(nx, ny);
            dis[nx][ny] = 0;
            int now = 0, shortest = -1;
            char end_food = s[nx][ny] + 1;
            while (!que.empty())
            {
                auto [x, y] = que.front(); que.pop();
                if (end_food == s[x][y])
                {
                    now++;
                    shortest = dis[x][y];
                }
                for (int i = 0; i < 4; i++)
                {
                    int tx = x + dx[i];
                    int ty = y + dy[i];
                    if (0 <= tx && tx < n && 0 <= ty && ty < n && s[tx][ty] != '#' && dis[tx][ty] > dis[x][y] && (s[tx][ty] == '.' || s[tx][ty] <= end_food))
                    {
                        dis[tx][ty] = dis[x][y] + 1;
                        que.emplace(tx, ty);
                    }
                }
            }
            return { shortest, now };
        };

    int shortest = 0;
    ll now = 1;
    bool flag = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (isalpha(s[i][j]) && s[i][j] < max_food)
            {
                pii p = bfs(i, j);
                if (p.first < 0)
                    flag = 0;
                shortest += p.first;
                now *= p.second;
                now %= MOD;
            }
        }
    }
    if (!flag)
        cout << ": Impossible\n";
    else
        cout << ": " << shortest << ' ' << now << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n && n)
    {
        solve();
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}