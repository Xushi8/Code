// 2023/11/14 21:25:06
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
    vector<int> a(n);
    for (int& x : a)
    {
        cin >> x;
    }

    vector<pii> ans;
    int maxn = 2e9;
    int l = 0, r = 0;
    int sum = 0;
    while (1)
    {
        while (r < n && sum < k)
        {
            sum += a[r++];
        }

        if (sum < k)
        {
            break;
        }

        if (sum < maxn)
        {
            ans.clear();
            ans.emplace_back(l, r - 1);
            maxn = sum;
        }
        else if (sum == maxn)
        {
            ans.emplace_back(l, r - 1);
        }

        sum -= a[l++];
    }

    for (auto [x, y] : ans)
    {
        cout << x + 1 << '-' << y + 1 << '\n';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}