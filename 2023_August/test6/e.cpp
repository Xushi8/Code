// 2023/08/03 19:48:06
#ifndef LOCAL
// #pragma GCC optimize(2)
#endif
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
const int N = 2000005;

ll arr[N];
vector<int> G[N];
ll ans;
ll n, m;

ll dfs(int u)
{
    vector<ll> tmp;
    for (int v : G[u])
    {
        tmp.emplace_back(dfs(v));
    }

    sort(tmp.begin(), tmp.end());
    int len = (int)tmp.size();
    for (int i = 0; i < (int)tmp.size(); i++)
    {
        ll p = tmp[i];
        if (arr[u] + p + (len - 1) <= m)
        {
            ans++;
            len--;
            arr[u] += p;
        }
        else
        {
            arr[u] += len;
            break;
        }
    }

    return arr[u]; // arr[u] 为删除此节点所需要的权重
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        for (int j = 0; j < x; j++)
        {
            int y;
            cin >> y;
            G[i].emplace_back(y);
        }
    }

    dfs(0);
    cout << ans << '\n';

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}