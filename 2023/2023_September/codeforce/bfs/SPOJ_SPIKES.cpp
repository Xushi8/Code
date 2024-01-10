// 2023/09/24 21:41:34
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

struct point
{
    int x, y, jump;

    point(int a, int b, int c)
    {
        x = a;
        y = b;
        jump = c;
    }
};

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

    int bx, by;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == '@')
            {
                bx = i;
                by = j;
            }
        }
    }

    queue<point> que;
    que.emplace(bx, by, 0);
    int dx[] = { 0, 1, 0, -1 };
    int dy[] = { 1, 0, -1, 0 };
    constexpr int INF = 0x3f3f3f3f;
    vector<vector<int>> cnt(n, vector<int>(m, INF));
    while (!que.empty())
    {
        point p = que.front(); que.pop();
        for (int i = 0; i < 4; i++)
        {
            int tx = dx[i] + p.x;
            int ty = dy[i] + p.y;
            if (0 <= tx && tx < n && 0 <= ty && ty < m && s[tx][ty] != '#' && cnt[tx][ty] > p.jump)
            {
                cnt[tx][ty] = p.jump;
                if (s[tx][ty] == 's')
                {
                    if (p.jump + 1 <= k)
                    {
                        que.emplace(tx, ty, p.jump + 1);
                    }
                }
                else if (s[tx][ty] == 'x')
                {
                    if (p.jump * 2 <= k)
                    {
                        cout << "SUCCESS" << endl;
                        return 0;
                    }
                }
                else
                {
                    que.emplace(tx, ty, p.jump);
                }
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}