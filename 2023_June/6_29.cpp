// 2023/06/29 22:28:03
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// int lena, lenb;
// char a[1005], b[1005];
// int dp[1005][1005];
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     cin >> a >> b;
//     lena = strlen(a);
//     lenb = strlen(b);
//     for (int i = 1; i <= lena; i++) dp[i][0] = i;
//     for (int j = 1; j <= lenb; j++) dp[0][j] = j;
//     for (int i = 1; i <= lena; i++)
//         for (int j = 1; j <= lenb; j++)
//             if (a[i - 1] == b[j - 1])
//                 dp[i][j] = dp[i - 1][j - 1];
//             else
//                 dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
//     cout << dp[lena][lenb] << '\n';
    
//     cout << flush;
//     return 0;
// }


int n;
ll w[50], v[50];
ll W;

pair<ll, ll> wv[1 << 21];

// 2023/06/29 22:39:19

int main()
{

    for (int i = 0; i < 1 << 21; i++)
    {
        wv[i].first = wv[i].second = 0x3f3f3f3f3f3f3f3f;
    }

    cin >> n >> W;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i] >> w[i];
    }


    int n2 = n / 2;
    for (int i = 0; i < 1 << n2; i++)
    {
        ll sw = 0, sv = 0;
        for (int j = 0; j < n2; j++)
        {
            if (i >> j & 1)
            {
                sw += w[j];
                sv += v[j];
            }
        }
        wv[i] = make_pair(sw, sv);
    }

    sort(wv, wv + (1 << n2));
    
    int m = 1;
    for (int i = 1; i < 1 << n2; i++)
    {
        if (wv[m - 1].second < wv[i].second)
        {
            wv[m++] = wv[i];
        }
    }

    ll ans = 0;
    for (int i = 0; i < 1 << (n - n2); i++)
    {
        ll sw = 0, sv = 0;
        for (int j = 0; j < n - n2; j++)
        {
            if (i >> j & 1)
            {
                sw += w[n2 + j];
                sv += v[n2 + j];
            }
        }

        if (sw <= W)
        {
            ll tmp = (lower_bound(wv, wv + m, make_pair(W - sw, 0x3f3f3f3f3f3f3f3f)) - 1)->second;
            ans = max(ans, sv + tmp);
        }
    }

    cout << ans << '\n';

    cout << flush;
    return 0;
}