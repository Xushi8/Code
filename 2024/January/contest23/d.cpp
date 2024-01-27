// 2024/01/23 09:35:46
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

void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(m);
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll ans = (k - 1) * 2;
    if (a.front() < k)
    {
        a.erase(a.begin());
    }
    for (size_t i = 0; i < a.size(); i++)
    {
        ans += abs(a[i] - k) * 2;
    }
    
    // int id = int(lower_bound(a.begin(), a.end(), k) - a.begin());
    // ll ans = 0;
    // if (id == 0)
    // {
    //     ans += (k - 1) * 2;
    //     for (int i = 0; i < m; i++)
    //     {
    //         ans += (a[i] - k) * 2;
    //     }
    // }
    // else if (id == m)
    // {
    //     ans += (k - 1) * 2;
    //     for (int i = 1; i < m; i++)
    //     {
    //         ans += (k - a[i]) * 2;
    //     }
    // }
    // else
    // {
    //     ans += (k - 1) * 2;
    //     for (int i = id; i < m; i++)
    //     {
    //         ans += (a[i] - k) * 2;
    //     }
    //     for (int i = 1; i < id; i++)
    //     {
    //         ans += (k - a[i]) * 2;
    //     }
    // }

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
    return 0;
}