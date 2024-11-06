// 2024/11/06 13:33:27
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

int bit1[N], bit2[N];

void add(int bit[], int x, int val)
{
    for (int i = x; i < N; i += i & -i)
    {
        bit[i] += val;
    }
}

int sum(const int bit[], int x)
{
    int res = 0;
    for (int i = x; i > 0; i -= i & -i)
    {
        res += bit[i];
    }
    return res;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int q, l, r;
        cin >> q >> l >> r;
        if (q == 1)
        {
            add(bit1, l, 1);
            add(bit2, r, 1);
        }
        else
        {
            int all = sum(bit1, r);
            all -= sum(bit2, l - 1);
            cout << all << '\n';
        }
    }
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
