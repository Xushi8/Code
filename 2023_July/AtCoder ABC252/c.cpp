// 2023/07/06 20:17:52
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
    
    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int ans = INF;
    for (int i = '0'; i <= '9'; i++) // 
    {
        set<int> s;
        for (int j = 0; j < n; j++)
        {
            int target;
            for (int k = 0; k < 10; k++)
            {
                if (arr[j][k] == i)
                {
                    target = k;
                    break;
                }
            }
            while (s.count(target) != 0)
            {
                target += 10;
            }
            s.insert(target);
        }
        int sum = *max_element(s.begin(), s.end());
        ans = min(ans, sum);
    }

    cout << ans << '\n';

    cout << endl;
    return 0;
}