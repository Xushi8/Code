// 2023/08/31 19:40:15
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
#define int long long
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int MOD = (int)(1e9 + 7);
constexpr int N = 100005;

int dp[N];
pii arr[N];

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        sum += c;
        int d = (b - a) / 2 + 1;
        if (d < 0)
            d = 0;

        arr[i].first = d;
        arr[i].second = c;
    }
    
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = sum; j >= arr[i].second; j--)
        {
            dp[j] = min(dp[j], dp[j - arr[i].second] + arr[i].first);
        }
    }

    int ans = INF;
    for (int i = sum / 2 + 1; i <= sum; i++)
    {
        ans = min(ans, dp[i]);
    }

    // for (int i = 0; i < 35; i++)
    // {
    //     cerr << dp[i] << '\n';
    // }

    cout << ans << '\n';

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}