// 2024/08/12 13:15:42
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
    cin >> tt;
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
using u64 = uint64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 1000005;

void func() {}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    a.insert(a.begin(), 0);

    vector<vector<int>> sum(n + 1, vector<int>(n + 2));
    for (int i = 1; i <= n; i++)
    {
        int r = i;
        int nr = i;
        int cnt = 0;
        for (int l = i; l >= 1; l--)
        {
            if (a[l] <= a[i])
                cnt++;
            while (r < n && cnt < i - l + 1)
            {
                r++;
                nr = r;
                if (a[r] <= a[l])
                    cnt++;
            }
            if (cnt == i - l + 1)
            {
                while (r < n && a[r + 1] > a[i])
                    r++;
                auto& s = sum[l];
                s[nr]++;
                s[r + 1]--;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            sum[i][j] += sum[i][j - 1];
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if (sum[i][j] == 0)
            {
                ans++;
            }
        }
    }
    cout << ans << '\n';
}