// 2023/10/27 10:15:58
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

bool check(string s, string a)
{
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] < a[i])
            return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;
    string a = "9223372036854775807";
    string b = "-9223372036854775808";
    if (s.front() == '-')
    {
        if (s.substr(1).size()  > b.substr(1).size() || check(s.substr(1), b.substr(1)))
        {
            // cerr << s << '\n' << s.substr(1) << '\n' << b.substr(1) << '\n';
            cout << "BigInteger\n";
            return 0;
        }
    }
    else
    {
        if (s.size() > a.size() || check(s, a))
        {
            cout << "BigInteger\n";
            return 0;
        }
    }

    ll tmp = stoll(s);

    if (-128 <= tmp && tmp <= 127)
        cout << "byte\n";
    else if (-32768 <= tmp && tmp <= 32767)
        cout << "short\n";
    else if (-2147483648 <= tmp && tmp <= 2147483647)
        cout << "int\n";
    else
        cout << "long\n";

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}