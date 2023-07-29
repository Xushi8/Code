// 2023/07/29 09:15:22
#ifndef DEBUG
#pragma GCC optimize(2)
#endif
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
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const int N = 1000005;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;
    while (tt--)
    {
        int n, k, x;
        cin >> n >> k >> x;
        if (x != 1)
        {
            cout << "YES\n";
            cout << n << '\n';
            while (n--)
                cout << 1 << ' ';
            cout << '\n';
            continue;
        }

        if (k == 1)
        {
            cout << "NO\n";
            continue;
        }

        if (k == 2)
        {
            if (n % 2 == 0)
            {
                cout << "YES\n";
                cout << n / 2 << '\n';
                while (n > 0)
                {
                    cout << 2 << ' ';
                    n -= 2;
                }

                cout << '\n';
                continue;
            }
            else
            {
                cout << "NO\n";
            }

            continue;
        }

        if (n == 1)
        {
            cout << "NO\n";
        }
        else
        {
            if (n & 1)
            {
                cout << "YES\n";
                n -= 3;
                cout << n / 2 + 1 << '\n';
                cout << 3 << ' ';
                while (n > 0)
                {
                    cout << 2 << ' ';
                    n -= 2;
                }
                cout << '\n';
            }
            else
            {
                cout << "YES\n";
                cout << n / 2 << '\n';
                while (n > 0)
                {
                    cout << 2 << ' ';
                    n -= 2;
                }
                cout << '\n';
            }
        }
    }

    cout << endl;
    return 0;
}