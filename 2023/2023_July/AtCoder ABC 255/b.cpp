// 2023/07/29 18:36:11
#ifndef DEBUG
#pragma GCC optimize(2)
#endif
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
const int INF = 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const int N = 1000005;

struct Point
{
    double x, y;
    double dis;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    set<int> s;
    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        x--;
        s.emplace(x);
    }

    vector<Point> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> b[i].x >> b[i].y;
        if (s.count(i) != 0)
            b[i].dis = 0.0;
        else
            b[i].dis = 1e18;
    }

    double ans = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (fabs(b[i].dis - 0.0) < 1e-6)
        {
            continue;
        }

        for (int x : s)
        {
            b[i].dis = min(b[i].dis, sqrt((b[i].x - b[x].x) * (b[i].x - b[x].x) + (b[i].y - b[x].y) * (b[i].y - b[x].y)));
        }
        ans = max(ans, b[i].dis);
    }

    cout << setprecision(12) << fixed;
    cout << ans << '\n';


    cout << endl;
    return 0;
}