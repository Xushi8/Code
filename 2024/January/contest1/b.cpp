// 2024/01/10 22:47:22
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

    string s;
    int cnt = 1;
    while (cin >> s && s[0] != '-')
    {
        stack<char> stk;
        int ans = 0;
        for (char ch : s)
        {
            if (ch == '{')
            {
                stk.emplace(ch);
            }
            else if (ch == '}')
            {
                if (!stk.empty() && stk.top() == '{')
                {
                    stk.pop();
                }
                else
                {
                    stk.emplace('{');
                    ans++;
                }
            }
        }
        ans += stk.size() / 2;
        cout << cnt++ << '.' << ' ' << ans << '\n';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}