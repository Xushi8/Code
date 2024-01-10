// 2023/08/19 20:13:33
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
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
constexpr int INF = 0x3f3f3f3f;
constexpr int MOD = (int)(1e9 + 7);
constexpr int N = 1000005;
int n;
pii arr[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].second >> arr[i].first;
    }

    sort(arr, arr + n, greater<pii>());
    int ans = 0;
    for (int i = 0; i < n; )
    {
        int flavor = arr[i].second, now = arr[i].first;
        int j;
        int mx = arr[i + 1].first / 2;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j].second != flavor)
            {
                mx = max(mx, arr[j].first);
                break;
            }
        }
        now += mx;
        ans = max(ans, now);
        i = j;
    }

    cout << ans << '\n';
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}