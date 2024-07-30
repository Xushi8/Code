// 2024/07/29 21:24:39
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
    int n;
    cin >> n;
    vector<array<int, 4>> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][0];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][1];
        arr[i][2] = min(arr[i][0], arr[i][1]);
        arr[i][3] = i;
    }
    auto cp = arr;
    sort(arr.begin(), arr.end(), [](auto const& l, auto const& r)
        {
            return l[2] < r[2];
        });

    vector<int> ans(n);
    int l = 0, r = n - 1;
    for (auto [a, b, m, index] : arr)
    {
        if (m == a)
            ans[l++] = index;
        else
            ans[r--] = index;
    }

    int tim[2] = {};
    for (auto x : ans)
    {
        tim[0] += cp[x][0];
        tim[1] = max(tim[0], tim[1]);
        tim[1] += cp[x][1];
    }
    cout << tim[1] << '\n';

    for (auto x : ans)
        cout << x + 1 << ' ';
    cout << '\n';
}