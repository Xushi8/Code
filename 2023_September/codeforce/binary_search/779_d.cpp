// 2023/10/05 18:19:58
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
    
    string s1, s2;
    cin >> s1 >> s2;
    vector<int> arr(s1.size());
    for (size_t i = 0; i < s1.size(); i++)
    {
        cin >> arr[i];
        arr[i]--;
    }

    auto check = [&](int val) -> bool
        {
            vector<bool> dec(s1.size(), 0);
            for (int i = 0; i < val; i++)
            {
                dec[arr[i]] = 1;
            }

            size_t tot = 0;
            for (size_t i = 0; i < s1.size(); i++)
            {
                if (dec[i])
                    continue;
                if (tot < s2.size() && s2[tot] == s1[i])
                    tot++;
            }

            return tot == s2.size();
        };

    int l = 0, r = int(s1.size()), ans = 0;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (check(mid))
            ans = mid, l = mid + 1;
        else
            r = mid - 1;
    }

    cout << ans << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}