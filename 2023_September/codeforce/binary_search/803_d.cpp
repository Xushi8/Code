// 2023/10/04 18:28:05
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
    
    size_t k;
    string s;
    cin >> k;
    cin.get();
    getline(cin, s);

    auto check = [&](size_t val) -> bool
        {
            size_t rows = 0;
            size_t now = 0;
            for (size_t i = 0, j; i < s.size(); i++)
            {
                for (j = i; j < s.size(); j++)
                {
                    if (s[j] == ' ' || s[j] == '-')
                        break;
                }

                if (j != s.size())
                    j++;

                now += j - i;
                if (now > val)
                {
                    now -= j - i;
                    rows++;
                    if (now == 0 || j - i > val)
                        return false;
                    now = j - i;
                }

                i = j - 1;
            }

            if (now != 0)
                rows++;

            return rows <= k;
        };

    int l = 1, r = int(s.size());
    int ans = 1;
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