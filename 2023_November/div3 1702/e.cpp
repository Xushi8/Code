// 2023/11/21 17:00:53
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

void solve()
{
    int n;
    cin >> n;
    vector<pii> arr(n);
    bool flag = 0;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        arr[i] = {x, y};
        if (x == y)
        {
            flag = 1;
        }
    }
    if (flag)
    {
        cout << "NO" << '\n';
        return;
    }
    set<int> a, b;
    vector<bool> used(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (!used[i])
        {
            auto [x, y] = arr[i];
            if (a.count(x) == 0 && a.count(y) == 0)
            {
                a.emplace(x);
                a.emplace(y);
                used[i] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (!used[i])
        {
            auto [x, y] = arr[i];
            if (b.count(x) == 0 && b.count(y) == 0)
            {
                b.emplace(x);
                b.emplace(y);
                used[i] = 1;
            }
        }
    }

    cout << (count(used.begin(), used.end(), 1) == n ? "YES" : "NO") << '\n';
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