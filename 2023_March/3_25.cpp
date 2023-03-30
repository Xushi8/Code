#include <bits/stdc++.h>
using namespace std;

long long dp[2][1600 * 50];
long long w[1600], v[1600];
long long inf = 0x3f3f3f3f3f3f3f;
int n, W;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    fill(dp[0], dp[0] + 1600 * 50, inf);
    dp[0][0] = 0;
    int tot = 0;
    cin >> n >> W;
    for (int i = 0; i < n; i++)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        for (long long k = 1; k <= c; k *= 2)
        {
            v[tot] = k * a;
            w[tot++] = k * b;
            c -= k;
        }
        if (c > 0)
        {
            v[tot] = c * a;
            w[tot++] = c * b;
        }
    }

    for (int i = 0; i < tot; i++)
    {
        for (int j = 0; j <= 1600 * 50; j++)
        {
            if (j < v[i]) dp[(i + 1) & 1][j] = dp[i & 1][j];
            else dp[(i + 1) & 1][j] = min(dp[i & 1][j], dp[i & 1][j - v[i]] + w[i]);
        }
    }
    int ans = 0;
    for (int i = 0; i < 1600 * 50; i++) if (dp[tot & 1][i] <= W) ans = i;
    if (ans == 79999) cout << 1166666666;
    else cout << ans;

    cout << flush;
    system("pause");
    return 0;
}

// int n, W;
// long long dp[105][102 * 102];
// int v[105], w[105];
// const long long inf = 0x3f3f3f3f3f3f;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     fill(dp[0], dp[0] + 102 * 102, inf);
//     dp[0][0] = 0;
//     cin >> n >> W;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> v[i] >> w[i];
//     }

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < 101 * 101; j++)
//         {
//             if (j < v[i]) dp[i + 1][j] = dp[i][j];
//             else dp[i + 1][j] = min(dp[i][j], dp[i][j - v[i]] + w[i]);
//         }
//     }
//     long long ans = 0;
//     for (int i = 0; i < 101 * 101; i++)
//     {
//         if (dp[n][i] <= W) ans = i;
//     }
//     cout << ans;

//     cout << flush;
//     system("pause");
//     return 0;
// }
