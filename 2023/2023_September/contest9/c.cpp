// 2023/10/02 09:50:54
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
#define int long long

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 1000005;

void solve()
{
    int n;
    cin >> n;
    vector<pii> arr(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[i] = { a, b };
        sum += b;
    }
    sort(arr.begin(), arr.end());
    int index; // 不选的
    int now = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        now += arr[i].second;
        if (now > sum / 2)
        {
            now -= arr[i].second;
            index = i;
            break;
        }

        ans -= arr[i].first * arr[i].second;
    }

    int cnt = 0;
    for (int i = index + 1; i < n; i++)
    {
        cnt += arr[i].second;
        ans += arr[i].first * arr[i].second;
    }

    if (cnt < now)
        ans += arr[index].first * (now - cnt);
    else
        ans -= arr[index].first * (cnt - now);

    cout << ans << '\n';
}

int32_t main()
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