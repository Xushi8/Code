// 2023/07/15 21:34:04

// 2023/08/06 22:01:57
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

ll dp[N][2];
uint8_t s[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n >> (s + 1);
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '0')
        {
            dp[i][0] = 1;
            dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
        }
        else
        {
            dp[i][0] = dp[i - 1][1];
            dp[i][1] = dp[i - 1][0] + 1;
        }
    }

    ull ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += dp[i][1];
    }

    cout << ans << '\n';

    cout << flush;
    return 0;
}