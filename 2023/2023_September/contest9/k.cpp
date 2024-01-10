// 2023/10/02 11:39:18
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
int ans;
int n, m, k;
int arr[6][6];

void dfs(int now)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            
        }
    }
}

void solve()
{
    memset(arr, 0, sizeof(arr));
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;
        arr[a][b] = 1;
    }

    ans = k;
    dfs(ans);
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