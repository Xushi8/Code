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
    vector<array<int, 3>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i][0];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> a[i][1];
        a[i][2] = i + 1;
    }

    
}