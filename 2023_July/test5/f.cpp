// 2023/07/31 19:34:32
#ifndef LOCAL
#pragma GCC optimize(2)
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
const int N = 505;

int arr[N], dp[N][N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, b, mod;
    cin >> n >> m >> b >> mod;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    dp[0][0] = 1;
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= m; i++)
        {
            for (int j = arr[k]; j <= b; j++)
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - arr[k]]) % mod;
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i <= b; i++)
    {
        ans = (ans + dp[m][i]) % mod;
    }

    cout << ans << '\n';

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}