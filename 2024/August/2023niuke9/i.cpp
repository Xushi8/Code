// 2024/08/12 12:47:23
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
    vector<array<int, 4>> a(n);
    for (auto& [l1, r1, l2, r2] : a)
    {
        cin >> l1 >> r1 >> l2 >> r2;
    }

    for (auto& [l1, r1, l2, r2] : a)
    {
        if (l1 > l2 || (l1 == l2 && r1 > r2))
        {
            swap(l1, l2);
            swap(r1, r2);
        }
    }

    
}