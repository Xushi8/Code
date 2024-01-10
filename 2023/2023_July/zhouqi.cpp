// 2023/07/06 16:20:47
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
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const int N = 1000005;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;
    size_t ans = s.size();
    for (size_t i = 1; i <= s.size() / 2; i++) // zhouqi
    {
        bool flag = false;
        for (size_t j = 0; j < i; j++) // qishiweizhi
        {
            for (size_t k = j; k + i < s.size(); k += i)
            {
                if (s[k] != s[k + i])
                {
                    flag = true;
                    goto out;
                }
            }
        }
    out:
        if (!flag)
        {
            ans = i;
            break;
        }
    }

    cout << ans << '\n';

    cout << endl;
    return 0;
}