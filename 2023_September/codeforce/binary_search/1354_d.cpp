// 2023/10/20 20:44:21
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
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    sort(a.begin(), a.end());

    auto check = [&](int val) -> bool
        {
            int cnt = a.end() - lower_bound(a.begin(), a.end(), val); // 记录>=val的数目
            // cerr << cnt << ' ' << lower_bound(a.begin(), a.end(), val) - a.begin() << '\n';
            int tot = a.size(); // 记录此时的a中的数量
            for (auto x : b)
            {
                if (x > 0)
                    cnt += (x >= val);
                else
                    cnt -= (-x > tot - cnt);
                
                if (x > 0)
                    tot++;
                else
                    tot--;
            }

            return cnt > 0;
        };

    int l = 0, r = 1e9, ans = 0;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (check(mid))
            ans = mid, l = mid + 1;
        else
            r = mid - 1;
    }

    cout << ans << '\n';

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}