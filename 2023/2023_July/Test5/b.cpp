// 2023/08/02 09:05:01
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
const int N = 1000005;

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
        vector<int> arr(n + 1);
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; i++)
            cin >> arr[i];

        for (int i = n; i >= 1; i--)
        {
            if (i + arr[i] > n)
            {
                dp[i] = arr[i];
                continue;
            }

            dp[i] = arr[i] + dp[i + arr[i]];
        }

        cout << *max_element(dp.begin(), dp.end()) << '\n';
    }


#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}