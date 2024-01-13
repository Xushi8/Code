// 2024/01/12 13:59:15
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
constexpr int N = 100005;

int a[N], f[__lg(N) + 1][N];

int query(int l, int r) {
    int mid = __lg(r - l + 1);
    return __gcd(f[mid][l], f[mid][r - (1 << mid) + 1]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++)
    {
        f[0][i] = a[i];
    }

    for (int i = 1; i <= __lg(n); i++)
    {
        for (int j = i + 1; j + (1 << i) - 1 <= n; j++)
        {
            f[i][j] = __gcd(f[i - 1][j], f[i - 1][j + (1 << (i - 1))]);
        }
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}