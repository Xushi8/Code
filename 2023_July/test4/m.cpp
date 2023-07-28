// 2023/07/28 15:49:03
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

ll exgcd(ll a, ll b, ll& x, ll& y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }

    ll res = exgcd(b, a % b, x, y);
    ll tmp = x;
    x = y;
    y = tmp - (a / b) * y;
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll x, y, m, n, L;
    cin >> x >> y >> m >> n >> L;
    ll a = (n - m + L) % L;
    ll b = (x - y + L) % L;
    ll X, Y;
    ll gcd = exgcd(a, L, X, Y);
    if (b % gcd != 0)
        cout << "Impossible\n";
    else
    {
        ll c1 = b / gcd;
        X *= c1;
        L /= gcd;
        X = (X % L + L) % L;
        cout << X << '\n';
    }

    cout << endl;
    return 0;
}