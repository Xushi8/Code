// 2023/12/04 20:24:19
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
#include <bitset>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 1000005;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q, x;
    cin >> n >> q >> x;
    vector<int> arr(n * 2);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        arr[i + n] = arr[i];
    }

    vector<ll> prefix(n * 2);
    for (int i = 0; i < n * 2; i++)
    {
        prefix[i] = i == 0 ? arr[i] : prefix[i - 1] + arr[i];
    }

    ll sum = prefix[n - 1];

    vector<int> ans(n);
    int u = 0;
    for (int i = 0; i < n; i++)
    {
        ans[i] = x / sum * n;
        int v = x % sum == 0 ? u - 1 : lower_bound(prefix.begin() + u, prefix.begin() + 2 * n, (u == 0 ? 0 : prefix[u - 1]) + x % sum) - prefix.begin();
        ans[i] += v - u + 1;
        u = (v + 1) % n;
    }

    vector<int> ans1(n);
    int tot = 0;
    int tar = u;
    while (1)
    {
        ans1[tot] = x / sum * n;
        int v = x % sum == 0 ? u - 1 : lower_bound(prefix.begin() + u, prefix.begin() + 2 * n, (u == 0 ? 0 : prefix[u - 1]) + x % sum) - prefix.begin();
        ans1[tot++] += v - u + 1;
        u = (v + 1) % n;
        if (u == tar)
        {
            break;
        }
    }

    while(q--) {
        ll x;
        cin >> x;
        x--;
        cout << (x < n ? ans[x] : ans1[(x - n) % tot]) << '\n';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}