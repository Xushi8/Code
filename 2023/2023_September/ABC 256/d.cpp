// 2023/09/18 19:39:12
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<pii> arr(n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[i] = { a, b };
    }

    sort(arr.begin(), arr.end());

    vector<pii> ans;
    for (int i = 0; i < n; i++)
    {
        pii now = arr[i];
        while (i + 1 <= n && now.second >= arr[i + 1].first)
        {
            now.second = max(now.second, arr[i + 1].second);
            i++;
        }
        ans.emplace_back(now);
    }

    for (auto [x, y] : ans)
    {
        cout << x << ' ' << y << '\n';  
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}