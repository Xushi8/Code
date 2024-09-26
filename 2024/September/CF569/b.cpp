// 2024/09/26 14:41:51
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
    vector<int> a(n);
    vector<int> cnt(n);
    set<int> erase, to;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
        if(a[i] < n)
            cnt[a[i]]++;
        else
            erase.emplace(a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (cnt[i] > 1)
            erase.emplace(i);
        if (cnt[i] < 1)
            to.emplace(i);
    }
    for (int i = 0; i < n; i++)
    {
        if (erase.count(a[i]))
        {
            int old = a[i];
            a[i] = *to.begin();
            to.erase(to.begin());
            if (old < n && --cnt[old] == 1)
                erase.erase(old);
        }
    }
    for (auto x : a)
    {
        cout << x + 1 << ' ';
    }
    cout << '\n';
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
