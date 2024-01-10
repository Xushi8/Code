// 2023/09/26 17:30:43
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

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

void solve(int n, int m)
{
    vector<string> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    vector<vector<int>> dis(n, vector<int>(m, -1));
    queue<pii> que;
    que.emplace(0, 0);
    dis[0][0] = 0;
    while (!que.empty())
    {
        pii p = que.front(); que.pop();
        int x = p.first, y = p.second;
        int k = s[x][y] - '0';
        for (int i = 0; i < 4; i++)
        {
            int tx = x + k * dx[i];
            int ty = y + k * dy[i];
            if (0 <= tx && tx < n && 0 <= ty && ty < m && dis[tx][ty] == -1)
            {
                dis[tx][ty] = dis[x][y] + 1;
                que.emplace(tx, ty);
            }
        }
    }

    cout << dis[n - 1][m - 1] << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    while (cin >> n >> m)
    {
        solve(n, m);
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}