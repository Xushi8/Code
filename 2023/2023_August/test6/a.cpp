// 2023/08/03 14:06:04
#ifndef LOCAL
#pragma GCC optimize(2)
#endif
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
const int N = 300005;

int arr[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;

    if (n & 1)
    {
        cout << ":(\n";
    }
    else
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
                cnt++;
        }

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '?')
            {
                if (cnt < n / 2)
                {
                    s[i] = '(';
                    cnt++;
                }
                else
                {
                    s[i] = ')';
                }
            }
        }

        stack<char> stk;
        bool flag = 1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
                stk.emplace('(');
            else
            {
                if (stk.empty())
                {
                    flag = 0;
                    break;
                }

                stk.pop();

                if (stk.empty() && i != n - 1)
                {
                    flag = 0;
                    break;
                }
            }
        }

        if (!flag || !stk.empty())
        {
            cout << ":(\n";
        }
        else
        {
            cout << s << '\n';
        }
    }



#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}