// 2024/01/15 10:34:12
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
#include <bitset>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 1000005;

void solve()
{
    int r, c;
    cin >> r >> c;
    cin.ignore(1024, '\n');
    vector<string> s(4 * r + 3);
    for (int i = 0; i < 4 * r + 3; i++)
    {
        getline(cin, s[i]);
    }

    map<pii, int> mp;
    int be, ed;
    for (int i = 2; i <= 4 * r - 2; i += 4)
    {
        for (int j = 4; j <= 6 * c - 2; j += 12)
        {
            mp.emplace(make_pair(i, j), mp.size());
            if (s[i][j] == 'S')
                be = mp[{i, j}];
            if (s[i][j] == 'T')
                ed = mp[{i, j}];
        }
    }

    for (int i = 4; i <= 4 * r; i += 4)
    {
        for (int j = 10; j <= 6 * c - 2; j += 12)
        {
            mp.emplace(make_pair(i, j), mp.size());
            if (s[i][j] == 'S')
                be = mp[{i, j}];
            if (s[i][j] == 'T')
                ed = mp[{i, j}];
        }
    }

    vector<vector<int>> G(r * c);

    for (int i = 2; i <= 4 * r - 2; i += 4)
    {
        for (int j = 4; j <= 6 * c - 2; j += 12)
        {
            int index = mp[{i, j}];
            if (s[i - 1][j + 3] == ' ')
            {
                int index1 = mp[{i - 2, j + 6}];
                G[index].emplace_back(index1);
                G[index1].emplace_back(index);
            }
            if (s[i + 1][j + 3] == ' ')
            {
                int index1 = mp[{i + 2, j + 6}];
                G[index].emplace_back(index1);
                G[index1].emplace_back(index);
            }
            if (s[i + 2][j] == ' ')
            {
                int index1 = mp[{i + 4, j}];
                G[index].emplace_back(index1);
                G[index1].emplace_back(index);
            }
        }
    }

    for (int i = 4; i <= 4 * r; i += 4)
    {
        for (int j = 10; j <= 6 * c - 2; j += 12)
        {
            int index = mp[{i, j}];
            if (s[i - 1][j + 3] == ' ')
            {
                int index1 = mp[{i - 2, j + 6}];
                G[index].emplace_back(index1);
                G[index1].emplace_back(index);
            }
            if (s[i + 1][j + 3] == ' ')
            {
                int index1 = mp[{i + 2, j + 6}];
                G[index].emplace_back(index1);
                G[index1].emplace_back(index);
            }
            if (s[i + 2][j] == ' ')
            {
                int index1 = mp[{i + 4, j}];
                G[index].emplace_back(index1);
                G[index1].emplace_back(index);
            }
        }
    }

    constexpr int INF = 0x3f3f3f3f;
    vector<int> dis(r * c, INF);

    queue<int> que;
    que.emplace(be);
    dis[be] = 1;
    while (!que.empty())
    {
        int u = que.front();
        que.pop();
        for (int v : G[u])
        {
            if (dis[v] > dis[u] + 1)
            {
                dis[v] = dis[u] + 1;
                que.emplace(v);
            }
        }
    }

    int ans = dis[ed];
    if (ans == INF)
        ans = -1;
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
    return 0;
}