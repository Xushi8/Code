// 2023/10/16 11:14:03
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

void solve()
{
    int n, m;
    cin >> n >> m;
    int ans = 0;
    if (n > m)
        ans = 0;
    else
    {
        m++;
        for (int i = 30; i >= 0; i--)
        {
            if (((m >> i) & 1) && !((n >> i) & 1))
                ans |= (1 << i);
            if (!((m >> i) & 1) && ((n >> i) & 1))
                break;
        }
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