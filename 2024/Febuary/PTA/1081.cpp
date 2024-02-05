// 2024/02/04 16:39:27
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
#include <numeric>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 1000005;
#define int long long

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<array<int, 3>> a(n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        char ch;
        cin >> x >> ch >> y;
        if (x >= 0)
            a[i][2] = 1;
        else
            a[i][2] = -1;
        a[i][0] = abs(x);
        a[i][1] = y;
    }

    int gong = 1;
    for (auto [x, y, z] : a)
    {
        gong = lcm(gong, y);
    }

    for (auto& [x, y, z] : a)
    {
        x *= gong / y;
        y = gong;
    }

    int zi = 0;
    int mu = gong;
    for (auto [x, y, z] : a)
    {
        zi += x * z;
    }

    int yue = gcd(zi, mu);
    zi /= yue;
    mu /= yue;
    int zheng = zi / mu;
    if (zheng != 0 && zi % mu != 0)
        cout << zheng << ' ' << zi % mu << '/' << mu << endl;
    else if (zheng == 0 && zi % mu != 0)
        cout << zi % mu << '/' << mu << endl;
    else if(zheng != 0 && zi % mu == 0)
        cout << zheng << endl;
    else
        cout << 0 << endl;

#ifdef LOCAL
                cerr
             << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}