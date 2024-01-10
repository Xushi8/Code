// 2023/08/19 21:12:45
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
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
constexpr int INF = 0x3f3f3f3f;
constexpr int MOD = (int)(1e9 + 7);
constexpr int N = 1000005;

bool vis[N];

void dfs(int u, const vector<vector<int>>& arr)
{
    vis[u] = 1;
    for (int v : arr[u])
    {
        if (vis[v])
            continue;

        dfs(v, arr);
    }


    if (u != 0)
        cout << u + 1 << ' ';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<vector<int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            arr[i].emplace_back(x - 1);
        }
    }

    dfs(0, arr);
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}