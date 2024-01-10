// 2023/08/16 09:02:50
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

    int tt;
    cin >> tt;
    while (tt--)
    {
        int n, m;
        cin >> n >> m;
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int ans = INF;
        if (x1 == 1 || x1 == n)
        {
            if (y1 == 1 || y1 == m)
                ans = min({ ans, 2 });
            else
                ans = min({ ans, 3 });
        }

        if (y1 == 1 || y1 == m)
        {
            if (x1 == 1 || x1 == n)
                ans = min(ans, 2);
            else
                ans = min(ans, 3);
        }

        if (x2 == 1 || x2 == n)
        {
            if (y2 == 1 || y2 == m)
                ans = min({ ans, 2 });
            else
                ans = min({ ans, 3 });
        }

        if (y2 == 1 || y2 == m)
        {
            if (x2 == 1 || x2 == n)
                ans = min(ans, 2);
            else
                ans = min(ans, 3);
        }

        if (x1 != x2)
        {
            if (y1 != y2)
            {
                ans = min({ ans, 4, n, m });
            }
            else
            {
                ans = min({ ans, 4, m });
            }
        }

        if (y1 != y2)
        {
            if (x1 != x2)
            {
                ans = min({ ans, 4, n, m });
            }
            else
            {
                ans = min({ ans, 4, n });
            }
        }

        cout << ans << '\n';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}