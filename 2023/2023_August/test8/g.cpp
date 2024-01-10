// 2023/08/11 10:01:57
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

void solve()
{
    int n;
    cin >> n;
    vector<string> arr(n);
    int minn = INF, pos;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (minn > (int)arr[i].size())
        {
            minn = (int)arr[i].size();
            pos = i;
        }
    }

    for (int i = minn; i >= 1; i--)
    {
        for (int j = 0; j + i - 1 < minn; j++)
        {
            string tmp = arr[pos].substr(j, i);
            string rev(tmp.rbegin(), tmp.rend());
            bool flag = 1;
            for (int k = 0; k < n; k++)
            {
                if (arr[k].find(tmp) == string::npos && arr[k].find(rev) == string::npos)
                {
                    flag = 0;
                    break;
                }
            }

            if (flag)
            {
                cout << i << '\n';
                return;
            }
        }
    }

    cout << 0 << '\n';
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
    cout << flush;
    return 0;
}