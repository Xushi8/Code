// 2023/09/23 22:42:24
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
constexpr int N = 10005;

struct point
{
    int x, y, step, par;
};
bool vis[N][N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    int bx, by, endx, endy;
    cin >> bx >> by >> endx >> endy;
    bx--; by--; endx--; endy--;

    auto bfs = [&]() -> int
        {
            queue<point> que;
            que.emplace(bx, by, 0, -2);
            vis[bx][by] = 1;
            int dx[] = { 0, 1, 0, -1 };
            int dy[] = { 1, 0, -1, 0 };
            while (!que.empty())
            {
                auto [x, y, step, par] = que.front(); que.pop();
                for (int i = 0; i < 4; i++)
                {
                    // if ((par == 0 && i == 2) ||
                    //     (par == 2 && i == 0) ||
                    //     (par == 1 && i == 3) ||
                    //     (par == 3 && i == 1))
                    //     continue;

                    for (int j = 1; j <= k; j++)
                    {
                        int tx = x + dx[i] * j;
                        int ty = y + dy[i] * j;
                        if (tx < 0 || tx >= n || ty < 0 || ty >= m || s[tx][ty] == '#')
                            break;
                        if (vis[tx][ty])
                            continue;
                        point tmp = { tx, ty, step + 1, i };
                        vis[tx][ty] = 1;
                        if (tx == endx && ty == endy)
                            return tmp.step;
                        que.emplace(tmp);
                    }
                }
            }

            return -1;
        };

    if (bx == endx && by == endy)
        ::cout << 0 << '\n';
    else
        ::cout << bfs() << '\n';

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}