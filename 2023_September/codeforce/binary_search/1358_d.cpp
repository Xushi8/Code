// 2023/10/27 21:23:21
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

ll sum[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    for (ll i = 1; i < N; i++)
    {
        sum[i] = sum[i - 1] + i;
    }

    ll n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int& x : arr)
        cin >> x;

    ll ans = 0, tmp = 0;
    int now = n - 1;
    for (int i = n - 1; i >= 0; i--)
    {
        while (k > 0)
        {
            k -= arr[now];
            tmp += sum[arr[now]];
            if (now == 0)
                now = n - 1;
            else
                now--;
        }

        ans = max(ans, tmp - (-k) * (1 + (-k)) / 2); // 多加了1 ～ abs(x)，在这里减去
        tmp -= sum[arr[i]];
        k += arr[i];
    }

    cout << ans << '\n';

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}