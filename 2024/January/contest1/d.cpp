// 2024/01/12 13:03:18
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

    int n;
    while (cin >> n && n != 0)
    {
        vector<int> arr(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        vector<int> L(n + 2), R(n + 2);
        stack<int> stk;

        for (int i = 1; i <= n; i++)
        {
            while (!stk.empty() && arr[stk.top()] >= arr[i])
            {
                stk.pop();
            }

            L[i] = stk.empty() ? 0 : stk.top();
            stk.emplace(i);
        }

        stack<int>().swap(stk);

        for (int i = n; i >= 1; i--)
        {
            while (!stk.empty() && arr[stk.top()] >= arr[i])
            {
                stk.pop();
            }
            R[i] = stk.empty() ? n + 1 : stk.top();
            stk.emplace(i);
        }

        ll ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ll len = (i - L[i]) + (R[i] - i) - 1;
            ans = max(ans, arr[i] * len);
        }
        cout << ans << '\n';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}