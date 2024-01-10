// 2023/08/14 15:51:05
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
        int n, tar;
        cin >> n >> tar;
        int cnt[32] = { 0 };
        for (int i = 0, x; i < n; i++)
        {
            cin >> x;
            for (int j = 0; j < 30; j++)
            {
                if ((x >> j) & 1)
                {
                    cnt[j]++;
                }
            }
        }

        for (int i = 0; i < 10; i++)
        {
            cout << cnt[i] << " \n"[i == 9];
        }
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}