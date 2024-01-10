// 2023/08/02 15:37:09
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
const int N =
#ifdef DEBUG
1000005;
#else
1000005;
#endif

int t[N], w[N];
int dp[1 << 17];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int W, n;
    cin >> W >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t[i] >> w[i];
    }

    for (int i = 1; i < (1 << n); i++)
    {
        int wei = 0;
        int maxn = 0;
        for (int j = 0; j < 17; j++)
        {
            if ((i >> j) & 1)
            {
                wei += w[j];
                maxn = max(maxn, t[j]);
            }
        }

        if (wei <= W)
            dp[i] = maxn;
    }
    int S = (1 << n) - 1;
    for (int i = 1; i <= S; i++)
    {
        for (int s1 = i; s1; s1 = (s1 - 1) & i)
        {
            int s2 = i ^ s1;
            if (dp[i] != 0)
                dp[i] = min(dp[i], dp[s2] + dp[s1]);
            else
                dp[i] = dp[s2] + dp[s1];
        }
    }

    cout << dp[S] << '\n';

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}