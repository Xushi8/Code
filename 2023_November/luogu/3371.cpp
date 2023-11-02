// 2023/11/02 16:44:10
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

vector<pii> G[N];
int dis[N], cnt[N];
bool is_inqueue[N];
int n, m, s;

bool spfa(int s)
{
    memset(dis, 0x3f, sizeof(dis));
    memset(is_inqueue, 0, sizeof(is_inqueue));
    queue<int> que;
    que.push(s);
    cnt[s]++;
    is_inqueue[s] = 1;
    dis[s] = 0;
    while (!que.empty())
    {
        int u = que.front();
        que.pop();
        is_inqueue[u] = 0;
        if (cnt[u] > n)
            return false;
        for (auto [v, w] : G[u])
        {
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                if (!is_inqueue[v])
                {
                    is_inqueue[v] = 1;
                    que.push(v);
                    cnt[v]++;
                }
            }
        }
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> s;
    s--;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        G[u].push_back({v, w});
    }

    spfa(s);

    for (int i = 0; i < n; i++)
    {
        cout << (dis[i] == 0x3f3f3f3f ? INT32_MAX : dis[i]) << ' ';
    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}