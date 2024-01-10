// 2023/10/22 19:13:47
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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int cnt[26] = {0};
    for (auto ch : s)
    {
        cnt[ch - 'a']++;
    }
    int odd = 0;
    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] & 1)
        {
            odd++;
        }
    }
    bool flag;
    if (odd == k)
        flag = 1;
    else if (odd > k + 1)
        flag = 0;
    else
        flag = 1;

    cout << (flag ? "YES\n" : "NO\n");
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