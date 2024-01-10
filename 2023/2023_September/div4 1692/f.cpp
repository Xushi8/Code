// 2023/09/17 16:06:36
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
    int n;
    cin >> n;
    int wei[10] = { 0 };
    for (int i = 0, x; i < n; i++)
    {
        cin >> x;
        wei[x % 10]++;
    }

    for (int i = 0; i < 10; i++)
    {
        if (wei[i] == 0)
            continue;
        wei[i]--;

        for (int j = i; j < 10; j++)
        {
            if (wei[j] == 0)
                continue;
            wei[j]--;

            for (int k = j; k < 10; k++)
            {
                if (wei[k] == 0)
                    continue;

                if ((i + j + k) % 10 == 3)
                {
                    cout << "YES\n";
                    return;
                }
            }

            wei[j]++;
        }

        wei[i]++;
    }
    cout << "NO\n";
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