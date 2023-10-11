// 2023/10/11 21:58:39
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
    
    ll a, b, c, d, ans;
    cin >> a >> b >> c >> d;
    ans = 0;
    for (ll i = max(c + 1, a + b); i <= b + c; i++)
    {
        ans += (min(d + 1, i) - c) * (min(i - b, b) - max(i - c, a) + 1);
    }
    cout << ans << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}