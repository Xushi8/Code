// // 2023/09/27 15:21:15
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
// #include <array>
// #include <fstream>
// using namespace std;

// using ll = long long;
// using pii = pair<int, int>;
// constexpr int N = 1000005;


// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int n, m;
//     cin >> n >> m;
//     string s;
//     cin >> s;
//     for (char& ch : s)
//     {
//         ch -= 'a';
//     }
    
//     int len = n - n / 2;
//     vector<int> adds;
//     int cnt = 0;
//     while (len < m)
//     {
//         string tmp = s.substr(0, n / 2) + s + s.substr(n / 2);
//         s = move(tmp);
//         adds.emplace_back(len);
//         cnt++;
//         n *= 2;
//         len = n - n / 2;
//     }

//     for (int length : adds)
//     {
//         for (size_t i = s.size() - 1, j = 0; j < length; j++, i--)
//         {
//             s[i] = (s[i] + 1) % 26;
//         }
//     }


//     for (int k = 0; k < 26; k++)
//     {
//         string tmp = s;
//         for (size_t i = 0; i < s.size(); i++)
//         {
//             tmp[i] = (tmp[i] + cnt + k) % 26;
//             tmp[i] += 'a';
//         }

//         string ans(tmp.rbegin(), tmp.rbegin() + m);
//         cout << ans << ' ' << k << '\n';
//     }

// #ifdef LOCAL
//     cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
// #endif
//     cout << endl;
//     return 0;
// }

// 2023/09/27 16:11:30
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
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 1000005;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int cnt = 0;
    while ((int)s.size() / 2 < m)
    {
        cnt++;
        string tmp = s.substr(0, s.size() / 2) + s;
        string tmp1 = s.substr(s.size() / 2);
        for (char& ch : tmp1)
            ch = (ch - 'a' + 1) % 26 + 'a';
        tmp += move(tmp1);
        s = move(tmp);
    }
    string s1 = move(s);
    s = "";
    for (int i = s1.size() - m; i < s1.size(); i++)
    {
        s += s1[i];
    }
    cnt = 16 - cnt;
    for (int i = 0; i < s.size(); i++)
    {
        cout.put((s[i] - 'a' + cnt) % 26 + 'a');
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}