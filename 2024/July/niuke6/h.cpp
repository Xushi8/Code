// // 2024/08/01 12:12:06
// #ifdef LOCAL
// #include <basic_std_lib.h>
// #else
// #include <bits/stdc++.h>
// #endif
// using namespace std;

// void solve();

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int tt;
//     tt = 1;
//     cin >> tt;
//     while (tt--)
//     {
//         solve();
//     }

// #ifdef LOCAL
//     cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
// #endif
//     return 0;
// }

// using i64 = int64_t;
// using u64 = uint64_t;
// using pii = pair<int, int>;
// using pll = pair<i64, i64>;
// constexpr int N = 1000005;

// void solve()
// {
//     string s;
//     cin >> s;
//     int n = s.size();
//     int cnt;
//     cnt = 0;

//     // 3
//     for (int i = 0; i < min(10, n); i++)
//     {
//         cnt += s[i] == '3';
//     }
//     for (int i = 10; i < n; i++)
//     {
//         if (cnt == 10)
//         {
//             cout << "invalid" << '\n';
//             return;
//         }
//         cnt -= s[i - 10] == '3';
//         cnt += s[i] == '3';
//     }
//     if (cnt == 10)
//     {
//         cout << "invalid" << '\n';
//         return;
//     }

//     cnt = 0;
//     for (int i = 0; i < min(90, n); i++)
//     {
//         cnt += s[i] == '5' || s[i] == 'U';
//     }
//     for (int i = 90; i < n; i++)
//     {
//         cnt -= s[i - 90] == '5' || s[i - 90] == 'U';
//         cnt += s[i] == '5' || s[i] == 'U';
//         if (cnt == 0)
//         {
//             cout << "invalid" << '\n';
//             return;
//         }
//     }
// }

// 2024/07/30 14:51:08

#include <bits/stdc++.h>
using namespace std;

void solve();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;
    while (tt--)
    {
        solve();
    }
    return 0;
}
string s;
void solve()
{
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] == '3')
        {
            cnt++;
        }
        else
        {
            cnt = 0;
        }
        if (cnt == 10)
        {
            cout << "invalid" << endl;
            return;
        }
    }
    cnt = 0;
    for (int i = 0; i < (int)s.size(); i++)
    {
        cnt++;
        if (s[i] == 'U' || s[i] == '5')
        {
            cnt = 0;
        }
        if (cnt == 90)
        {
            cout << "invalid" << endl;
            return;
        }
    }
    string t;
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] == 'U' || s[i] == '5')
        {
            t += s[i];
        }
    }
    for (int i = 1; i < (int)t.size(); i++)
    {
        if (t[i - 1] == '5' && t[i] == '5')
        {
            cout << "invalid" << endl;
            return;
        }
    }

    cout << "valid" << endl;
}
