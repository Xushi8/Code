// 2023/07/18 00:37:02
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

ll bit[N];
int n;

ll sum(int i)
{
    ll sum = 0;
    while (i > 0)
    {
        sum += bit[i];
        i -= i & -i;
    }
    return sum;
}

void add(int i, int x)
{
    while (i <= n)
    {
        bit[i] += x;
        i += i & -i;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tt;
    cin >> n >> tt;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        add(i, x);
    }

    while (tt--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
        {
            add(b, c);
        }
        else
        {
            cout << sum(c) - sum(b - 1) << '\n';
        }
    }

    cout << '\n';
    return 0;
}