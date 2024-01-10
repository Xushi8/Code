// 2023/09/17 16:45:01
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
    
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        map<int, vector<int>> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            mp[arr[i]].emplace_back(i + 1);
        }

        int ans = arr[0], l = 1, r = 1;
        int maxn = 1;
        for (auto [x, vec] : mp)
        {
            int t = -0x3f3f3f3f, pos;
            for (int i = 0; i < vec.size(); i++)
            {
                if (vec[i] - 2 * i > t)
                {
                    t = vec[i] - 2 * i;
                    pos = vec[i];
                }
                int now = 2 * i - vec[i] + t + 1;
                if (now > maxn)
                {
                    maxn = now;
                    ans = x;
                    l = pos;
                    r = vec[i];
                }
            }
        }
        cout << ans << ' ' << l << ' ' << r << '\n';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}