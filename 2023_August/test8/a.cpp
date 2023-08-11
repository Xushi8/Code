// // 2023/08/10 08:38:04
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <cstdint>
// #include <vector>
// #include <string>
// #include <set>
// #include <map>
// #include <unordered_map>
// #include <unordered_set>
// #include <queue>
// #include <functional>
// #include <iomanip>
// #include <cmath>
// #include <stack>
// using namespace std;

// using ll = long long;
// using ull = unsigned long long;
// using pii = pair<int, int>;
// const int INF = 0x3f3f3f3f;
// const int MOD = (int)(1e9 + 7);
// const int N = 1000005;

// void solve(const string& s)
// {
//     int len = (int)s.size();
//     for (int i = 1; i <= len; i++)
//     {
//         if (len % i != 0)
//             continue;

//         bool flag = 1;
//         for (int j = 0; j < i; j++)
//         {
//             for (int k = j; k < len - i; k += i)
//             {
//                 if (s[k] != s[k + i])
//                 {
//                     flag = 0;
//                     goto out;
//                 }
//             }
//         }

//     out:
//         if (flag)
//         {
//             cout << len / i << '\n';
//             return;
//         }
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     string s;
//     while (cin >> s && s[0] != '.')
//     {
//         solve(s);
//     }

// #ifdef LOCAL
//     cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
// #endif
//     cout << flush;
//     return 0;
// }

// 2023/08/11 11:15:37
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
int nex[N];

void get_nex(const string& s)
{
    nex[0] = -1;
    for (int i = 0, j = -1; i < (int)s.size(); )
    {
        if (j == -1 || s[i] == s[j])
        {
            i++; j++;
            nex[i] = j;
        }
        else
        {
            j = nex[j];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    while (cin >> s && s[0] != '.')
    {
        get_nex(s);
        // cout << s.size() / (s.size() - nex[s.size()]) << '\n';
        vector<int> arr;
        int t = (int)s.size() - 1;
        while (t != -1)
        {
            if (s[t] == s.back())
                arr.emplace_back(t + 1);
            
            t = nex[t];
        }

        for (auto it = arr.rbegin(); it != arr.rend(); it++)
        {
            cout << *it << ' ';
        }

        cout << '\n';

        // cout << s.size() - nex[s.size()] << ' ';

        cout << '\n';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}