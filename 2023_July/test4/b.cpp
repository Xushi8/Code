// 2023/07/27 14:47:15
#pragma GCC optimize(2)
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
const int N = 5000005;

double arr[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    double sum = 0.0;
    for (int i = 1; i <= 100000000; i++)
    {
        sum += 1.0 / i;
        if (i % 20 == 0)
        {
            arr[i / 20] = sum;
        }
    }

    cout << setprecision(10) << fixed;
    double ans;
    int tt;
    cin >> tt;
    int Case = 1;
    while (tt--)
    {
        int m;
        cin >> m;
        ans = arr[m / 20];
        for (int i = m - (m % 20) + 1, j = 0; j < m % 20; i++, j++)
        {
            ans += 1.0 / i;
        }
        cout << "Case " << Case++ << ": " << ans << '\n';
    }

    cout << flush;
    return 0;
}