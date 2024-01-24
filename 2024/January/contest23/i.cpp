// 2024/01/24 14:59:42
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

ll t[N];
bool func(ll x)
{
    for (int i = 62; i >= 0; i--)
    {
        if (((x >> i) & 1) == 0)
            continue;
        if (t[i] == 0)
        {
            t[i] = x;
            return true;
        }
        else
        {
            x ^= t[i];
        }
        if (x == 0)
            break;
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    ll sum = 0;
    ll x = 0;
    for (int i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        sum ^= a;
        x += func(a ^ b);
    }
    if (func(sum))
        cout << "1/1\n";
    else
        cout << (1LL << x) - 1 << '/' << (1LL << x) << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}