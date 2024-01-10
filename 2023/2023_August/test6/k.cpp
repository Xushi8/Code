// 2023/08/04 14:58:06
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
const int N = 1000005;

char arr[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    arr[s.size() - 1] = s[s.size() - 1];
    for (int i = (int)s.size() - 2; i >= 0; i--)
    {
        arr[i] = min(s[i], arr[i + 1]);
    }

    stack<char> stk;

    for (int i = 0; i < (int)s.size(); i++)
    {
        while (!stk.empty() && stk.top() <= arr[i])
        {
            cout << stk.top();
            stk.pop();
        }
        stk.emplace(s[i]);
    }

    while (!stk.empty())
    {
        cout << stk.top();
        stk.pop();
    }
    cout << '\n';

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}