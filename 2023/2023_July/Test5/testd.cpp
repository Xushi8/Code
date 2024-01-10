// 2023/08/02 11:13:12
#ifndef LOCAL
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

bool dfs(int i, int j, int sum, bool turn)
{
    if (i == 0)
        return sum % 2 == 0;
    if (j == 0)
    {
        i %= 4;
        if (turn)
        {
            if (i == 1 || i == 2)
                return (sum + 1) % 2 == 0;
            else
                return sum % 2 == 0;
        }
        else
        {
            if (i == 2 || i == 3)
                return (sum + 1) % 2 == 0;
            else
                return sum % 2 == 0;
        }
    }

    if (turn)
    {
        return dfs(i - 1, j, sum + 1, !turn) || dfs(i, j - 1, sum, !turn);
    }
    else
    {
        return !(dfs(i - 1, j, sum, !turn) || dfs(i, j - 1, sum, !turn));
    }



    // if (i == 0)
    //     return sum % 2 == 0;
    // if (j == 0)
    //     return !((i & 1) ^ (sum & 1));

    // if (i == 1 && j == 1)
    // {
    //     return dfs(i - 1, j - 1, sum + 1) || dfs(i - 1, j - 1, sum);
    // }
    // else if (i == 1 && j != 1)
    // {
    //     return dfs(i - 1, j - 1, sum + 1) || dfs(i - 1, j - 1, sum) ||
    //         dfs(i, j - 2, sum);
    // }
    // else if (i != 1 && j == 1)
    // {
    //     return dfs(i - 1, j - 1, sum + 1) || dfs(i - 1, j - 1, sum) ||
    //         dfs(i - 2, j, sum + 1);
    // }
    // else
    // {
    //     return dfs(i - 1, j - 1, sum + 1) || dfs(i - 1, j - 1, sum) ||
    //     dfs(i - 2, j, sum + 1) || dfs(i, j - 2, sum);
    // }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << i << ' ' << j << ' ' << dfs(i, j, 0, 1) << '\n';
        }
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}