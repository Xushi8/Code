// 2023/08/05 10:01:20
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
        int n, x;
        cin >> n >> x;
        vector<int> arr(x);
        for (int i = 0; i < x; i++)
            cin >> arr[i];
        sort(arr.begin(), arr.end());
        vector<int> len;
        for (int i = 1; i < x; i++)
        {
            len.emplace_back(arr[i] - arr[i - 1] - 1);
        }
        len.emplace_back(n - arr[x - 1] + arr[0] - 1);

        sort(len.begin(), len.end());
        int tot = 0;
        int ans = 0;
        for (int i = (int)len.size() - 1; i >= 0; i--)
        {
            if (len[i] - 4 * tot == 1)
            {
                ans++;
                break;
            }
            
            ans += max(0, len[i] - 1 - 4 * tot);
            tot++;
        }

        cout << n - ans << '\n';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}