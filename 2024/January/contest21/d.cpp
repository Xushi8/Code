#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10, maxp = 6 * maxn;
char mp[4 * maxn][maxp];
vector<int> G[maxn * maxn];
int vis[maxn * maxn];
int bfs(int s, int t)
{
    queue<pair<int, int>> q;
    q.push({s, 1});
    vis[s] = 1;
    int cnt = 0;
    while (!q.empty())
    {
        int sz = q.size();
        for (int i = 0; i < sz; i++)
        {
            pair<int, int> u = q.front();
            q.pop();
            if (u.first == t) return u.second;
            for (auto v : G[u.first])
            {
                if (!vis[v])
                {
                    vis[v] = 1;
                    q.push({v, u.second + 1});
                }
            }
        }
    }
    return -1;
}
void slove()
{
    int n, m;
    cin >> m >> n;
    int sz = n * m;
    for (int i = 1; i <= sz; i++) G[i].clear();
    memset(vis, 0, sizeof vis);
    getchar();
    for (int i = 1; i <= 4 * m + 3; i++)
    {
        cin.getline(mp[i] + 1, 6 * n + 5, '\n');
    }
    int s, t;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int x = (j & 1) ? (4 * i - 1) : (4 * i + 1);
            int y = 6 * j - 1;
            int id = (i - 1) * n + j;
            int nid = 0;
            if (mp[x][y] == 'S') s = id;
            if (mp[x][y] == 'T') t = id;
            if (mp[x + 2][y] == ' ')
            {
                nid = id + n;
                G[id].push_back(nid);
                G[nid].push_back(id);
            }
            if (mp[x + 1][y + 3] == ' ')
            {
                nid = id + 1 + (j & 1 ? 0 : n);
                G[id].push_back(nid);
                G[nid].push_back(id);
            }
            if (mp[x - 1][y + 3] == ' ')
            {
                nid = id + 1 + (j & 1 ? -n : 0);
                G[id].push_back(nid);
                G[nid].push_back(id);
            }
        }
    }
    cout << bfs(s, t) << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) slove();
    return 0;
}
