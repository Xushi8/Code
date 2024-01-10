// 2023/08/05 10:20:57
#ifndef LOCAL
#pragma GCC optimize(2)
#endif
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
const int N = 200005;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n), jump(n);
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        for (int i = 0; i < n; i++)
        {
            jump[i] = arr[i] - (n - i) + 1;
        }

        vector<int> tmp = jump;
        sort(tmp.begin(), tmp.end(), greater<int>());
        int target = tmp[k - 1];
        int target_num = 1;
        for (int i = k - 2; i >= 0; i--)
        {
            if (tmp[i] == target)
                target_num++;
            else
                break;
        }

        for (int i = 0; i < n; i++)
        {
            if (jump[i] > target || (jump[i] == target && target_num > 0))
            {
                ans += n - i - 1;
                if (jump[i] == target)
                    target_num--;
            }
            else
            {
                ans += arr[i];
            }
        }

        ans -= 1LL * k * (k - 1) / 2;
        ans = max(0LL, ans);
        cout << ans << '\n';

    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}