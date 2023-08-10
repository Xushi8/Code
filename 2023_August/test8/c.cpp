// 2023/08/10 15:33:12
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
    
    set<string> a, b;
    int n;
    cin >> n;
    string s;
    while (n--)
    {
        cin >> s;
        a.emplace(s);
    }
    cin >> n;
    while (n--)
    {
        cin >> s;
        if (a.count(s) == 0)
        {
            cout << "WRONG\n";
        }
        else
        {
            if (b.count(s) != 0)
            {
                cout << "REPEAT\n";
            }
            else
            {
                cout << "OK\n";
                b.emplace(s);
            }
        }
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}