// 2023/09/30 16:15:53
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
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 1000005;

void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int x, y, x1, y1, x2, y2;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;

    if (x1 == x2)
    {
        if (a + b > 0)
        {
            cout << "no\n";
            return;
        }
    }

    if (y1 == y2)
    {
        if (c + d > 0)
        {
            cout << "no\n";
            return;
        }
    }

    int disa = x - x1, disb = x2 - x, disc = y - y1, disd = y2 - y;
    if (a > b)
    {
        swap(a, b);
        swap(disa, disb);
    }
    if (c > d)
    {
        swap(c, d);
        swap(disc, disd);
    }
    b -= a;
    d -= c;

    if (b <= disb && d <= disd)
        cout << "yes\n";
    else
        cout << "no\n";
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