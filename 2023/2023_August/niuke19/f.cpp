// 2023/08/18 14:04:52
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
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
constexpr int INF = 0x3f3f3f3f;
constexpr int MOD = (int)(1e9 + 7);
constexpr int N = 305;

int dp[N][N][N];
int sum[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, tim, k, m;
    cin >> n >> tim >> k >> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        sum[x]++;
    }

    for (int i = 1; i <= tim; i++)
    {
        sum[i] += sum[i - 1];
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}