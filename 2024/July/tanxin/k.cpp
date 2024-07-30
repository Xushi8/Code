// 2024/07/29 23:04:22
#ifdef LOCAL
#include <basic_std_lib.h>
#else
#include <bits/stdc++.h>
#endif
using namespace std;

void solve();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    tt = 1;
    while (tt--)
    {
        solve();
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}

using i64 = int64_t;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<array<int, 2>> a(m);
    for (int i = 0; i < m; i++)
    {
        cin >> a[i][0] >> a[i][1];
    }
    sort(a.begin(), a.end());

    i64 ans = 0;
    for (int i = 0; i < 30; i++)
    {
        for (int j = 0, k = 0; j < m; j = k)
        {
            int x = 0;
            int cnt = 0; // 1的数量
            while (k < m && (j == k || a[k][0] - 1 == a[k - 1][0])) // 连续段[j,k)
            { 
                x ^= (a[k][1] >> i) & 1;
                if (x)
                    cnt++;
                k++;
            }
            if (a[j][0] == 1) // 从1开始的连续段没的选
                ans += (1ll << i) * cnt;
            else
                ans += (1ll << i) * min(cnt, a[k - 1][0] - a[j][0] + 2 - cnt); // 连续段前一位填0或1
        }
    }
    cout << ans << '\n';
}