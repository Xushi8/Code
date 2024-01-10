// 2023/08/12 20:39:13
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
    
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> tim(n, 0);
    int now = 0;
    int tt;
    cin >> tt;
    vector<int> ope;
    while (tt--)
    {
        int op, i;
        char ch;
        cin >> op >> i >> ch;
        i--;
        if (op == 1)
        {
            s[i] = ch;
            tim[i] = now;
        }
        else if (op == 2)
        {
            ope.emplace_back(2);
            now++;
        }
        else
        {
            ope.emplace_back(3);
            now++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (tim[i] != now)
        {
            if (!ope.empty())
            {
                if (ope.back() == 2)
                    s[i] = tolower(s[i]);
                else
                    s[i] = toupper(s[i]);
            }
        }
    }

    cout << s << '\n';

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}