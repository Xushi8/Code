// 2023/09/25 22:28:34
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

ifstream ifs("input.txt");
ofstream ofs("output.txt");

#ifndef LOCAL
#define cin ifs
#define cout ofs
#endif

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    int k;
    cin >> k;
    queue<pii> que;
    vector<vector<int>> dis(n, vector<int>(m, -1));
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        x--; y--;
        que.emplace(x, y);
        dis[x][y] = 0;
    }

    int dx[] = { 0, 1, 0, -1 };
    int dy[] = { 1, 0, -1, 0 };
    int maxx = -1;
    int ansx = 0, ansy = 0;
    while (!que.empty())
    {
        auto [x, y] = que.front(); que.pop();
        for (int i = 0; i < 4; i++)
        {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if (0 <= tx && tx < n && 0 <= ty && ty < m && dis[tx][ty] == -1)
            {
                dis[tx][ty] = dis[x][y] + 1;
                que.emplace(tx, ty);
                if (maxx < dis[tx][ty])
                {
                    maxx = dis[tx][ty];
                    ansx = tx;
                    ansy = ty;
                }
            }
        }
    }

    cout << ansx + 1 << ' ' << ansy + 1 << '\n';


    ifs.close();
    ofs.close();

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}