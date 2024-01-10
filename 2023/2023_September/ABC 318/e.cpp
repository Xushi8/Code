// 2023/09/02 21:46:14
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

ll C(int n, int m)
{
    ll res = 1;
    if (m > n / 2)
        m = n - m;

    for (int i = 1; i < m; i++)
    {
        res *= n--;
    }
    for (int i = m; i >= 1; i--)
    {
        res /= i;
    }

    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<vector<int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        x--;
        arr[x].emplace_back(i);
    }

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (size_t j = 1; j < arr[i].size(); j++)
        {
            // for (size_t k = 0; k < j; k++)
            // {
            //     ans += arr[i][j] - arr[i][k] - j + k;
            // }
            //     // ans += arr[i][j] - arr[i][0] - j;

            ans += 1LL * (arr[i][j] - arr[i][j - 1] - 1) * C(arr[i].size() - 1, j);
        }
    }

    cout << ans << '\n';

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}