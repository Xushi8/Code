// 2023/10/03 18:07:32
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
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 1000005;

int square[32000];

constexpr void pre()
{
    for (int i = 0; i < 32000; i++)
    {
        square[i] = i * i;
    }
}

constexpr int INF = 0x3f3f3f3f;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    pre();
    int n;
    cin >> n;
    vector<pii> arr(n);
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        auto it = lower_bound(square, square + 32000 - 5, x);
        arr[i].first = min(*it - x, x - *(it - 1));
        if (x == 0)
            arr[i].second = 2;
        else
            arr[i].second = 1;
    }
    sort(arr.begin(), arr.end());
    int cnt = upper_bound(arr.begin(), arr.end(), make_pair(0, INF)) - arr.begin();
    ll ans = 0;
    if (cnt > n / 2)
    {
        for (int i = 0; i < cnt - n / 2; i++)
        {
            ans += arr[i].second;
        }
    }
    else
    {
        for (int i = cnt; i < n / 2; i++)
        {
            ans += arr[i].first;
        }
    }

    cout << ans << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}