// 2023/07/07 11:43:18
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
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const int N = 1000005;

ll sum(ll a, ll n)
{
    // return n / a * (a + n / a * a) / 2;
    if (n / a % 2 == 0)
        return n / a / 2 * (a + n / a * a);
    else
        return (a + n / a * a) / 2 * (n / a);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n, a, b;
    cin >> n >> a >> b;
    ll ans = sum(1, n);
    ans -= sum(a, n);
    ans -= sum(b, n);
    ans += sum(a * b / __gcd(a, b), n);

    cout << ans << '\n';

    cout << endl;
    return 0;
}