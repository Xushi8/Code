// 2023/11/05 14:36:42
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 1000005;

vector<int> G[N];
int dis[2][N];
bool inqueue[N];
vector<int> no_sure;

void bfs(int k, int s)
{
    queue<int> que;
    que.emplace(s);
    dis[k][s] = 0;
    while (!que.empty())
    {
        int u = que.front();
        que.pop();
        for (int v : G[u])
        {
            if (dis[k][v] > dis[k][u] + 1)
            {
                que.emplace(v);
                dis[k][v] = dis[k][u] + 1;
            }
        }
    }

    for (int v : no_sure)
    {
        dis[k][0] = min(dis[k][0], dis[k][v]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        if (u == 0)
        {
            no_sure.push_back(v);
        }
        else
        {
            G[u].push_back(v);
            G[v].push_back(u);
        }
    }

    memset(dis, 0x3f, sizeof(dis));

    bfs(0, 1);
    bfs(1, n);

    for (int i = 1; i <= n; i++)
    {
        int ans = min({dis[0][n], dis[0][0] + 1 + dis[1][i], dis[0][i] + 1 + dis[1][0], dis[0][0] + dis[1][0] + 2});
        if (ans == 0x3f3f3f3f)
            ans = -1;
        cout << ans << ' ';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}