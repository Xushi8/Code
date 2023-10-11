// 2023/10/11 13:54:58
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

ll sum(ll a, ll b)
{
    ll n = b - a + 1;
    if (a <= b)
        return n * (a + b) / 2;
    return 0;
}

void solve()
{
    int n;
    cin >> n;
    vector<ll> k(n + 1), h(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> k[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }

    ll ans = 0;
    ll pre = k[n];
    for (int i = n; i >= 1; i--)
    {
        if (k[i] - k[i - 1] >= h[i])
            ans += sum(1, pre - k[i] + h[i]), pre = k[i - 1];
        else
            h[i - 1] = max(h[i - 1], h[i] - (k[i] - k[i - 1]));
    }

    cout << ans << '\n';
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