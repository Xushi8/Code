// 2023/07/18 23:10:41
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
#include <bitset>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const int N = 1000005;

int n;
int bit[N];

void add(int i, int x)
{
    while (i <= n)
    {
        bit[i] += x;
        i += i & -i;
    }
}

void add(int x)
{
    while (x <= n)
    {
        bit[x]++;
        x += x & -x;
    }
}

ll sum(int i)
{
    ll ret = 0;
    while (i > 0)
    {
        ret += bit[i];
        i -= i & -i;
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        add(x);
        ans += i - sum(x);
    }

    cout << ans << '\n';

    cout << endl;
    return 0;
}