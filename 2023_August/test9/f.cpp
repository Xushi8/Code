// 2023/08/15 17:41:01
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
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const int N = 105;

int in[N];
vector<int> G[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    while (cin >> n >> m && n)
    {
        memset(in, 0, sizeof(in));
        for (int i = 0; i < n; i++)
            G[i].clear();
        
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            in[y]++;
            G[x].emplace_back(y);
        }

        for (int i = 0; i < n; i++)
        {
            G[i].erase(unique(G[i].begin(), G[i].end()), G[i].end());
        }

        queue<int> que;
        set<int> st;
        for (int i = 0; i < n; i++)
        {
            if (in[i] == 0)
            {
                que.emplace(i);
            }
        }

        bool flag = 1;
        if (que.empty())
            flag = 0;
        
        while (!que.empty())
        {
            int u = que.front(); que.pop();
            if (st.count(u) != 0)
                continue;
            st.emplace(u);
            for (int v : G[u])
            {
                in[v]--;
                if (v == 0 && st.count(v) == 0)
                {
                    que.emplace(v);
                }

                if (in[v] < 0)
                {
                    flag = 0;
                    break;
                }
            }
        }

        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}