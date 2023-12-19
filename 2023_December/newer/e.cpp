// 2023/12/13 19:50:14
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
    cin >> s;
    for (char& x : s)
    {
        x -= '0';
    }
    string s1(s), s2(s);
    ll ans1 = 0;
    for (size_t i = 1; i < s1.size(); i++)
    {
        if (s1[i] == s1[i - 1])
        {
            ans1 += i + 1;
            s1[i] = !s1[i];
        }
    }

    ll ans2 = 0;
    s2[0] = !s2[0];
    ans2 += 1;
    for (size_t i = 1; i < s2.size(); i++)
    {
        if (s2[i] == s2[i - 1])
        {
            ans2 += i + 1;
            s2[i] = !s2[i];
        }
    }

    cout << min(ans1, ans2) << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}