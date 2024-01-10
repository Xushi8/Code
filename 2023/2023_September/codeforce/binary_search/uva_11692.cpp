// 2023/10/05 17:57:40
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
    double l, k, t1, t2, h;
    cin >> l >> k >> t1 >> t2 >> h;
    if (h < l)
    {
        cout << k * t1 << ' ' << k * t1 << '\n';
        return;
    }

    if (fabs(l - h) < 1e-6)
    {
        double a = 0.0;
        double b = k * t2;
        cout << h + a << ' ' << h + b << '\n';
    }
    else
    {
        
    }
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
    cout << flush;
    return 0;
}