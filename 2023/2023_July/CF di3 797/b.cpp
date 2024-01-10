// 2023/07/15 16:27:51
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
const int N = 1000005;

int a[N], b[N];

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
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];

        int target = INF;
        for (int i = 0; i < n; i++)
        {
            if (b[i] != 0)
            {
                target = a[i] - b[i];
            }
        }

        if (target != INF && target < 0)
        {
            cout << "NO\n";
            continue;
        }

        bool flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] - b[i] != target)
            {
                if (b[i] == 0)
                {
                    if (a[i] - b[i] > target)
                    {
                        flag = 1;
                        break;
                    }
                }
                else
                {
                    flag = 1;
                    break;
                }
            }
        }

        cout << (flag ? "NO\n" : "YES\n");
    }

    cout << endl;
    return 0;
}