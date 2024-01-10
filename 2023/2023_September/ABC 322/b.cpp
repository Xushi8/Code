// 2023/09/30 20:02:52
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
    
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;

    auto check1 = [&](string s, string t) ->bool
        {
            for (int i = 0; i < n; i++)
            {
                if (s[i] != t[i])
                    return false;
            }
            return true;
        };
    auto check2 = [&](string s, string t) ->bool
        {
            for (int i = m - n, j = 0; j < n; j++, i++)
            {
                if (s[j] != t[i])
                    return false;
            }
            return true;
        };

    bool ans1 = check1(s, t);
    bool ans2 = check2(s, t);
    if (ans1 && ans2)
        cout << 0;
    if (ans1 && !ans2)
        cout << 1;
    if (!ans1 && ans2)
        cout << 2;
    if (!ans1 && !ans2)
        cout << 3;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}