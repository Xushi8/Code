// 2024/11/06 13:46:13
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

void merge_sort(vector<int>& a, int l, int r, vector<int>& tmp, i64& ans)
{
    if (l >= r - 1)
        return;
    int mid = (l + r) / 2;
    merge_sort(a, l, mid, tmp, ans);
    merge_sort(a, mid, r, tmp, ans);
    int tot = l;
    int p = l, q = mid;
    while (tot < r)
    {
        if (q == r || (p < mid && a[p] <= a[q]))
            tmp[tot++] = a[p++];
        else
            tmp[tot++] = a[q++], ans += mid - p;
    }
    for (int i = l; i < r; i++)
    {
        a[i] = tmp[i];
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<int> tmp(n);

    i64 ans = 0;
    merge_sort(a, 0, n, tmp, ans);
    cout << ans << '\n';
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
