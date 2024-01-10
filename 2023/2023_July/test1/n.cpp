// 2023/07/18 10:22:15
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
#include <bitset>

using namespace std;

int GCD[100005][21];

int query(int l, int r)
{
    int mid = __lg(r - l + 1);
    return __gcd(GCD[l][mid], GCD[r - (1 << mid) + 1][mid]);
}

int binary_find(int l, int r, int begin_pos, int now_gcd)
{
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (query(begin_pos, mid) == now_gcd)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    return r;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> GCD[i][0];
    }

    for (int j = 1; j <= 20; j++)
    {
        for (int i = 1; i - 1 + (1 << j) <= n; i++)
        {
            GCD[i][j] = __gcd(GCD[i][j - 1], GCD[i + (1 << (j - 1))][j - 1]);
        }
    }

    map<int, long long> m;
    int now_gcd, pos;
    int pre_pos;
    for (int i = 1; i <= n; i++)
    {
        pos = i;
        now_gcd = GCD[i][0];
        while (1)
        {
            pre_pos = pos;
            pos = binary_find(pos, n, i, now_gcd);
            // now_gcd = query(i, pos);
            m[now_gcd] += pos - pre_pos + 1;
            if (pos < n)
            {
                now_gcd = query(i, ++pos);
            }
            else
            {
                break;
            }
        }
    }

    int tt;
    cin >> tt;
    while (tt--)
    {
        int x;
        cin >> x;
        cout << m[x] << '\n';
    }

    cout << flush;
    return 0;
}