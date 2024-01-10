// 2023/08/02 10:45:54
#ifndef LOCAL
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
const int N = 105;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;
        int odd = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            odd += (x & 1);
        }

        int even = n - odd;
        if (odd % 4 == 2)
        {
            cout << "Bob\n";
        }
        else if (odd % 4 == 3)
        {
            cout << "Alice\n";
        }
        else if (odd % 4 == 0)
        {
            cout << "Alice\n";
        }
        else
        {
            if (even & 1)
                cout << "Alice\n";
            else
                cout << "Bob\n";
        }
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}