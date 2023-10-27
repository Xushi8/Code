// 2023/10/27 10:36:24
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
constexpr int N = 65;

ll c[N][N];

void init()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (!j) c[i][j] = 1;
            else c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n, m, t;
    cin >> n >> m >> t;
    init();

    ll ans = 0;
    for (int a = 4; a <= n; a++)
    {
        int b = t - a;
        if (b < 1)
            break;

        ans += c[n][a] * c[m][b];
    }
    cout << ans << '\n';

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}