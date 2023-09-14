// 2023/09/13 14:44:57
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
#include <bitset>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 1000005;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < (1 << 6); i++)
    {
        cout << bitset<6>(i) << ' ' << i << '\n';
    }

    ll arr[35];
    arr[0] = 0;
    arr[1] = 2;
    arr[2] = 2 + arr[1];
    for (ll i = 3; i < 35; i++)
    {
        arr[i] = arr[i - 1] + i * (1LL << (i - 1));
        // cout << arr[i] << '\n';
    }

    // for (int i = 0; i < 5; i++)
    // {
    //     cout << arr[i] << '\n';
    // }

    int tt;
    cin >> tt;
    while (tt--)
    {
        ll k;
        cin >> k;
        ll tmp = lower_bound(arr, arr + 35, k) - arr;
        ll tmp1 = upper_bound(arr, arr + 35, k) - arr;
        // cout << *lower_bound(arr, arr + 35, k) << ' ';
        if (tmp == tmp1)
            cout << tmp - 1 << '\n';
        else
            cout << tmp << '\n';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}