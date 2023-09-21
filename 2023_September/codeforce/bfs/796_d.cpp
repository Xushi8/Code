// 2023/09/21 19:28:05
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

vector<pii> G[N];
int dis[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k, d;
    cin >> n >> k >> d;
    vector<int> p(k);
    for (int i = 0; i < k; i++)
    {
        cin >> p[i];
        p[i]--;
    }

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].emplace_back(v, i + 1);
        G[v].emplace_back(u, i + 1);
    }

    memset(dis, -1, sizeof(dis));
    queue<int> que;
    for (int x : p)
    {
        que.emplace(x);
        dis[x] = x;
    }

    while (!que.empty())
    {
        int u = que.front(); que.pop();
        for (auto [v, index] : G[u])
        {
            if (dis[v] != -1)
                continue;

            dis[v] = dis[u];
            que.emplace(v);
        }
    }

    set<int> st;
    for (int u = 0; u < n; u++)
    {
        for (auto [v, index] : G[u])
        {
            if (dis[u] != dis[v])
            {
                st.emplace(index);
            }
        }
    }

    cout << st.size() << endl;
    for (int x : st)
    {
        cout << x << ' ';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}