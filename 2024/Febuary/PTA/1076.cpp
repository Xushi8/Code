// 2024/02/01 17:53:07
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
constexpr int N = 1005;
constexpr int INF = 0x3f3f3f3f;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<vector<int>> G(n);
    for (int i = 0; i < n; i++)
    {
        int cnt;
        cin >> cnt;
        while (cnt--)
        {
            int x;
            cin >> x;
            x--;
            G[x].emplace_back(i);
        }
    }
    vector<bool> vis(n, 0);

    int q;
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;
        x--;
        queue<pii> que;
        que.emplace(x, 0);
        set<int> st;
        while (!que.empty())
        {
            auto [u, deep] = que.front();
            que.pop();
            if (deep == k + 1)
                break;
            st.emplace(u);
            for (int v : G[u])
            {
                if (!vis[v])
                {
                    vis[v] = 1;
                    que.emplace(v, deep + 1);
                }
            }
        }

        cout << st.size() - 1 << '\n';
        fill(vis.begin(), vis.end(), 0);
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}