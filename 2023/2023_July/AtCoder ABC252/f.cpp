// 2023/07/06 23:26:56
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n, L;
    cin >> n >> L;
    priority_queue<ll, vector<ll>, greater<ll>> que;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        que.emplace(x);
        L -= x;
    }

    if (L > 0)
        que.emplace(L);

    ll ans = 0;
    while (que.size() >= 2)
    {
        ll a = que.top(); que.pop();
        ll b = que.top(); que.pop();
        que.emplace(a + b);
        ans += a + b;
    }

    cout << ans << '\n';

    cout << endl;
    return 0;
}