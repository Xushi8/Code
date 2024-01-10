// 2023/10/20 19:49:49
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

int in[N];
vector<int> G[N];

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        in[i] = 0;
        G[i].clear();
    }

    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            int y;
            cin >> y;
            y--;
            G[y].emplace_back(i);
            in[i]++;
        }
    }

    priority_queue<pii, vector<pii>, greater<>> que;
    for (int i = 0; i < n; i++)
    {
        if (in[i] == 0)
        {
            que.emplace(1, i);
        }
    }

    int ans = 0;
    int tot = 0;
    while (!que.empty())
    {
        auto [cnt, u] = que.top(); que.pop();
        tot++;
        ans = max(ans, cnt);
        for (int v : G[u])
        {
            if (--in[v] == 0)
            {
                if (v > u)
                    que.emplace(cnt, v);
                else
                    que.emplace(cnt + 1, v);
            }
        }
    }

    if (tot != n)
        cout << "-1\n";
    else
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
    cout << endl;
    return 0;
}