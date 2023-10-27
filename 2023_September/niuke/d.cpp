// 2023/10/27 11:01:57
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdint>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <functional>
#include <iomanip>
#include <cmath>
#include <stack>
#include <array>
#include <fstream>
#include <bitset>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 1000005;
constexpr int INF = 0x3f3f3f3f;

void solve()
{
    ll n, m, x, y;
    cin >> n >> m >> x >> y;
    n--; m--;
    ll minn = min(n, m), maxx = max(n, m);
    ll ans = 0;
    if (minn == 0)
        ans = maxx * x;
    else if (x * 2 <= y)
        ans = (minn + maxx) * x;
    else if (x <= y)
        ans = minn * y + (maxx - minn) * x;
    else
    {
        if ((maxx - minn) & 1)
            ans = (maxx - 1) * y + x;
        else
            ans = maxx * y;
    }

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tt;
    cin >> tt;
    while (tt--)
    {
        solve();
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}