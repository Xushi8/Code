// 2024/01/16 16:46:45
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
        size_t n = s.size();
        if (s == "ikimasu")
        {
            cout << "itte\n";
            continue;
        }

        string s1 = s.substr(n - 6);
        if (s1 == "rimasu")
        {
            s.erase(s.end() - 6, s.end());
            s.append("tte");
            cout << s << '\n';
            continue;
        }

        if (s1 == "mimasu" || s1 == "bimasu" || s1 == "nimasu")
        {
            s.erase(s.end() - 6, s.end());
            s.append("nde");
            cout << s << '\n';
            continue;
        }

        if (s1 == "kimasu")
        {
            s.erase(s.end() - 6, s.end());
            s.append("ite");
            cout << s << '\n';
            continue;
        }

        if (s1 == "gimasu")
        {
            s.erase(s.end() - 6, s.end());
            s.append("ide");
            cout << s << '\n';
            continue;
        }

        s1 = s.substr(n - 7);

        if (s1 == "shimasu")
        {
            s.erase(s.end() - 7, s.end());
            s.append("shite");
            cout << s << '\n';
            continue;
        }

        s.erase(s.end() - 7, s.end());
        s.append("tte");
        cout << s << '\n';
        continue;
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << '\n';
#endif
    return 0;
}