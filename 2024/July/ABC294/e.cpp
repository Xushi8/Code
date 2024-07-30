// 2024/07/30 20:47:52
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
using u64 = uint64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 1000005;

void solve()
{
    i64 L, n1, n2;
    cin >> L >> n1 >> n2;
    vector<array<i64, 3>> a(n1), b(n2);
    i64 last;
    last = 0;
    for (int i = 0; i < n1; i++)
    {
        i64 val, cnt;
        cin >> val >> cnt;
        a[i] = {last, last + cnt - 1, val};
        last += cnt;
    }
    last = 0;
    for (int i = 0; i < n2; i++)
    {
        i64 val, cnt;
        cin >> val >> cnt;
        b[i] = {last, last + cnt - 1, val};
        last += cnt;
    }

    i64 ans = 0;
    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        while (a[i][1] < b[j][0])
            i++;
        while (b[j][1] < a[i][0])
            j++;
        if (a[i][2] == b[j][2])
        {
            ans += min(a[i][1], b[j][1]) - max(a[i][0], b[j][0]) + 1;
        }

        if (a[i][1] <= b[j][1])
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    cout << ans << '\n';
}