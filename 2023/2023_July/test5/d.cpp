// 2023/07/31 14:53:25
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
const int N = 100005;

int n;
int arr[N];
ll dp[N];
ll func(int index)
{
    if (index == n)
        return dp[index] = 0;
    if (dp[index] >= 0)
        return dp[index];

    int num = arr[index];
    ll cnt = upper_bound(arr, arr + n, num) - lower_bound(arr, arr + n, num);

    return dp[index] = max(1LL * num * cnt + func(upper_bound(arr, arr + n, num + 1) - arr),
        func(lower_bound(arr, arr + n, num + 1) - arr));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    memset(dp, -1, sizeof(dp));
    cout << func(0) << '\n';

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}