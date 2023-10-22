// 2023/10/22 19:03:53
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
    
    int tt;
    cin >> tt;
    while (tt--)
    {
        string s;
        cin >> s;
        for (auto& ch : s)
        {
            if (ch == '0')
                ch += 10;
        }
        
        int ans = 0;
        ans += s[0] - '0';
        ans += abs(s[1] - s[0]) + 1;
        ans += abs(s[2] - s[1]) + 1;
        ans += abs(s[3] - s[2]) + 1;
        cout << ans << '\n';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}