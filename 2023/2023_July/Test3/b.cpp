// 2023/07/26 09:12:44
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tt;
    cin >> tt;
    while(tt--)
    {
        int n;
        char ch;
        cin >> n >> ch;
        string str;
        cin >> str;
        str += str;

        int ans = -1;
        if (ch == 'g')
        {
            cout << 0 << '\n';
            continue;
        }

        for (size_t i = 0; i < str.size(); i++)
        {
            if (str[i] == ch)
            {
                int cnt = 1;
                size_t j;
                for (j = i + 1; j < str.size(); j++)
                {
                    if (str[j] == 'g')
                        break;

                    cnt++;
                }
                ans = max(ans, cnt);
                i = j;
            }
        }

        cout << ans << '\n';
    }
    
    cout << endl;
    return 0;
}