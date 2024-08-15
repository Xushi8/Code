// 2024/08/12 12:02:55
#ifdef LOCAL
#include <basic_std_lib.h>
#else
#include <bits/stdc++.h>
#endif
using namespace std;

#define int long long
#define endl '\n'
void solve();

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    tt = 1;
    // cin >> tt;
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
const int mod = 1e9 + 7;
int n, k;
const int N = 1e5 + 10;
int A[N];
void solve()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    if (k == 1)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum = max(sum, A[i]);
        }
        cout << sum << endl;
    }
    else
    {
        int ans = 0x3f3f3f3f3f;
        priority_queue<int> S;
        for (int i = 0; i < n; i++)
        {
            S.push(A[i]);
        }
        int cnt = 0;
        while (!S.empty())
        {
            int x = S.top();
            cnt++;
            if (x <= n)
            {
                break;
            }
            S.pop();
            S.push(x / k);
            ans = min(ans, cnt + S.top());
        }
        cout << ans << endl;
    }
}