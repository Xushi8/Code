// 2024/07/29 22:14:28
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
    cin >> tt;
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
    string s;
    cin >> s;
    cerr << s << ' ';
    if (s.size() == 1) // 只有一位数字
    {
        cout << s << '\n';
        return;
    }

    if (s[0] == '1')
    {
        // 1000
        if (count(s.begin() + 1, s.end(), '0') + 1 == s.size())
        {
            int cnt = s.size() - 1;
            while (cnt--)
                cout << '9';
            cout << '\n';
            return;
        }

        // 1003
        if (count(s.begin() + 1, s.end() - 1, '0') + 2 == s.size() && s.back() != '0')
        {
            cout << s << '\n';
            return;
        }

        int pos;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] != '0')
            {
                pos = i;
                break;
            }
        }

        // 100199
        if (count(s.begin() + pos + 1, s.end(), '9') + pos + 1 == s.size())
        {
            cout << s << '\n';
            return;
        }

        // 100134
        for (int i = 0; i < pos; i++)
            cout << s[i];
        cout << char(s[pos] - 1);
        int cnt = s.size() - pos - 1;
        while (cnt--)
        {
            cout << '9';
        }
        cout << '\n';
        return;
    }

    // 2999
    if (count(s.begin() + 1, s.end(), '9') + 1 == s.size())
    {
        cout << s << '\n';
        return;
    }

    // 292399
    cout << char(s[0] - 1);
    int cnt = s.size() - 1;
    while (cnt--)
    {
        cout << '9';
    }
    cout << '\n';
}