// 2024/07/30 20:42:03
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
    int n, q;
    cin >> n >> q;
    int last = 1;
    set<int> called;
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            called.emplace(last++);
        }
        else if (op == 2)
        {
            int x;
            cin >> x;
            called.erase(x);
        }
        else
        {
            cout << *called.begin() << '\n';
        }
    }
}