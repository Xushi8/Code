// 2023/11/26 15:09:36
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
constexpr int N = 100005;

bool vis[N];
int arr[N];
int len = 0;

void dfs(int u)
{
    if (vis[u])
    {
        return;
    }

    vis[u] = 1;
    len++;
    dfs(arr[u]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i] && arr[i] != i)
        {
            len = 0;
            dfs(i);
            if (i == 0)
            {
                ans += len - 1;
            }
            else
            {
                ans += len + 1;
            }
        }
    }

    cout << ans << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}