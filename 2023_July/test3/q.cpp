// 2023/07/25 17:25:55
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


map<pair<pair<int, int>, int>, int> m;
int arr[50][50];
int n;
ll ans;

void dfsl(int x, int y, int val)
{
    val ^= arr[x][y];
    
    if (x + y == 1 + n)
    {
        m[{{x, y}, val}]++;
        return;
    }

    if (x + 1 <= n)
        dfsl(x + 1, y, val);
    if (y + 1 <= n)
        dfsl(x, y + 1, val);
}

void dfsr(int x, int y, int val)
{

    if (x + y == 1 + n)
    {
        ans += m[{{x, y}, val}];
        return;
    }

    val ^= arr[x][y];
    if (x - 1 >= 1)
        dfsr(x - 1, y, val);
    if (y - 1 >= 1)
        dfsr(x, y - 1, val);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> arr[i][j];

    dfsl(1, 1, 0);
    dfsr(n, n, 0);

    cout << ans << '\n';

    cout << endl;
    return 0;
}