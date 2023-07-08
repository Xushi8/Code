// 2023/07/07 11:59:10
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
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = (int)(998244353);
const int N = 5005;

ll f[N][N], g[N][N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, K;
    cin >> n >> m >> K;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i == 1)
            {
                f[i][j] = 1;
            }
            else
            {
                if (K == 0)
                {
                    f[i][j] = g[i - 1][m];
                }
                else
                {
                    if (j - K >= 1)
                        f[i][j] += g[i - 1][j - K] - g[i - 1][0];
                    if (j + K <= m)
                        f[i][j] += g[i - 1][m] - g[i - 1][j + K - 1];
                }
            }
            g[i][j] = (g[i][j - 1] + f[i][j]) % MOD;
        }
    }

    if (g[n][m] < 0) g[n][m] += MOD;
    cout << g[n][m] << '\n';

    cout << endl;
    return 0;
}