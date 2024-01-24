// 2024/01/23 20:13:39
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

    int h, w, r, c;
    cin >> h >> w >> r >> c;
    int ans = 0;
    // if (r - 1 >= 1 && c - 1 >= 1)
    //     ans++;
    // if (r - 1 >= 1 && c + 1 <= w)
    //     ans++;
    // if (r + 1 <= h && c - 1 >= 1)
    //     ans++;
    // if (r + 1 <= h && c + 1 <= w)
    //     ans++;
    if (r - 1 >= 1)
        ans++;
    if (c - 1 >= 1)
        ans++;
    if (r + 1 <= h)
        ans++;
    if (c + 1 <= w)
        ans++;
    cout << ans << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}