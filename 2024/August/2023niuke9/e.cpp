// 2024/08/12 12:29:49
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

void dfs(int bx, int by, int ex, int ey, vector<array<int, 3>>& ans)
{
    int lenx = ex - bx;
    int leny = ey - by;
    // cout << bx <<  ' ' << by << ' ';
    ans.push_back({bx, by, 0});
    if (lenx == leny)
    {
        // cout << lenx << '\n';
        ans.back()[2] = lenx;
        return;
    }

    if (lenx > leny)
    {
        // cout << leny << '\n';
        ans.back()[2] = leny;
        dfs(bx + leny, by, ex, ey, ans);
    }
    else
    {
        // cout << lenx << '\n';
        ans.back()[2] = lenx;
        dfs(bx, by + lenx, ex, ey, ans);
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> ans;
    dfs(0, 0, n, m, ans);
    cout << "YES\n";
    cout << ans.size() << '\n';
    for (auto [x, y, z] : ans)
    {
        cout << x << ' ' << y << ' ' << z << '\n';
    }
}