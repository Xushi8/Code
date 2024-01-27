// 2024/01/27 10:16:04
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
#include <numeric>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 5005;
ll dp[N][N];
constexpr ll MOD = int(1e9 + 7);

ll fast_pow(ll a, size_t n)
{
    ll b = 1;
    while (n)
    {
        if (n & 1)
            b = b * a % MOD;
        a = a * a % MOD;
        n /= 2;
    }
    return b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    dp[0][0] = 1;
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i][j] = (dp[i - 1][j] * j + dp[i - 1][j - 1] * (n - j + 1)) % MOD;
        }
    }

    ll ans = 0;
    for (int i = 1; i <= min(n, k); i++)
    {
        ans += dp[k][i] * fast_pow(2, n - i) % MOD;
        ans %= MOD;
    }
    cout << ans << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}