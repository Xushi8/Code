// 2023/10/03 21:16:20
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }

    priority_queue<pii, vector<pii>, less<pii>> que;
    for (auto [x, y] : mp)
    {
        que.emplace(y, x);
    }

    vector<array<int, 3>> ans;
    while (que.size() >= 3)
    {
        auto [a1, b1] = que.top(); que.pop();
        auto [a2, b2] = que.top(); que.pop();
        auto [a3, b3] = que.top(); que.pop();
        a1--; a2--; a3--;
        ans.push_back({ b1, b2, b3 });
        sort(ans.back().begin(), ans.back().end(), greater<int>());
        if (a1 != 0) que.emplace(a1, b1);
        if (a2 != 0) que.emplace(a2, b2);
        if (a3 != 0) que.emplace(a3, b3);
    }

    cout << ans.size() << '\n';
    for (auto [a, b, c] : ans)
    {
        cout << a << ' ' << b << ' ' << c << '\n';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}