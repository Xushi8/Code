// 2023/12/14 11:15:37
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

constexpr ll MOD = 1e9 + 7;

ll fast_pow(ll a, ll n, const ll mod = MOD)
{
    ll b = 1;
    while (n)
    {
        if (n & 1)
            b = b * a % n;
        a = a * a % n;
        n /= 2;
    }
    return b;
}

ll inv(ll a, ll n, const ll mod = MOD) {
    return fast_pow(a, n - 2, mod);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}