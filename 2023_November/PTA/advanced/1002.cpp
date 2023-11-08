// 2023/11/07 17:21:25
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

double ans[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            int a;
            double b;
            cin >> a >> b;
            ans[a] += b;
        }
    }

    int cnt = 0;
    for (int i = 1000; i >= 0; i--)
    {
        if (ans[i] != 0.0)
        {
            cnt++;
        }
    }

    cout << setprecision(1) << fixed;
    cout << cnt;
    for (int i = 1000; i >= 0; i--)
    {
        if (ans[i] != 0.0)
        {
            cout << ' ' << i << ' ' << ans[i];
        }
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}