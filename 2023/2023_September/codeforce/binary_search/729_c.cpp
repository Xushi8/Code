// 2023/10/03 20:24:28
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
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 1000005;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k, len, tim;
    cin >> n >> k >> len >> tim;
    vector<pii> arr(n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[i] = { a, b };
    }

    vector<int> dis(k + 2);
    dis[0] = 0;
    for (int i = 1; i <= k; i++)
    {
        cin >> dis[i];
    }
    dis[k + 1] = len;
    sort(dis.begin(), dis.end());

    auto check = [&](int ans) -> bool
        {
            int used_time = 0;
            for (size_t i = 1; i < dis.size(); i++)
            {
                int this_dis = dis[i] - dis[i - 1];
                int x = ans - this_dis;
                int y = 2 * this_dis - ans;
                if (x < 0)
                    return false;
                if (y < 0)
                    used_time += this_dis;
                else
                    used_time += x + y * 2;
            }
            return used_time <= tim;
        };

    int l = 0, r = 2e9;
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }

    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].second >= r)
        {
            if (ans == -1)
                ans = arr[i].first;
            else
                ans = min(ans, arr[i].first);
        }
    }

    cout << ans << '\n';

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}