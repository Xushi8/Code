// 2023/07/05 19:24:05
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
const int N = 100005;

bool used[10000005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, W;
    cin >> n >> W;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= W && !used[arr[i]])
        {
            ans++;
            used[arr[i]] = 1;
        }
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] <= W && !used[arr[i] + arr[j]])
            {
                ans++;
                used[arr[i] + arr[j]] = 1;
            }
            for (int k = j + 1; k < n; k++)
            {
                if (arr[i] + arr[j] + arr[k] <= W && !used[arr[i] + arr[j] + arr[k]])
                {
                    ans++;
                    used[arr[i] + arr[j] + arr[k]] = 1;
                }
            }
        }
    }

    cout << ans << '\n';

    cout << endl;
    return 0;
}