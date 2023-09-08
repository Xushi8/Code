// 2023/09/06 15:39:40
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

void solve()
{
    int n;
    cin >> n;
    int yu = 0;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        yu ^= arr[i];
    }

    int cnt = __builtin_popcount(yu);
    if (n == 1)
        cout << 1 << '\n' << arr.front() << '\n';
    else
    {
        if (cnt >= n)
            cout << 1 << '\n';
        else
        {
            sort(arr.begin(), arr.end());
            vector<pii> tmp(n);
            for (int i = 0; i < n; i++)
            {
                tmp[i] = {__builtin_popcount(arr[i]), arr[i]};
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tt;
    cin >> tt;
    while (tt--)
    {
        solve();
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}