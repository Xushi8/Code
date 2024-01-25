// 2024/01/25 09:12:52
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
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 55;
constexpr int INF = 0x3f3f3f3f;
int arr[N][N], dp[N][N];
int n, k;
void dfs(int now)
{
    if (now == k)
    {
        return;
    }
    vector<pii> t1, t2;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            if (arr[i][j] == now)
            {
                t1.emplace_back(i, j);
            }
            else if (arr[i][j] == now - 1 && dp[i][j] != INF)
            {
                t2.emplace_back(i, j);
            }
        }
    }

    for (auto [x1, y1] : t1)
    {
        for (auto [x2, y2] : t2)
        {
            dp[x1][y1] = min(dp[x1][y1], dp[x2][y2] + abs(x1 - x2) + abs(y1 - y2));
        }
    }
    dfs(now + 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    memset(dp, 0x3f, sizeof(dp));
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            arr[i][j]--;
            if (arr[i][j] == 0)
            {
                dp[i][j] = 0;
            }
        }
    }

    dfs(1);

    int ans = INF;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == k - 1)
            {
                ans = min(ans, dp[i][j]);
            }

            // cerr << dp[i][j] << ' ';
        }
        // cerr << '\n';
    }

    cout << (ans == INF ? -1 : ans) << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}