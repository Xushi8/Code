// 2024/01/10 22:31:00
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

    int n;
    while (cin >> n)
    {
        queue<char> a, b;
        for (int i = 0; i < n; i++)
        {
            char ch;
            cin >> ch;
            a.emplace(ch);
        }
        for (int i = 0; i < n; i++)
        {
            char ch;
            cin >> ch;
            b.emplace(ch);
        }

        stack<int> stk;
        vector<string> ans;

        while (!a.empty())
        {
            while (!stk.empty() && !b.empty() && stk.top() == b.front())
            {
                stk.pop();
                b.pop();
                ans.emplace_back("out");
            }
            char ch = a.front();
            a.pop();
            if (!b.empty() && ch == b.front())
            {
                ans.insert(ans.end(), {"in", "out"});
                b.pop();
            }
            else
            {
                ans.emplace_back("in");
                stk.emplace(ch);
            }
        }
        while (!stk.empty() && !b.empty() && stk.top() == b.front())
        {
            stk.pop();
            b.pop();
            ans.emplace_back("out");
        }
        if (b.empty())
        {
            cout << "Yes.\n";
            for (auto x : ans)
            {
                cout << x << '\n';
            }
            cout << "FINISH\n";
        }
        else
        {
            cout << "No.\nFINISH\n";
        }
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}