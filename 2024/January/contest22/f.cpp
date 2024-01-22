// 2024/01/22 09:58:31
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

int bx = 1, by = 1;
void dfs(int n, int m, int deg)
{
    while (deg < 0)
        deg += 360;
    while (deg >= 360)
        deg -= 360;

    if (n == 1)
    {
        if (deg == 0)
        {
            if (m == 1)
            {
            }
            else if (m == 2)
            {
                by++;
            }
            else if (m == 3)
            {
                bx++;
                by++;
            }
            else
            {
                bx++;
            }
        }
        else if (deg == 90)
        {
            if (m == 1)
            {
            }
            else if (m == 2)
            {
                bx++;
            }
            else if (m == 3)
            {
                bx++;
                by++;
            }
            else
            {
                by++;
            }
        }
        else if (deg == 180)
        {
            if (m == 1)
            {
                bx++;
                by++;
            }
            else if (m == 2)
            {
                bx++;
            }
            else if (m == 3)
            {
            }
            else
            {
                by++;
            }
        }
        else
        {
            if (m == 1)
            {
                bx++;
                by++;
            }
            else if (m == 2)
            {
                by++;
            }
            else if (m == 3)
            {
            }
            else
            {
                bx++;
            }
        }
        cout << bx << ' ' << by << endl;
        return;
    }

    int tmp = n - 1;
    if (deg == 0)
    {
        if (0 < m && m <= (1 << tmp * 2))
        {
            dfs(n - 1, m, deg + 90);
        }
        else if ((1 << tmp * 2) < m && m <= (1 << tmp * 2) * 2)
        {
            by += 1 << tmp;
            m -= (1 << tmp * 2);
            dfs(n - 1, m, deg);
        }
        else if ((1 << tmp * 2) * 2 < m && m <= (1 << tmp * 2) * 3)
        {
            bx += 1 << tmp;
            by += 1 << tmp;
            m -= (1 << tmp * 2) * 2;
            dfs(n - 1, m, deg);
        }
        else
        {
            bx += 1 << tmp;
            m -= (1 << tmp * 2) * 3;
            dfs(n - 1, m, deg - 90);
        }
    }
    else if (deg == 90)
    {
        if (0 < m && m <= (1 << tmp * 2))
        {
            dfs(n - 1, m, 0);
        }
        else if ((1 << tmp * 2) < m && m <= (1 << tmp * 2) * 2)
        {
            bx += 1 << tmp;
            m -= (1 << tmp * 2);
            dfs(n - 1, m, 90);
        }
        else if ((1 << tmp * 2) * 2 < m && m <= (1 << tmp * 2) * 3)
        {
            bx += 1 << tmp;
            by += 1 << tmp;
            m -= (1 << tmp * 2) * 2;
            dfs(n - 1, m, 90);
        }
        else
        {
            by += 1 << tmp;
            m -= (1 << tmp * 2) * 3;
            dfs(n - 1, m, 180);
        }
    }
    else if (deg == 180)
    {
        if (0 < m && m <= (1 << tmp * 2))
        {
            bx += 1 << tmp;
            by += 1 << tmp;
            dfs(n - 1, m, 180);
        }
        else if ((1 << tmp * 2) < m && m <= (1 << tmp * 2) * 2)
        {
            bx += 1 << tmp;
            m -= (1 << tmp * 2);
            dfs(n - 1, m, 90);
        }
        else if ((1 << tmp * 2) * 2 < m && m <= (1 << tmp * 2) * 3)
        {
            m -= (1 << tmp * 2) * 2;
            dfs(n - 1, m, -90);
        }
        else
        {
            by += 1 << tmp;
            m -= (1 << tmp * 2) * 3;
            dfs(n - 1, m, 180);
        }
    }
    else
    {
        if (0 < m && m <= (1 << tmp * 2))
        {
            bx += 1 << tmp;
            by += 1 << tmp;
            dfs(n - 1, m, -90);
        }
        else if ((1 << tmp * 2) < m && m <= (1 << tmp * 2) * 2)
        {
            by += 1 << tmp;
            m -= (1 << tmp * 2);
            dfs(n - 1, m, -90);
        }
        else if ((1 << tmp * 2) * 2 < m && m <= (1 << tmp * 2) * 3)
        {
            m -= (1 << tmp * 2) * 2;
            dfs(n - 1, m, -180);
        }
        else
        {
            bx += 1 << tmp;
            m -= (1 << tmp * 2) * 3;
            dfs(n - 1, m, 0);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    // int n, m;
    // cin >> n >> m;
    // dfs(n, m, 0);

    for (int i = 1; i <= 64; i++)
    {
        bx = 1, by = 1;
        cout << i << ' ';
        dfs(3, i, 0);
    }

    // dfs(3, 13, 0);

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}