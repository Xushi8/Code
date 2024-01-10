// 2023/10/11 22:11:40
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
    int n, m;
    cin >> n >> m;
    vector<int> tmpa(n), tmpb(n), a, b;
    for (int i = 0; i < n; i++)
    {
        cin >> tmpa[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> tmpb[i];
        if (tmpb[i] == 1)
            a.push_back(tmpa[i]);
        else
            b.push_back(tmpa[i]);
    }
    
    sort(a.begin(), a.end(), greater<>());
    sort(b.begin(), b.end(), greater<>());
    vector<ll> suma(a.size() + 1), sumb(b.size() + 1);
    for (size_t i = 1; i <= a.size(); i++)
    {
        suma[i] = suma[i - 1] + a[i - 1];
    }
    for (size_t i = 1; i <= b.size(); i++)
    {
        sumb[i] = sumb[i - 1] + b[i - 1];
    }

    ll ans = INT64_MAX;
    for (size_t i = 0; i < suma.size(); i++)
    {
        ll now = i;
        ll tmp = m - suma[i];
        auto it = lower_bound(sumb.begin(), sumb.end(), tmp);
        if (it != sumb.end())
        {
            ans = min(ans, now + 2 * (it - sumb.begin()));
        }
    }

    cout << (ans == INT64_MAX ? -1 : ans) << '\n';
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