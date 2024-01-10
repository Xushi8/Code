// 2023/11/16 21:24:08
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
constexpr int N = 10005;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    stack<int> stk;
    multiset<int> st1, st2;

    int q;
    cin >> q;
    while (q--)
    {
        string s;
        cin >> s;
        if (s == "Pop")
        {
            if (stk.empty())
            {
                cout << "Invalid\n";
            }
            else
            {
                int x = stk.top();
                stk.pop();
                cout << x << '\n';
                auto it = st1.find(x);
                if (it != st1.end())
                {
                    st1.erase(it);
                }
                else
                {
                    st2.erase(st2.find(x));
                }

                while (st1.size() >= st2.size() + 2)
                {
                    auto it = --st1.end();
                    st2.emplace(*it);
                    st1.erase(it);
                }

                while (st1.size() < st2.size())
                {
                    auto it = st2.begin();
                    st1.emplace(*it);
                    st2.erase(it);
                }
            }
        }
        else if (s == "PeekMedian")
        {
            if (stk.empty())
            {
                cout << "Invalid\n";
            }
            else
            {
                cout << *--st1.end() << '\n';
            }
        }
        else
        {
            int x;
            cin >> x;
            stk.emplace(x);
            if (st1.empty() || x <= *--st1.end())
            {
                st1.emplace(x);
            }
            else
            {
                st2.emplace(x);
            }
            while (st1.size() >= st2.size() + 2)
            {
                auto it = --st1.end();
                st2.emplace(*it);
                st1.erase(it);
            }

            while (st1.size() < st2.size())
            {
                auto it = st2.begin();
                st1.emplace(*it);
                st2.erase(it);
            }
        }
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}