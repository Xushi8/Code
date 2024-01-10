// 2023/08/15 20:45:28
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
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[b].emplace_back(a);
        in[a]++;
    }

    queue<int> que;
    for (int i = 0; i < n; i++)
    {
        if (in[i] == 0)
            que.emplace(i);
    }

    size_t ans = 0;
    while (!que.empty())
    {
        ans = max(ans, que.size() - 1);
        int u = que.front(); que.pop();
        for (int v : G[u])
        {
            in[v]--;
            if (in[v] == 0)
            {
                que.emplace(v);
            }
        }
    }

    cout << ans << '\n';

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}