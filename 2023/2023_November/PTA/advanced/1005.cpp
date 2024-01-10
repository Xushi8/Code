// 2023/11/07 18:18:08
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

const string s[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string a;
    cin >> a;
    int ans = 0;
    for (char ch : a)
    {
        ans += ch - '0';
    }

    stack<int> stk;
    while (ans)
    {
        stk.emplace(ans % 10);
        ans /= 10;
    }

    if (stk.empty())
    {
        cout << s[0];
    }
    else
    {
        cout << s[stk.top()];
        stk.pop();
        while (!stk.empty())
        {
            cout << ' ' << s[stk.top()];
            stk.pop();
        }
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}