// 2023/08/16 10:51:19
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

int fri[N], arr[N];

int find(int x)
{
    if (fri[x] == x)
        return x;
    else
        return fri[x] = find(fri[x]);
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (arr[x] > arr[y])
        fri[x] = y;
    else
        fri[y] = x;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        fri[i] = i;
    }

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--; v--;
        unite(u, v);
    }

    ull ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (fri[i] == i)
            ans += arr[i];
    }

    cout << ans << '\n';

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}