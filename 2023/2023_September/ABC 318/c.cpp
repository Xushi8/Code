// 2023/09/02 20:53:52
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
using pii = pair<int, int>;
constexpr int N = 1000005;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n, d, p;
    cin >> n >> d >> p;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(), greater<int>());
    ll ans = 0;
    ll t;
    for (t = 0; t < n; t++)
    {
        ll sum = 0;
        for (ll i = 0 + d * t, j = 0; i < n && j < d; i++, j++)
        {
            sum += arr[i];
        }
        if (sum <= p)
            break;
    }

    ll sum = 0;
    for (ll i = 0 + d * t, j = 0; i < n && j < d; i++, j++)
    {
        sum += arr[i];
    }

    if (sum > p)
        t++;

    ans += t * p;
    for (ll i = 0 + d * t; i < n; i++)
    {
        ans += arr[i];
    }

    cout << ans << '\n';

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}