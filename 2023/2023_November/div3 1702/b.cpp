// 2023/11/21 16:30:09
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

void solve()
{
    string s;
    cin >> s;
    size_t i = 0;
    int ans = 0;
    while (i != s.size())
    {
        ans++;
        set<char> st;
        for (; i < s.size(); i++)
        {
            if (st.size() < 3 || (st.size() == 3 && st.count(s[i]) == 1))
            {
                st.emplace(s[i]);
            }
            else
            {
                break;
            }
        }
    }

    cout << ans << '\n';
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
    cout << endl;
    return 0;
}