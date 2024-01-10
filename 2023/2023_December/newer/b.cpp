// 2023/12/13 19:01:48
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
    cin >> n;
    vector<pll> arr(n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        arr[i] = {x, y};
    }

    ll ax, ay;
    cin >> ax >> ay;

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            array<ll, 3> tmp;
            ll bx, by, cx, cy;
            bx = arr[i].first;
            by = arr[i].second;
            cx = arr[j].first;
            cy = arr[j].second;
            tmp[0] = abs(ax - bx) * abs(ax - bx) + abs(ay - by) * abs(ay - by);
            tmp[1] = abs(ax - cx) * abs(ax - cx) + abs(ay - cy) * abs(ay - cy);
            tmp[2] = abs(bx - cx) * abs(bx - cx) + abs(by - cy) * abs(by - cy);
            sort(tmp.begin(), tmp.end());
            if (tmp[0] + tmp[1] == tmp[2])
            {
                ans++;
            }
        }
    }

    cout << ans << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}