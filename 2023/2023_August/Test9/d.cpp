// 2023/08/16 10:58:36
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
const int N = 1000005;

vector<int> G[N];
int arr[N], in[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;
    while (tt--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            arr[i] = 0;
            in[i] = 0;
            G[i].clear();
        }

        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            u--; v--;
            G[u].emplace_back(v);
            G[v].emplace_back(u);
            in[v]++; in[u]++;
        }

        queue<int> que;

        for (int i = 0; i < n; i++)
        {
            if (G[i].size() == 1)
            {
                arr[i] = 1;
                que.emplace(i);
            }
        }

        while (!que.empty())
        {
            int u = que.front(); que.pop();
            for (int v : G[u])
            {
                in[v]--;
                if (in[v] == 1)
                {
                    arr[v] = arr[u] + 1;
                    que.emplace(v);
                }
            }
        }


        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            // cerr << arr[i] << ' ';
            ans += (arr[i] > m);
        }

        cout << ans << '\n';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}