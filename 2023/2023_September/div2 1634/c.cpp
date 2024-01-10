// 2023/09/05 20:28:53
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
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 1000005;

void solve()
{
    int n, k;
    cin >> n >> k;
    if (k == 1)
    {
        cout << "YES\n";
        for (int i = 1; i <= n * k; i++)
        {
            cout << i << '\n';
        }
    }
    else
    {
        if (n % 2 == 1)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
            int a = 1, b = 2;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < k; j++)
                {
                    if (i & 1)
                    {
                        cout << b << ' ';
                        b += 2;
                    }
                    else
                    {
                        cout << a << ' ';
                        a += 2;
                    }
                }
                cout << '\n';
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tt;
    cin >> tt;
    while (tt--)
    {
        solve();
    }

    int a = 0b1100'0101;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}