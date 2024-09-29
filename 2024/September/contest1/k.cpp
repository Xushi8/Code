// 2024/09/28 16:40:39
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
void print(array<int, 4> const& arr)
{
    auto [a, b, c, d] = arr;
    cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
}

void solve()
{
    int n;
    cin >> n;
    cout << 3 * n * n / 4 << '\n';

    for (int i = 1; i <= n; i += 2)
    {
        for (int j = 1; j <= n; j += 2)
        {
            array<int, 4> arr;
            arr = {1, i, j + 1, 2};
            print(arr);
            arr = {1, i + 1, j, 2};
            print(arr);
            arr = {2, i, j, 1};
            print(arr);
        }
    }
}