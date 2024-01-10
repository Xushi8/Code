// 2023/07/30 13:04:46
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
        int n, m;
        cin >> n >> m;
        int c = m / n;
        for (int i = (int)sqrt(c); i >= 1; i--)
        {
            if (c % i != 0)
                continue;

            int A = i, B = c / i;
            if (__gcd(A, B) == 1)
            {
                cout << (A + B) * n << '\n';
                break;
            }
        }
    }

    cout << endl;
    return 0;
}