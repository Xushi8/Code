// 2023/07/14 19:50:28
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

bool check(int n, int ans)
{
    int l, r;
    if ((n - ans) & 1)
    {
        l = (n - ans) / 2 + 1;
        r = (n - ans) / 2;
    }
    else
    {
        l = (n - ans) / 2 + 1;
        r = (n - ans) / 2 - 1;
    }

    return ans > l && l > r && r > 0;
}

int solve(int n)
{
    int left = 1, right = n;
    int mid = left + (right - left) / 2;
    while (left < right - 1)
    {
        if (check(n, mid))
            right = mid;
        else
            left = mid;
        
        mid = left + (right - left) / 2;
    }

    return right;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tt;
    cin >> tt;
    while (tt--)
    {
        int x;
        cin >> x;
        int ans = solve(x);
        int l, r;
        if ((x - ans) & 1)
        {
            l = (x - ans) / 2 + 1;
            r = (x - ans) / 2;
        }
        else
        {
            l = (x - ans) / 2 + 1;
            r = (x - ans) / 2 - 1;
        }
        cout << l << ' ' << ans << ' ' << r << '\n';
    }

    cout << endl;
    return 0;
}