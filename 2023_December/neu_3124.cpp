// 2023/12/14 11:27:53
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
using pll = pair<ll, ll>;
constexpr int N = 1000005;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    ll x;
    cin >> n >> x;
    vector<pll> arr(n);
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        arr[i] = {x, i};
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        int l = i + 1, r = n - 1;
        while (l < r)
        {
            ll sum = arr[i].first + arr[l].first + arr[r].first;
            if (sum > x)
            {
                r--;
            }
            else if (sum < x)
            {
                l++;
            }
            else
            {
                array<ll, 3> ans = {arr[i].second, arr[l].second, arr[r].second};
                sort(ans.begin(), ans.end());
                for (int i = 0; i < 3; i++)
                {
                    cout << ans[i] + 1 << ' ';
                }
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;

#ifdef LOCAL
        cerr
         << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}