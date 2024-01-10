// 2023/07/15 19:58:42
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
    
    int n, p, q;
    cin >> n >> p >> q;
    int ans = p;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        // ans = min(ans, p - q + x);
        ans = min(ans, q + x);
    }
    cout << ans << '\n';

    cout << endl;
    return 0;
}