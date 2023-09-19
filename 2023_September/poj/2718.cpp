// 2023/09/18 09:55:48
#ifndef LOCAL
#pragma GCC optimize(2)
#endif
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <iomanip>
#include <stack>
#include <cmath>
#include <cstdlib>
using namespace std;

inline int read()
{
    int x = 0, f = 1;
    int ch = getchar();
    while (ch < '0' || ch>'9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        x = x * 10 + ch - '0', ch = getchar();
    return x * f;
}

typedef long long ll;
typedef pair<int, int> pii;
const int N = 15;




int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;
    cin.get();
    while (tt--)
    {
        int n, arr[15];
        int ch;
        int tot = 0;
        int now = 0;
        while (1)
        {
            while ((ch = cin.get()) && !isspace(ch))
            {
                now = now * 10 + ch - '0';
            }

            arr[tot++] = now;
            now = 0;
            if (ch == '\n' || ch == '\r')
                break;
        }

        int ans = 0x3f3f3f3f;
        n = tot;
        int mid = n / 2;
        do
        {
            if (arr[0] == 0 || arr[mid] == 0)
                continue;

            int a = 0, b = 0;
            for (int i = 0; i < mid; i++)
            {
                a = a * 10 + arr[i];
            }
            for (int i = mid; i < n; i++)
            {
                b = b * 10 + arr[i];
            }
            ans = min(ans, abs(a - b));
        } while (next_permutation(arr, arr + n));
        if (n == 2)
            ans = abs(arr[0] - arr[1]);
        cout << ans << '\n';

        // for (int i = 0; i < n; i++)
        // {
        //     cerr << arr[i] << ' ';
        // }
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}