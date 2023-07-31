// 2023/07/31 13:13:59
#ifndef DEBUG
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
    
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int cnt = 0;
    int last = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (last <= arr[i])
        {
            last = arr[i];
            cnt++;
        }
        else
        {
            last = arr[i];
            cnt = 1;
        }

        ans = max(ans, cnt);
    }

    cout << ans << '\n';

    cout << endl;
    return 0;
}