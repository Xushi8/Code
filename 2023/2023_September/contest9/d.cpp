// 2023/10/02 10:18:29
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

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> arr(n);
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        ans += a;
        arr[i] = { b - a, a, b };
    }
    sort(arr.begin(), arr.end(), greater<>());

    if (n == 1)
    {
        cout << arr[0][2] << '\n';
        return;
    }
    
    int available = m - n;
    int cnt = 0; // 独居的人
    for (int i = 0; i < n && i < available; i++)
    {
        if (arr[i][0] > 0)
        {
            ans += arr[i][0];
            cnt++;
        }
        else
            break;
    }

    if (n - cnt == 1)
    {
        ans -= min(-arr[cnt][0], arr[cnt - 1][0]);
    }

    cout << ans << '\n';
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