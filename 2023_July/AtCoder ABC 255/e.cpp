// // 2023/07/29 20:16:41
// #ifndef DEBUG
// #pragma GCC optimize(2)
// #endif
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <cstdint>
// #include <vector>
// #include <string>
// #include <set>
// #include <map>
// #include <unordered_map>
// #include <unordered_set>
// #include <queue>
// #include <functional>
// #include <iomanip>
// #include <cmath>
// #include <stack>
// using namespace std;

// using ll = long long;
// using ull = unsigned long long;
// using pii = pair<int, int>;
// const int INF = 0x3f3f3f3f;
// const int MOD = (int)(1e9 + 7);
// const int N = 1000005;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
    
    
//     cout << endl;
//     return 0;
// }


// 2023/09/15 17:00:40
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

ll a[N], b[N], c[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a[i];
    }

    b[0] = 0;
    for (int i = 1; i < n; i++)
    {
        b[i] = a[i - 1] - b[i - 1];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> c[i];
    }

    unordered_map<ll, ll> mp;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j & 1)
            {
                mp[c[i] - b[j]]++;
            }
            else
            {
                mp[b[j] - c[i]]++;
            }
        }
    }

    ll ans = 0;
    for (auto [x, y] : mp)
    {
        ans = max(ans, y);
    }

    cout << ans << '\n';

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}