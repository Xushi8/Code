// 2024/08/06 12:05:59
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

    cout << setprecision(20) << fixed;

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

void solve()
{
    int L, x, y;
    cin >> L >> x >> y;

    auto dis = [](double x, double y, double x1, double y1)
    {
        return sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));  
    };
    double dis1 = dis(x, y, 0, 0);
    double dis2 = dis(x, y, L, 0);
    if (dis1 <= L)
    {
        cout << "Yes\n";
        cout << 0 << '\n';
    }
    else if (dis2 <= L)
    {
        cout << "Yes\n";
        cout << 1.0 * L << '\n';
    }
    else
    {
        cout << "No\n";
    }
}