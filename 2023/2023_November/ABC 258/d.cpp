// 2023/11/05 19:53:46
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
using pll = pair<ll, ll>;
constexpr int N = 1000005;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x;
    cin >> n >> x;
    vector<pll> a(n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        a[i] = {x, y};
    }

    ll ans = 9e18;
    ll tar = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == x)
            break;
        tar += a[i].first + a[i].second;
        ans = min(ans, tar + (x - i - 1) * a[i].second);
    }

    cout << ans << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}