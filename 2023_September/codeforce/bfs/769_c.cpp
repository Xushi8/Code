// 2023/09/21 19:07:20
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
constexpr int N = 1005;

char arr[N][N];
int dis[N][N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    if (k & 1)
    {
        cout << "IMPOSSIBLE\n" << endl;
        return 0;
    }
    
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int bx, by;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 'X')
            {
                bx = i;
                by = j;
            }
        }
    }

    int dx[] = { 1, 0, 0, -1 };
    int dy[] = { 0, -1, 1, 0 };
    queue<pii> que;
    que.emplace(bx, by);
    memset(dis, -1, sizeof(dis));
    dis[bx][by] = 0;
    arr[bx][by] = '.';
    while (!que.empty())
    {
        auto [x, y] = que.front(); que.pop();
        for (int i = 0; i < 4; i++)
        {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if (0 <= tx && tx < n && 0 <= ty && ty < m && arr[tx][ty] == '.' && dis[tx][ty] == -1)
            {
                dis[tx][ty] = dis[x][y] + 1;
                que.emplace(tx, ty);
            }
        }
    }

    int x = bx;
    int y = by;
    vector<char> ans;
    for (int i = 0; i < k; i++)
    {
        if (x + 1 < n && dis[x + 1][y] <= k - i && arr[x + 1][y] == '.')
        {
            x++;
            ans.emplace_back('D');
        }
        else if (y - 1 >= 0 && dis[x][y - 1] <= k - i && arr[x][y - 1] == '.')
        {
            y--;
            ans.emplace_back('L');
        }
        else if (y + 1 >= 0 && dis[x][y + 1] <= k - i && arr[x][y + 1] == '.')
        {
            y++;
            ans.emplace_back('R');
        }
        else if (x - 1 >= 0 && dis[x - 1][y] <= k - i && arr[x - 1][y] == '.')
        {
            x--;
            ans.emplace_back('U');
        }
        else
        {
            cout << "IMPOSSIBLE\n" << endl;
            return 0;
        }
    }

    for (char ch : ans)
    {
        cout << ch;
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}