// 2023/11/01 14:01:30
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

void solve()
{
    int n;
    cin >> n;
    for (int i = sqrt(n) + 1; i >= 1; i--)
    {
        if (n % i == 0)
        {
            int a = i;
            int b = n / i;
            if (a > b)
                continue;
            if (a * 2 >= b)
            {
                cout << 1 << '\n';
            }
            else
            {
                cout << 0 << '\n';
            }
            break;
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
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}