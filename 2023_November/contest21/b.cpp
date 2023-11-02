// 2023/11/01 14:36:47
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdint>
#include <iterator>
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

int get_nuber(const string& str)
{
    stack<int> num;
    stack<char> s;
    char ch;
    for (size_t i = 0; i < str.size(); i++)
    {
        ch = str[i];
        int tot = -1;
        while (isdigit(ch))
        {
            if (tot == -1)
                tot = 0;
            tot *= 10;
            tot += ch - '0';
            if (i + 1 < str.size())
                ch = str[++i];
            else
                ch = ' ';
        }
        if (tot != -1)
            num.emplace(tot);

        if (ch == ' ')
            continue;

        if (ch == '*' || ch == '/')
        {
            if (s.empty())
            {
                s.emplace(ch);
            }
            else
            {
                while (!s.empty() && (s.top() == '/' || s.top() == '*'))
                {
                    char tmp = s.top();
                    s.pop();
                    int b = num.top();
                    num.pop();
                    int a = num.top();
                    num.pop();
                    int ans;
                    if (tmp == '*')
                        ans = a * b;
                    else if (tmp == '/')
                        ans = a / b;
                    num.emplace(ans);
                }
                s.emplace(ch);
            }
        }
        else if (ch == '+' || ch == '-')
        {
            if (s.empty())
            {
                s.emplace(ch);
            }
            else
            {
                while (!s.empty())
                {
                    char tmp = s.top();
                    s.pop();
                    int b = num.top();
                    num.pop();
                    int a = num.top();
                    num.pop();
                    int ans;
                    if (tmp == '*')
                        ans = a * b;
                    else if (tmp == '/')
                        ans = a / b;
                    else if (tmp == '+')
                        ans = a + b;
                    else if (tmp == '-')
                        ans = a - b;
                    num.emplace(ans);
                }
                s.emplace(ch);
            }
        }
    }

    while (!s.empty())
    {
        char tmp = s.top();
        s.pop();
        int b = num.top();
        num.pop();
        int a = num.top();
        num.pop();
        int ans;
        if (tmp == '+')
            ans = a + b;
        else if (tmp == '-')
            ans = a - b;
        else if (tmp == '*')
            ans = a * b;
        else if (tmp == '/')
            ans = a / b;
        num.emplace(ans);
    }

    return num.top();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int arr[4];
    for (int i = 0; i < 4; i++)
    {
        cin >> arr[i];
    }

    set<int> st;
    int fuhao[9] = {0, 0, 0, 1, 1, 1, 2, 2, 2};
    sort(arr, arr + 4);

    do
    {
        do
        {
            int a, b, c, d;
            // 1 + 1 + 1 + 1    3
            a = arr[0], b = arr[1], c = arr[2], d = arr[3];
            char f[3];
            for (int i = 0; i < 3; i++)
            {
                f[i] = fuhao[i];
                if (f[i] == 0)
                    f[i] = '+';
                else if (f[i] == 1)
                    f[i] = '-';
                else
                    f[i] = '*';
            }

            string s;
            s.clear();
            s += to_string(a) + f[0] + to_string(b) + f[1] + to_string(c) + f[2] + to_string(d);
            a = get_nuber(s);

            st.emplace(abs(a));

            // 2 + 1 + 1        2

            a = arr[0] * 10 + arr[1];
            b = arr[2];
            c = arr[3];

            s.clear();
            s += to_string(a) + f[0] + to_string(b) + f[1] + to_string(c);
            a = get_nuber(s);

            st.emplace(abs(a));

            // 3 + 1 || 2 + 2   1
            a = arr[0] * 100 + arr[1] * 10 + arr[2];
            b = arr[3];

            s.clear();
            s += to_string(a) + f[0] + to_string(b);
            a = get_nuber(s);

            st.emplace(abs(a));

            a = arr[0] * 10 + arr[1];
            b = arr[2] * 10 + arr[3];

            s.clear();
            s += to_string(a) + f[0] + to_string(b);
            a = get_nuber(s);

            st.emplace(abs(a));

        } while (next_permutation(fuhao, fuhao + 9));
    } while (next_permutation(arr, arr + 4));

    cout << st.size() << endl;

    // for (auto x : st)
    // {
    //     cout << x << ' ';
    // }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}