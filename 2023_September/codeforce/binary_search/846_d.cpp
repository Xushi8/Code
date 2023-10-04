// 2023/10/04 20:16:02
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
constexpr int N = 1005;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k, q;
    cin >> n >> m >> k >> q;
    vector<array<int, 3>> arr(q);
    for (int i = 0; i < q; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        arr[i] = { c, a, b };
    }
    sort(arr.begin(), arr.end());

    auto check = [&](int val) -> bool
        {
            int index = upper_bound(arr.begin(), arr.end(), array<int, 3>{val, 999, 999}) - arr.begin();
            vector<vector<int>> cnt(n + 1, vector<int>(m + 1, 0));
            for (int i = 0; i < index; i++)
            {
                auto [a, x, y] = arr[i];
                cnt[x][y] = 1;
            }

            for (int i = 1; i <= n; i++)
            {
                for (int j = 2; j <= m; j++)
                {
                    cnt[i][j] += cnt[i][j - 1];
                }
            }
            for (int j = 1; j <= m; j++)
            {
                for (int i = 2; i <= n; i++)
                {
                    cnt[i][j] += cnt[i - 1][j];
                }
            }

            for (int i = k; i <= n; i++)
            {
                for (int j = k; j <= m; j++)
                {
                    if (cnt[i][j] - cnt[i - k][j] - cnt[i][j - k] + cnt[i - k][j - k] == k * k)
                        return true;
                }
            }

            return false;
        };

    int l = 0, r = 1000000000, ans = -1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (check(mid))
            ans = mid, r = mid - 1;
        else
            l = mid + 1;
    }

    cout << ans << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}