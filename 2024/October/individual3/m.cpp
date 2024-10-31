// 2024/10/16 14:24:21
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



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cout << setprecision(50);
    for (int i = 0; i < 20; i++)
    {
        cout << i << ' ' << std::tgamma(i + 1) << '\n';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
