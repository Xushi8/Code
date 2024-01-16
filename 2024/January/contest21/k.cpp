// 2024/01/15 20:58:44
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

    int n, k;
    cin >> n >> k;
    vector<pii> a;
    a.reserve(2 * n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        a.emplace_back(x, -1);
        a.emplace_back(y, 1);
    }

    sort(a.begin(), a.end());

    int now = 0;
    int be;
    vector<pii> ans;
    for (size_t i = 0; i < a.size(); i++)
    {
        if (now == k - 1 && a[i].second == -1)
            be = a[i].first;
        if (now == k && a[i].second == 1)
            ans.emplace_back(be, a[i].first);
        now -= a[i].second;
    }

    cout << ans.size() << '\n';
    for (auto [x, y] : ans)
    {
        cout << x << ' ' << y << '\n';
    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}