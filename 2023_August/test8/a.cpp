// 2023/08/10 08:38:04
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

void solve(const string& s)
{
    int len = (int)s.size();
    for (int i = 1; i <= len; i++)
    {
        if (len % i != 0)
            continue;

        bool flag = 1;
        for (int j = 0; j < i; j++)
        {
            for (int k = j; k < len - i; k += i)
            {
                if (s[k] != s[k + i])
                {
                    flag = 0;
                    goto out;
                }
            }
        }

    out:
        if (flag)
        {
            cout << len / i << '\n';
            return;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    while (cin >> s && s[0] != '.')
    {
        solve(s);
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}