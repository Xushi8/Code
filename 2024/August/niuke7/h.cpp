// 2024/08/06 13:49:55
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
    vector<string> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    map<string, int> field;
    for (int i = 0; i < n; i++)
    {
        field.try_emplace(a[i], i);
    }

    struct data
    {
        int m_id;
        vector<string> m_data;
    };

    int id = 0;
    vector<data> datas;
    vector<map<string, int>> suoyin(n);
}