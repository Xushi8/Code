// 2023/07/05 23:06:57
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
const int MOD = (int)(1e9 + 7);
const int N = 1000005;

int tx[] = { -1,-2,-2,-1,1,2,2,1 };
int ty[] = { -2,-1,1,2,2,1,-1,-2 };

int endx, endy, cx, cy;
bool check(pii p)
{
    if (p.second > endy)
        return false;
    if (p.first > endx)
        return false;
    if (p == make_pair(cx, cy))
        return false;
    for (int i = 0; i < 8; i++)
    {
        int dx = tx[i] + cx;
        int dy = ty[i] + cy;
        if (p == make_pair(dx, dy))
            return false;
    }

    return true;
}

ll dp[25][25];

bool used[25][25];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> endx >> endy >> cx >> cy;
    endx++; endy++; cx++; cy++;
    dp[2][1] = 1;
    dp[1][2] = 1;
    for (int i = 1; i <= endx; i++)
    {
        for (int j = 1; j <= endy; j++)
        {
            if (!check(make_pair(i, j)))
            {
                dp[i][j] = 0;
                continue;
            }

            if ((i == 1 && j == 1) || (i == 2 && j == 1) || (i == 1 && j == 2))
                continue;

            if (i == 1)
                dp[i][j] = dp[i][j - 1];
            else if (j == 1)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
        }
    }
    cout << dp[endx][endy] << '\n';
    // for (int i = 1; i <= endx; i++)
    // {
    //     for (int j = 1; j <= endy; j++)
    //         printf("%-12lld", dp[i][j]);
    //     printf("\n");
    // }

    cout << endl;
    return 0;
}