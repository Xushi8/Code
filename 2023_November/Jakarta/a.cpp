// 2023/12/03 12:06:05
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
string s[3];

int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
string ans = "CCC";

void func(int x, int y, int deep, string now, int x1 = -1, int y1 = -1)
{
    now += s[x][y];
    if (deep == 2)
    {
        ans = min(ans, now);
        return;
    }
    for (int i = 0; i < 8; i++)
    {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (0 <= tx && tx < 3 && 0 <= ty && ty < 3)
        {
            if (deep == 0)
            {
                func(tx, ty, deep + 1, now, x, y);
            }
            else if (deep == 1)
            {
                if (tx == x1 && ty == y1)
                {
                    continue;
                }
                func(tx, ty, deep + 1, now, x1, y1);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < 3; i++)
    {
        cin >> s[i];
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            func(i, j, 0, string());
        }
    }

    cout << ans << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}