// 2024/11/16 11:14:54
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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = std::count(s.begin(), s.end(), '0');
    if (cnt == 0)
    {
        cout << "DRAW" << '\n';
        return;
    }

    if (cnt % 2 == 1 && cnt > 1)
        cout << "ALICE" << '\n';
    else
        cout << "BOB" << '\n';
}

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
