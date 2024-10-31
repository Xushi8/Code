// // 2024/10/23 14:45:22
// #ifdef LOCAL
// #include <basic_std_lib.h>
// #else
// #include <bits/stdc++.h>
// #endif
// using namespace std;
// using i64 = int64_t;
// using u64 = uint64_t;
// using pii = pair<int, int>;
// using pll = pair<i64, i64>;
// constexpr int N = 1e6 + 6;

// void solve(string s)
// {
//     auto init = [](string s)
//     {
//         string res;
//         res.reserve(s.size() * 3 + 5);
//         res += "$#";
//         for (auto ch : s)
//         {
//             res += ch;
//             res += '#';
//         }
//         return res;
//     };

//     string ss = init(s);
//     vector<int> p(ss.size() * 2 + 5, 1);
//     const int size = ss.size();
//     ss += "!!!";
//     int ans = -1;
//     int id;
//     int maxx = 0;

//     int my_ans = 1;
//     for (int i = 1; i <= size; i++)
//     {
//         if (i < maxx)
//         {
//             p[i] = min(p[2 * id - 1], maxx - i);
//         }
//         while (ss[i - p[i]] == ss[i + p[i]])
//         {
//             p[i]++;
//         }

//         if (maxx < i + p[i])
//         {
//             id = i;
//             maxx = i + p[i];
//         }
//         ans = max(ans, p[i] - 1);

//         if (i + p[i] == size)
//         {
//             my_ans = max(my_ans, p[i] - 1);
//         }
//     }

//     string t = s.substr(0, s.size() - my_ans);
//     if (t.size() == s.size())
//     {
//         t.clear();
//     }
//     s += t;
//     cout << s << '\n';
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     string s;
//     while (cin >> s)
//     {
//         solve(s);
//     }

// #ifdef LOCAL
//     cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
// #endif
//     return 0;
// }

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

constexpr int N = 1e6 + 5;

char s[N];
char s_new[N * 2];
int p[N * 2];

int init()
{
    int len = strlen(s);
    s_new[0] = '$';
    s_new[1] = '#';
    int j = 2;
    for (int i = 0; i < len; i++)
    {
        s_new[j++] = s[i];
        s_new[j++] = '#';
    }
    s_new[j] = '\0';
    return j;
}

void solve()
{
    int len = init();

    int max_len = -1; 
    int id;
    int mx = 0;

    int ans = 1;
    for (int i = 1; i <= len; i++)
    {
        if (i < mx)
            p[i] = min(p[2 * id - i], mx - i); 
        else
            p[i] = 1;
        while (s_new[i - p[i]] == s_new[i + p[i]]) 
            p[i]++;                                
        if (mx < i + p[i])
        {                 
            id = i;       
            mx = i + p[i]; 
        }
        max_len = max(max_len, p[i] - 1);

        if (i + p[i] == len)
        {
            ans = max(ans, p[i] - 1);
        }
    }

    // cerr << ans << '\n';

    int siz = strlen(s);
    if (ans != siz)
    {
        memcpy(s + siz, s, siz - ans);
        reverse(s + siz, s + siz + (siz - ans));
        s[siz + (siz - ans)] = '\0';
    }

    cout << s << '\n';
}

int main()
{
    while (cin >> s)
    {
        solve();
    }
}