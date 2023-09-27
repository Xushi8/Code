// 2023/09/26 12:52:05
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
constexpr int INF = 0x3f3f3f3f;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dis1(n + 2, vector<int>(m + 2, INF)), dis2(n + 2, vector<int>(m + 2, INF)), dis3(n + 2, vector<int>(m + 2, INF));
    vector<vector<char>> s(n + 2, vector<char>(m + 2, '.'));
    int bx1, by1, bx2, by2, bx3, by3;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> s[i][j];
            if (s[i][j] == '1')
            {
                bx1 = i;
                by1 = j;
            }
            else if (s[i][j] == '2')
            {
                bx2 = i;
                by2 = j;
            }
            else if (s[i][j] == '3')
            {
                bx3 = i;
                by3 = j;
            }
        }
    }
    
    auto func = [&](int nx, int ny, vector<vector<int>>& dis) -> void
        {
            queue<pii> que;
            que.emplace(nx, ny);
            dis[nx][ny] = 0;
            while (!que.empty())
            {
                int x = que.front().first;
                int y = que.front().second;
                que.pop();
                for (int i = 0; i < 4; i++)
                {
                    int tx = x + dx[i];
                    int ty = y + dy[i];
                    if (0 <= tx && tx < n + 2 && 0 <= ty && ty < m + 2 && dis[tx][ty] == INF && s[tx][ty] != '#')
                    {
                        dis[tx][ty] = dis[x][y] + 1;
                        que.emplace(tx, ty);
                    }
                }
            }
        };

    func(bx1, by1, dis1);
    func(bx2, by2, dis2);
    func(bx3, by3, dis3);


    int ans = INF;
    for (int i = 0; i < n + 2; i++)
    {
        for (int j = 0; j < m + 2; j++)
        {
            if (dis1[i][j] != -1 && dis2[i][j] != -1 && dis3[i][j] != -1)
            {
                ans = min(ans, max({ dis1[i][j], dis2[i][j], dis3[i][j] }));
            }
        }
    }

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tt;
    cin >> tt;
    while (tt--)
    {
        solve();
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}