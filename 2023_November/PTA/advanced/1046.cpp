// 2023/11/14 21:35:00
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

    int n;
    cin >> n;
    vector<ll> sum(n + 2);
    sum[0] = sum[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        sum[i + 1] = sum[i] + x;
    }

    int q;
    cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        if (x > y)
        {
            swap(x, y);
        }

        ll a = sum[y] - sum[x];
        ll b = (sum[n + 1] - sum[y]) + (sum[x] - sum[0]);
        cout << min(a, b) << '\n';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}