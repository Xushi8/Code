// 2023/07/05 20:27:06
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
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = (int)(1e9 + 7);
const int N = 300005;

ll dp[N][2];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];


    dp[0][0] = INF;
    dp[0][1] = arr[0];
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = dp[i - 1][1];
        dp[i][1] = min(dp[i - 1][1], dp[i - 1][0]) + arr[i];
        // cout << i << ' ' << dp[i][0] << ' ' << dp[i][1] << ' ' << arr[i] << '\n';
    }

    ll ans = min(dp[n - 1][0], dp[n - 1][1]);

    dp[0][0] = 0;
    dp[0][1] = INF;
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = dp[i - 1][1];
        dp[i][1] = min(dp[i - 1][1], dp[i - 1][0]) + arr[i]; 
        // cout << i << ' ' << dp[i][0] << ' ' << dp[i][1] << ' ' << arr[i] << '\n';
    }

    ans = min(ans, dp[n - 1][1]);
    cout << ans << '\n';

    cout << endl;

    
    return 0;
}