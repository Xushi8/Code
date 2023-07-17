// 2023/07/16 15:51:24
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
#include <bitset>
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
    while (tt--)
    {
        int n, K;
        cin >> n >> K;
        vector<int> mod(K, 0);
        ll ans = 0;
        for (int i = 0, x; i < n; i++)
        {
            cin >> x;
            ans += x / K;
            mod[x % K]++;
        }
        int j = 1;
        for (int i = K - 1; i >= 0; i--)
        {
            j = max(j, K - i);
            while (mod[i] > 0 && j < i)
            {
                int minus = min(mod[i], mod[j]);
                mod[i] -= minus;
                mod[j] -= minus;
                ans += minus;
                if (mod[i] == 0)
                    break;
                
                j++;
            }
            if (j == i)
            {
                ans += mod[i] / 2;
                break;
            }
        }
        
        cout << ans << '\n';
    }


    cout << endl;
    return 0;
}