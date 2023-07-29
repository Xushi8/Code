// 2023/07/29 09:02:42
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

ll exgcd(ll a, ll b, ll& X, ll& Y)
{
    if (b == 0)
    {
        X = 1;
        Y = 0;
        return a;
    }

    ll res = exgcd(b, a % b, X, Y);
    Y -= (a / b) * Y;
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tt;
    cin >> tt;
    while (tt--)
    {
        ll k, n;
        cin >> k >> n;
        ll X, Y;
        ll tmp = exgcd(2, n, X, Y);
        if (k % tmp != 0)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
    }

    cout << endl;
    return 0;
}