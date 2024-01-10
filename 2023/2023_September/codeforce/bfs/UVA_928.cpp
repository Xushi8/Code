// 2023/09/29 22:56:49
#pragma GCC optimize(2)
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
    vector<string> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    map<pii, set<int>> mp;
    queue<array<int, 4>> que;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == 'S')
            {
                que.push({ i, j, 3, 0 });
                mp[{i, j}].emplace(3);
            }
        }
    }

    while (!que.empty())
    {
        auto [x, y, tmp, dis] = que.front(); que.pop();
        int k = (tmp == 3 ? 1 : tmp + 1);
        for (int i = 0; i < 4; i++)
        {
            int tx = x + k * dx[i];
            int ty = y + k * dy[i];
            for (int j = 1; j <= k; j++)
            {
                int tmpx = x + j * dx[i];
                int tmpy = y + j * dy[i];
                if (!(0 <= tmpx && tmpx < n && 0 <= tmpy && tmpy < m) || s[tmpx][tmpy] == '#')
                    goto next;
            }

            if (mp[{tx, ty}].count(k) == 0)
            {
                mp[{tx, ty}].emplace(k);
                que.push({tx, ty, k, dis + 1});
                if (s[tx][ty] == 'E')
                {
                    cout << dis + 1 << '\n';
                    return;
                }
            }

        next:
            ;
        }
    }

    cout << "NO\n";
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