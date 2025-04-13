// 2025/04/13 18:10:43
#ifdef LOCAL
#include <basic_std_lib.h>
#else
#include <bits/stdc++.h>
#endif
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 1e6 + 6;

void solve()
{
    int n1, n2, x, y;
    cin >> n1 >> n2 >> x >> y;

    if (x >= n1 && y >= n1)
    {
        cout << x << "-Y " << y << "-Y\n";
        cout << "huan ying ru guan\n";
        return;
    }

    if (x < n1 && y < n1)
    {
        cout << x << "-N " << y << "-N\n";
        cout << "zhang da zai lai ba\n";
        return;
    }

    if (x < n1 && y >= n2)
    {
        cout << x << "-Y " << y << "-Y\n";
        cout << "qing 2 zhao gu hao 1\n";
        return;
    }

    if (y < n1 && x >= n2)
    {
        cout << x << "-Y " << y << "-Y\n";
        cout << "qing 1 zhao gu hao 2\n";
        return;
    }

    if (x < n1)
    {
        cout << x << "-N " << y << "-Y\n";
        cout << "2: huan ying ru guan\n";
        return;
    }

    cout << x << "-Y " << y << "-N\n";
    cout << "1: huan ying ru guan\n";
}

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
