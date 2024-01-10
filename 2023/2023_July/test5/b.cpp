// 2023/07/31 13:35:00
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
const int N = 1000005;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> arr(n + 1);
    vector<ll> dp(n + 1);
    dp[0] = m;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        dp[i] = dp[i - 1] + arr[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++) // 1 ~ i
        {
            dp[i] = min(dp[i], dp[j] + dp[i - j] + m);
        }
    }

    cout << dp[n] << '\n';

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}