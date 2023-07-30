// 2023/07/29 19:39:50
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    vector<int> arr(n + 1);
    arr[0] = 0;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());
    vector<ll> sum(n + 1);
    sum[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + arr[i];
    }

    while (q--)
    {
        ll x;
        cin >> x;
        ull k = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
        ll sum1 = sum[k - 1];
        ll sum2 = sum[n] - sum[k - 1];
        ll ans = 0;
        ans += (k - 1) * x - sum1;
        ans += sum2 - (n - (k - 1)) * x;
        cout << ans << '\n';
    }

    cout << endl;
    return 0;
}