// 2023/07/27 15:40:21
// #pragma GCC optimize(2)
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
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const int N = 2200005;

ull now_sum[N];
int qianzhui[N];

int get_num(ll n)
{
    int ret = 0;
    while (n > 0)
    {
        ret += (int)(n % 10);
        n /= 10;
    }

    return ret;
}

int func(int l, int r)
{
    int a, b;
    l--;
    if (l % 3 == 0 || l % 3 == 1)
        a = l / 3 * 2;
    else
        a = l / 3 * 2 + 1;

    if (r % 3 == 0 || r % 3 == 1)
        b = r / 3 * 2;
    else
        b = r / 3 * 2 + 1;

    return b - a;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    // ull sum = 0;
    // int now_ans = 0;
    // for (ll i = 1; i < 1000; i++)
    // {
    //     int tmp = get_num(i);
    //     sum += tmp;
    //     if (sum % 3 == 0)
    //         now_ans++;

    //     cout << i << ' ' << now_ans << ' ' << sum << '\n';
    // }

    int tt;
    cin >> tt;
    int Case = 1;
    while (tt--)
    {
        int l, r;
        cin >> l >> r;
        cout << "Case " << Case++ << ": " << func(l, r) << '\n';
    }

    cout << flush;
    return 0;
}