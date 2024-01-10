// 2023/07/08 14:02:01
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
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const int N = 1000005;

// size_t find_end(const string& s)
// {
//     for (size_t i = s.size(); i--; )
//     {
//         if (s[i] == '0')
//             return i;
//     }
    
//     return -1;
// }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tt;
    cin >> tt;
    while (tt--)
    {
        size_t n, K;
        cin >> n >> K;
        string s;
        cin >> s;
        ll ans = 0;
        bool flag1 = 0, flag2 = 0;
        if (s[0] == '1')
            flag2 = 1;
        
        for (size_t i = s.size(); i--; )
        {
            if (s[i] == '1')
            {
                if (s.size() - 1 - i <= K && !flag1)
                {
                    s[i] = '0';
                    ans += 1;
                    K -= s.size() - 1 - i;
                    flag1 = 1;
                }
                else if (i <= K && !flag2)
                {
                    s[i] = '0';
                    ans += 10;
                    K -= i;
                    flag2 = 1;
                }
            }
        }

        if (s[0] == '1')
            ans += 10;
        
        for (size_t i = 1; i < s.size(); i++)
        {
            if (s[i] == '1')
                ans += 11;
        }

        cout << ans << '\n';


        
        // if (s.front() == '1')
        // {
            
        // }
        // else
        // {

        //     // for (size_t i = s.size(); i--; )
        //     // {
        //     //     if (s[i] == '1')
        //     //     {
        //     //         if (s.size() - 1 - i <= K)
        //     //         {
        //     //             s[i] = '0';
        //     //             ans += 1;
        //     //             break;
        //     //         }
        //     //     }
        //     // }

        //     // size_t end_index = find_end(s);
        //     // for (size_t i = end_index; i--; )
        //     // {
        //     //     if (s[i] == '1')
        //     //     {
        //     //         if (end_index - i <= K)
        //     //         {
        //     //             K -= end_index - i;
        //     //             end_index--;
        //     //         }
        //     //         else
        //     //         {
        //     //             break;
        //     //         }
        //     //     }
        //     // }
        //     // for (size_t i = 0; i < s.size(); i++)
        //     // {
        //     //     if (s[i] == '1')
        //     //     {
        //     //         if (i <= end_index)
        //     //         {
                        
        //     //         }
        //     //     }
        //     // }
        // }
    }
    cout << endl;
    return 0;
}