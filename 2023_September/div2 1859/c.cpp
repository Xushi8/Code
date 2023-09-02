// 2023/09/01 18:34:40
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

int ans[N];

void init()
{
    for (int n = 2; n < 255; n++)
    {
        for (int j = n - 1; j >= 1; j--)
        {
            int maxn = 0;
            int now = 0;
            for (int k = 1; k < j; k++)
            {
                now += k * k;
                maxn = max(maxn, k * k);
            }
            int m = n;
            for (int k = j; k <= n; k++)
            {
                now += k * m;
                maxn = max(maxn, k * m);
                m--;
            }

            ans[n] = max(ans[n], now - maxn);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    init();

    int tt;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;
        cout << ans[n] << '\n';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}