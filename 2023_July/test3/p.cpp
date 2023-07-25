// 2023/07/25 16:43:32
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
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const int N = 1000005;

#define int long long

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int& x : arr)
        cin >> x;

    // arr[i] * arr[j] + arr[k] 
    // arr[i] * (arr[j] + arr[k])

    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                m[arr[i] * arr[j] + arr[k]]++;

    ull ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                if (arr[i] != 0)
                    ans += m[arr[i] * (arr[j] + arr[k])];

    cout << ans << '\n';

    cout << endl;
    return 0;
}