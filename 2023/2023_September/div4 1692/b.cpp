// 2023/09/17 11:14:37
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
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());

        int ans = 0;
        int all_cnt = 0;
        for (int i = 0, j; i < n; i++)
        {
            int cnt = 1;
            for (j = i + 1; j < n; j++)
            {
                if (arr[j] == arr[i])
                    cnt++;
                else
                    break;
            }

            if (cnt == 1)
                ans++;
            else if (cnt % 2 != 0)
            {
                ans++;
                all_cnt += cnt - 1;
            }
            else
            {
                ans++;
                all_cnt -= cnt - 1;
            }

            i = j - 1;
        }

        ans -= (all_cnt % 2) != 0;
        cout << ans << '\n';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}