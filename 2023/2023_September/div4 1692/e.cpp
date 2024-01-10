// 2023/09/17 13:04:11
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
        int n, s;
        cin >> n >> s;
        vector<int> arr(n), sum_l(n + 1), sum_r(n + 1);
        int ans = INT32_MAX, sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }

        int target = sum - s;
        if (target == 0)
            ans = 0;
        else if (target < 0)
            ans = -1;
        else
        {
            sum_l[0] = 0;
            for (int i = 1; i <= n; i++)
            {
                sum_l[i] = sum_l[i - 1] + arr[i - 1];
            }
            sum_r[0] = 0;
            for (int i = 1; i <= n; i++)
            {
                sum_r[i] = sum_r[i - 1] + arr[n - i];
            }

            for (int i = 0; i < n; i++)
            {
                int j = lower_bound(sum_r.begin(), sum_r.end(), target - sum_l[i]) - sum_r.begin();
                ans = min(ans, i + j);
            }
        }

        cout << (ans == INT32_MAX ? -1 : ans) << '\n';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}