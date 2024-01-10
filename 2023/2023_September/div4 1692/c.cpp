// 2023/09/17 11:34:26
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
using pii = pair<int, int>;
constexpr int N = 1000005;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tt;
    cin >> tt;
    char s[10][10];
    while (tt--)
    {
        for (int i = 1; i < 9; i++)
        {
            cin >> (s[i] + 1);
        }
        for (int i = 1; i < 9; i++)
        {
            for (int j = 1; j < 9; j++)
            {
                if (s[i][j] == '#' && s[i - 1][j - 1] == '#' && s[i - 1][j + 1] == '#' && s[i + 1][j + 1] == '#' && s[i + 1][j - 1] == '#')
                {
                    cout << i << ' ' << j << '\n';
                    goto next;
                }
            }
        }
    next:
        ;
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}