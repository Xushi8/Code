// 2023/08/18 12:24:28
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
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const int N = 1000005;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    getline(cin, s);
    int a = -1, b = -1, c = -1;
    string sa, sb, sc;
    for (int i = 0; i < (int)s.size(); i++)
    {
        char ch = s[i];
        if (ch == '+')
        {
            a = i;
        }
        else if (ch == '=')
        {
            b = i;
        }
    }

    sa = s.substr(0, a - 1);
    sb = s.substr(a + 2, b - a - 3);
    sc = s.substr(b + 2);

    a = stoi(sa);
    b = stoi(sb);
    c = stoi(sc);
    if (a + b == c)
    {
        cout << "Yes\n";
        cout << a << " + " << b << " = " << c << endl;
        return 0;
    }

    for (int i = 0; i <= (int)sa.size(); i++)
    {
        auto it = sa.begin();
        for (char j = '0'; j <= '9'; j++)
        {
            if (i == 0 && j == '0')
                continue;

            sa.insert(it + i, j);
            a = stoi(sa);
            b = stoi(sb);
            c = stoi(sc);
            if (a + b == c)
            {
                cout << "Yes\n";
                cout << a << " + " << b << " = " << c << endl;
                return 0;
            }
            
            sa.erase(it + i);
        }
    }

    for (int i = 0; i <= (int)sb.size(); i++)
    {
        auto it = sb.begin();
        for (char j = '0'; j <= '9'; j++)
        {
            if (i == 0 && j == '0')
                continue;

            sb.insert(it + i, j);
            a = stoi(sa);
            b = stoi(sb);
            c = stoi(sc);
            if (a + b == c)
            {
                cout << "Yes\n";
                cout << a << " + " << b << " = " << c << endl;
                return 0;
            }

            sb.erase(it + i);
        }
    }

    for (int i = 0; i <= (int)sc.size(); i++)
    {
        auto it = sc.begin();
        for (char j = '0'; j <= '9'; j++)
        {
            if (i == 0 && j == '0')
                continue;

            sc.insert(it + i, j);
            a = stoi(sa);
            b = stoi(sb);
            c = stoi(sc);
            if (a + b == c)
            {
                cout << "Yes\n";
                cout << a << " + " << b << " = " << c << endl;
                return 0;
            }

            sc.erase(it + i);
        }
    }


    cout << "No\n";

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}