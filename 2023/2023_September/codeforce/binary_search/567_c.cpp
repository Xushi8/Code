// 2023/10/12 11:01:01
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    map<ll, int> mp;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        mp[arr[i]]++;
    }

    ll ans = 0;
    map<ll, int> tmp;
    for (ll i = 0; i < n; i++)
    {
        if (arr[i] % k != 0)
        {
            tmp[arr[i]]++;
            continue;
        }
        
        ll a = tmp[arr[i] / k];
        ll b = mp[arr[i] * k] - tmp[arr[i] * k];
        if (k == 1 || arr[i] == 0)
            b--;
        
        ans += a * b;
        tmp[arr[i]]++;
    }

    cout << ans << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}