// 2023/09/17 16:28:16
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

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int& x : arr)
        cin >> x;

    int ans = 0;
    int s = 0, t = s + 1;
    while (1)
    {
        while (t < n && arr[t] * 2 > arr[t - 1])
            t++;

        int len = t - s;
        if (len >= k + 1)
            ans += len - k;
        
        s = t;
        t = s + 1;

        if (s == n)
            break;
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