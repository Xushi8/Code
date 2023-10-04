// 2023/10/04 21:36:21
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
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 1000005;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    string s;
    cin >> n >> s;

    auto check = [&](int tim) -> bool
        {
            int pos = -1, lst = -1;
            for (int i = 0; i < n; i++)
            {
                if (s[i] == '*')
                {
                    if (pos == -1 && lst < i)
                        pos = i;
                }
                else if (s[i] == 'P')
                {
                    if (pos == -1)
                        lst = i + tim;
                    else if (i - pos > tim)
                        return false;
                    else
                        lst = max({lst, i + (tim - (i - pos) * 2), i + (tim - (i - pos)) / 2}), pos = -1;
                }
            }
            return pos == -1;
        };

    int l = 1, r = int(s.size()) * 2, ans = r;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (check(mid))
            ans = mid, r = mid - 1;
        else
            l = mid + 1;
    }

    cout << ans << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}