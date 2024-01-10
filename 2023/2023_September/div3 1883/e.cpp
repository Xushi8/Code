// 2023/10/22 20:21:30
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
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<ll> cnt(n, 0);
    for (int i = 1; i < n; i++)
    {
        if (arr[i] >= arr[i - 1])
        {
            int now = 0;
            int tmp = arr[i - 1];
            while (tmp * 2 <= arr[i])
            {
                tmp *= 2;
                now--;
            }
            cnt[i] = now;
        }
        else
        {
            int now = 0;
            int tmp = arr[i];
            while (tmp < arr[i - 1])
            {
                tmp *= 2;
                now++;
            }
            cnt[i] = now;
        }
    }

    for (int i = 1; i < n; i++)
    {
        cnt[i] += cnt[i - 1];
        if (cnt[i] < 0)
            cnt[i] = 0;
    }

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += cnt[i];
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