// 2023/11/07 18:36:34
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    bool flag = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] >= 0)
        {
            flag = 0;
        }
    }

    if (flag)
    {
        cout << 0 << ' ' << a.front() << ' ' << a.back();
    }
    else
    {
        int maxn = -1;
        int l = 0, r = 0, nl = 0, nr = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cnt += a[i];
            if (cnt > maxn)
            {
                maxn = cnt;
                nr = i;
                l = nl;
                r = nr;
            }
            if (cnt < 0)
            {
                cnt = 0;
                nl = i + 1;
                nr = i + 1;
            }
        }

        cout << maxn << ' ' << a[l] << ' ' << a[r];
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}