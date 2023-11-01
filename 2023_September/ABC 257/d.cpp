// 2023/10/31 21:41:03
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdint>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <iomanip>
#include <cmath>
#include <stack>
#include <array>
#include <fstream>
#include <bitset>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 1000005;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<array<ll, 3>> arr(n);
    for (int i = 0; i < n; i++)
    {
        ll x, y, p;
        cin >> x >> y >> p;
        arr[i] = {x, y, p};
    }

    vector<vector<ll>> dis(n, vector<ll>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                dis[i][j] = 0;
            else
                dis[i][j] = (abs(arr[i][0] - arr[j][0]) + abs(arr[i][1] - arr[j][1]) + (arr[i][2] - 1)) / arr[i][2];
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dis[i][j] = min(dis[i][j], max(dis[i][k], dis[k][j]));
            }
        }
    }

    ll ans = 1e18;
    for (int i = 0; i < n; i++)
    {
        ll now = 0;
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;

            now = max(now, dis[i][j]);
        }
        ans = min(ans, now);
    }

    cout << ans << '\n';

    int a, b;
    for (int i = 0; i < n; i++)
    {
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}