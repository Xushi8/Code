// 2023/10/22 15:04:34
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

bool check(int x, int k)
{
    string s = to_string(x);
    int cnt = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        cnt += s[i] - '0';
    }
    return cnt % k == 0;
}

void solve()
{
    int x, k;
    cin >> x >> k;
    for (int cnt = 0; cnt < 100; cnt++)
    {
        if (check(x + cnt, k))
        {
            cout << x + cnt << '\n';
            return;
        }
    }
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