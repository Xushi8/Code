// 2023/09/26 20:47:55
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

int distance(int a, int b, int x, int y)
{
    return ((a - x) * (a - x) + (b - y) * (b - y));
}

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

void solve(int n, int m)
{
    vector<vector<int>> dis(n, vector<int>(m, -1));
    vector<vector<bool>> arr(n, vector<bool>(m, 0));
    int k;
    cin >> k;
    while (k--)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;
        arr[a][b] = 1;
    }
    cin >> k;
    vector<array<int, 3>> birang(k);
    for (int i = 0; i < k; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        birang[i] = { a, b, c };
    }

    auto check = [&](int x, int y) -> bool
        {
            for (int i = 0; i < k; i++)
            {
                if (distance(x, y, birang[i][0], birang[i][1]) <= birang[i][2] * birang[i][2])
                {
                    arr[x][y] = 1;
                    return false;
                }
            }
            return true;
        };

    queue<pii> que;
    que.emplace(0, 0);
    dis[0][0] = 0;
    while (!que.empty())
    {
        pii p = que.front(); que.pop();
        int x = p.first, y = p.second;
        for (int i = 0; i < 4; i++)
        {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if (0 <= tx && tx < n && 0 <= ty && ty < m && dis[tx][ty] == -1 && !arr[tx][ty] && check(tx, ty))
            {
                dis[tx][ty] = dis[x][y] + 1;
                que.emplace(tx, ty);
            }
        }
    }

    int ans = dis[n - 1][m - 1];
    if (ans == -1)
        cout << "Impossible.\n";
    else
        cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    while (cin >> n >> m && (n || m))
    {
        solve(n, m);
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}