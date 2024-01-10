// 2023/08/16 17:24:47
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
const int INF = 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const int N = 1005;

int arr[N][N];
int dp[N][N];

struct Point
{
    int x, y, w;
    Point(int a, int b, int c)
    {
        x = a;
        y = b;
        w = c;
    }
};

// bool operator < (const array<int, 4>& a, const array<int, 4>& b)
// {
//     return a[3] < b[3];
// }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;
    while (tt--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }

        priority_queue<array<int, 4>> que;
        que.push({ 1, 1, 1, 1 });
        que.push({ 1, 2, 3, 4 });
        while (!que.empty())
        {
            array<int, 4> p = que.top(); que.pop();
            cout << ' ' << p[0] << ' ' << p[1] << ' ' << p[2] << ' ' << p[3] << '\n';
        }
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}