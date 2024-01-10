// 2023/11/08 15:00:54
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
constexpr int N = 505;

int cmax, n, sp, m;
int bike[N];

vector<pii> G[N];
int dis[N];
vector<int> path;

int ans_dis = 0x3f3f3f3f, ans_send, ans_take_back;
vector<int> ans_path;

void dfs(int cur, int cur_dis, int cur_send, int cur_take_back)
{
    if (cur_dis > dis[cur])
    {
        return;
    }
    if (cur_dis < dis[cur])
    {
        dis[cur] = cur_dis;
    }

    path.emplace_back(cur);

    if (cur == sp)
    {
        if (cur_dis < ans_dis || (cur_dis == ans_dis && cur_send < ans_send) || (cur_dis == ans_dis && cur_send == ans_send && cur_take_back < ans_take_back))
        {
            ans_path = path;
            ans_dis = cur_dis;
            ans_send = cur_send;
            ans_take_back = cur_take_back;
        }
    }
    else
    {
        for (auto [v, w] : G[cur])
        {
            if (cur_take_back + bike[v] < cmax / 2)
            {
                dfs(v, cur_dis + w, cur_send + cmax / 2 - (cur_take_back + bike[v]), 0);
            }
            else
            {
                dfs(v, cur_dis + w, cur_send, cur_take_back + bike[v] - cmax / 2);
            }
        }
    }

    path.pop_back();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> cmax >> n >> sp >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> bike[i];
    }

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }

    memset(dis, 0x3f, sizeof(dis));
    dfs(0, 0, 0, 0);

    cout << ans_send << ' ';
    cout << ans_path[0];
    for (int i = 1; i < ans_path.size(); i++) {
        cout << "->" << ans_path[i];
    }
    cout << ' ' << ans_take_back;

#ifdef LOCAL
            cerr
        << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}