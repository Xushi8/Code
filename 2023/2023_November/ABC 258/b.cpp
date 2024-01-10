// 2023/11/05 15:46:13
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
#include <fstream>
#include <bitset>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 1000005;

int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};

vector<string> s(100);
int n;

ll check(int x, int y, int k)
{
    ll res = 0;
    res = res * 10 + s[x][y] - '0';
    int tx = x + dx[k];
    int ty = y + dy[k];
    while (1)
    {
        if (tx >= n)
            tx = 0;
        if (tx < 0)
            tx = n - 1;
        if (ty >= n)
            ty = 0;
        if (ty < 0)
            ty = n - 1;

        if (tx == x && ty == y)
        {
            break;
        }

        res = res * 10 + s[tx][ty] - '0';

        tx += dx[k];
        ty += dy[k];
    }

    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < 8; k++)
            {
                ans = max(ans, check(i, j, k));
            }
        }
    }

    cout << ans << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}