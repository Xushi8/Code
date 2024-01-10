// 2023/09/07 22:22:59
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
using namespace std;

using ll = long long;
using LL = long long;
using pii = pair<int, int>;
constexpr int N = 1000005;
int p, q;

int fast_pow(int a, int n)
{
    int res = 1;
    while (n != 0)
    {
        if (n & 1) res = 1LL * res * a % p;
        a = 1LL * a * a % p;
        n /= 2;
    }

    return res;
}

bool check(int x, int l, int r)
{
    if (l > r)
        return r < x && x <= l;
    else
        return x <= l || x > r;
}

int solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if ((a + b) % p != (c + d) % p)
        return -1;

    int inv = fast_pow(a + b, p - 2);
    a = 1LL * a * inv % p;
    c = 1LL * c * inv % p;
    int k;
    for (k = 0; (1 << k) < p; k++)
    {
        if (!check(c, (LL(a != 0 ? a : p) - 1 << k) % p, (LL(a) << k) % p))
        {
            break;
        }
    }

    return k;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> p >> q;
    while (q--)
    {
        int ret = solve();
        cout << ret << '\n';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}