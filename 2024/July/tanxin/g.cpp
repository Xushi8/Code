// 2024/07/29 20:41:17
#ifdef LOCAL
#include <basic_std_lib.h>
#else
#include <bits/stdc++.h>
#endif
using namespace std;

void solve();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    tt = 1;
    while (tt--)
    {
        solve();
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}

using i64 = int64_t;
using u64 = uint64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 1000005;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n % 2 == 1)
    {
        cout << ":(" << '\n';
        return;
    }

    int cnt = std::count(s.begin(), s.end(), '(');
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '?')
        {
            if (cnt < n / 2)
                s[i] = '(', cnt++;
            else
                s[i] = ')';
        }
    }

    // check
    stack<char> stk;
    for (int i = 0; i < n; i++)
    {
        char ch = s[i];
        if (ch == '(')
            stk.emplace(ch);
        else
        {
            if (stk.empty())
            {
                cout << ":(" << '\n';
                return;
            }
            stk.pop();

            if (stk.empty() && i != n - 1)
            {
                cout << ":(" << '\n';
                return;
            }
        }
    }

    if (!stk.empty())
    {
        cout << ":(" << '\n';
        return;
    }

    cout << s << '\n';
}