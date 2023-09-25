// 2023/09/25 22:45:13
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

int dx[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

int dis[8][8];

void solve()
{
    string a, b;
    cin >> a >> b;
    int bx = a[0] - 'a', by = a[1] - '1';
    int ex = b[0] - 'a', ey = b[1] - '1';
    memset(dis, -1, sizeof(dis));
    queue<pii> que;
    que.emplace(bx, by);
    dis[bx][by] = 0;
    while (!que.empty())
    {
        pii p = que.front(); que.pop();
        int x = p.first, y = p.second;
        for (int i = 0; i < 8; i++)
        {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if (0 <= tx && tx < 8 && 0 <= ty && ty < 8 && dis[tx][ty] == -1)
            {
                dis[tx][ty] = dis[x][y] + 1;
                que.emplace(tx, ty);
            }
        }
    }

    cout << dis[ex][ey] << '\n';
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
    cout << flush;
    return 0;
}