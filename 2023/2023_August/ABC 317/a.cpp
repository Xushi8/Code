// 2023/08/31 19:23:45
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
using ull = unsigned long long;
using pii = pair<int, int>;
constexpr int INF = 0x3f3f3f3f;
constexpr int MOD = (int)(1e9 + 7);
constexpr int N = 1000005;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, a, b;
    cin >> n >> a >> b;
    int ans = 0;
    int target = INF;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (a + x >= b && a + x < target)
        {
            target = a + x;
            ans = i;
        }
    }

    cout << ans + 1 << '\n';

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}