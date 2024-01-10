// 2023/07/31 14:25:43
#ifndef LOCAL
#pragma GCC optimize(2)
#endif
#include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <cstdint>
// #include <vector>
// #include <string>
// #include <set>
// #include <map>
// #include <unordered_map>
// #include <unordered_set>
// #include <queue>
// #include <functional>
// #include <iomanip>
// #include <cmath>
// #include <stack>
using namespace std;

// using ll = long long;
// using ull = unsigned long long;
// using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const int N = 1000005;

int v[N], w[N];
int dp[2][N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, W;
    cin >> n >> W;
    for (int i = 0; i < n; i++)
    {
        cin >> w[i] >> v[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (j < w[i])
                dp[(i + 1) & 1][j] = dp[i & 1][j];
            else
                dp[(i + 1) & 1][j] = max(dp[i & 1][j], dp[i & 1][j - w[i]] + v[i]);
        }
    }

    cout << dp[n & 1][W] << '\n';

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}