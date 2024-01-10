// 2023/12/13 19:11:56
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

    ll y, z;
    cin >> y >> z;
    ll ans = 9e18;
    // for (ll i = 100000; i < 1000000; i++)
    // {
    //     string tmp(to_string(i) + to_string(y));
    //     ll x = stoll(tmp);
    //     ll aaa = ans;
    //     ans = min(ans, abs(x - z));
    //     if (ans != aaa)
    //     {
    //         cerr << ans << ' ' << x << '\n';
    //     }
    // }

    // ll i = 0;
    // string tmp(to_string(z));
    // for (size_t j = 0; j < 4; j++)
    // {
    //     i *= 10;
    //     i += (tmp[j] - '0');
    // }
    // i *= 100000000;
    // i += y;

    // for (ll cnt = 0; cnt < 100; cnt++)
    // {
    //     ll k = i + cnt * 1000000;
    //     ans = min(ans, abs(k - z));
    //     cerr << ans << ' ' << k << endl;
    // }

    cout << ans << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}