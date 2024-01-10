// 2023/08/04 09:35:29
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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        
        sort(arr.begin(), arr.end());
        arr.erase(unique(arr.begin(), arr.end()), arr.end());
        
        if (arr.size() == 1)
        {
            cout << 2 * arr[0] << '\n';
            continue;
        }
        else if (arr.size() == 2)
        {
            cout << arr[0] + arr[1] << '\n';
            continue;
        }
        
        vector<int> g1(arr.size()), g2(arr.size());
        g1[0] = arr[0];
        for (int i = 1; i < (int)g1.size(); i++)
        {
            g1[i] = __gcd(g1[i - 1], arr[i]);
        }
        g2.back() = arr.back();
        for (int i = (int)arr.size() - 2; i >= 0; i--)
        {
            g2[i] = __gcd(g2[i + 1], arr[i]);
        }

        

        int ans = max(g1.front() + g2[1], g2.back() + g1[arr.size() - 2]);
        for (int i = 1; i < (int)arr.size() - 1; i++)
        {
            ans = max(ans, arr[i] + __gcd(g1[i - 1], g2[i + 1]));
        }

        cout << ans << '\n';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}