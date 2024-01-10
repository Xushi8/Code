// 2023/10/12 12:51:25
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
    int maxn = *max_element(arr.begin(), arr.end());

    auto check = [&](ll val) -> bool
        {
            ll allx = val / 2 + (val & 1), ally = val / 2;
            ll now = maxn;
            for (int i = 0; i < n; i++)
            {
                ll dec = now - arr[i];
                if (dec & 1)
                {
                    dec--;
                    allx--;
                }

                if (dec / 2 <= ally)
                    ally -= dec / 2;
                else
                {
                    dec -= ally * 2;
                    ally = 0;
                    allx -= dec;
                }
            }
            if (allx >= 0 && ally >= 0)
                return true;

            allx = val / 2 + (val & 1), ally = val / 2;
            now = maxn + 1;
            for (int i = 0; i < n; i++)
            {
                ll dec = now - arr[i];
                if (dec & 1)
                {
                    dec--;
                    allx--;
                }

                if (dec / 2 <= ally)
                    ally -= dec / 2;
                else
                {
                    dec -= ally * 2;
                    ally = 0;
                    allx -= dec;
                }
            }
            if (allx >= 0 && ally >= 0)
                return true;
            else
                return false;
        };

    ll l = 0, r = 1e18, ans = r;
    while (l <= r)
    {
        ll mid = l + (r - l) / 2;
        if (check(mid))
            ans = mid, r = mid - 1;
        else
            l = mid + 1;
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