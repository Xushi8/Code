// 2023/07/31 15:59:22
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

    int n;
    cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    int dp[2][4] = { 0 };
    for (int i = 1; i <= n; i++)
    {
        dp[i & 1][0] = dp[(i - 1) & 1][0] + (arr[i] == 1);
        dp[i & 1][1] = max(dp[i & 1][0], dp[(i - 1) & 1][1] + (arr[i] == 2));
        dp[i & 1][2] = max(dp[i & 1][1], dp[(i - 1) & 1][2] + (arr[i] == 1));
        dp[i & 1][3] = max(dp[i & 1][2], dp[(i - 1) & 1][3] + (arr[i] == 2));
    }

    cout << dp[n & 1][3] << '\n';

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}