// 2023/07/06 16:05:23
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
    int n, K;
    cin >> n >> K >> s;
    int ans = n;
    int cnt[26];    
    for (int i = 1; i <= n; i++)
    {
        if (n % i != 0)
            continue;
        
        int maxn = 0;
        for (int j = 0; j < i; j++) // qishi
        {
            memset(cnt, 0, sizeof(cnt));
            for (int k = j; k < n; k += i)
            {
                cnt[s[k] - 'a']++;
            }
            int max_index = (int)(max_element(cnt, cnt + 26) - cnt);
            maxn += n / i - cnt[max_index];
        }
        if (maxn <= K)
        {
            ans = i;
            break;
        }
    }

    cout << ans << '\n';

    cout << endl;
    return 0;
}