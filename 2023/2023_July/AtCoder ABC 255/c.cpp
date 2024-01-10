// 2023/07/29 19:00:05
#ifndef DEBUG
#pragma GCC optimize(2)
#endif
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
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const int N = 1000005;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll x, a, d, n;
    cin >> x >> a >> d >> n;

    if (d == 0)
        cout << abs(x - a);
    else
    {
        if (d < 0)
        {
            a = a + (n - 1) * d;
            d = -d;
        }

        if (x <= a)
            cout << abs(a - x);
        else if (a + (n - 1) * d <= x)
            cout << abs(a + (n - 1) * d - x);
        else
        {
            ll k = (x - a) / d;

            cout << min(abs(a + k * d - x), abs(a + (k + 1) * d - x));
        }
    }
    

    

    

    cout << endl;
    return 0;
}