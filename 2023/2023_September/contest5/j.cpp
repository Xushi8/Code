// 2023/09/13 15:51:41
#include <iostream>
#include <cstdio>
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

inline int read()
{
    int x = 0, f = 1;
    int ch = getchar();
    while (ch < '0' || ch>'9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        x = x * 10 + ch - '0', ch = getchar();
    return x * f;
}

inline void write(int x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t, k;
    t = read();
    while (t--) {
        k = read();
        if (k == 1) write(0), putchar('\n');
        else if (k <= 2) write(1), putchar('\n');
        else if (k <= 6) write(2), putchar('\n');
        else if (k <= 18) write(3), putchar('\n');
        else if (k <= 50) write(4), putchar('\n');
        else if (k <= 130) write(5), putchar('\n');
        else if (k <= 322) write(6), putchar('\n');
        else if (k <= 770) write(7), putchar('\n');
        else if (k <= 1794) write(8), putchar('\n');
        else if (k <= 4098) write(9), putchar('\n');
        else if (k <= 9218) write(10), putchar('\n');
        else if (k <= 20482) write(11), putchar('\n');
        else if (k <= 45058) write(12), putchar('\n');
        else if (k <= 98306) write(13), putchar('\n');
        else if (k <= 212994) write(14), putchar('\n');
        else if (k <= 458754) write(15), putchar('\n');
        else if (k <= 983042) write(16), putchar('\n');
        else if (k <= 2097154) write(17), putchar('\n');
        else if (k <= 4456450) write(18), putchar('\n');
        else if (k <= 9437186) write(19), putchar('\n');
        else if (k <= 19922946) write(20), putchar('\n');
        else if (k <= 41943042) write(21), putchar('\n');
        else if (k <= 88080386) write(22), putchar('\n');
        else if (k <= 184549378) write(23), putchar('\n');
        else if (k <= 385875970) write(24), putchar('\n');
        else if (k <= 805306370) write(25), putchar('\n');
        else if (k <= 1677721602) write(26), putchar('\n');
        else if (k <= 3489660930) write(27), putchar('\n');
        else if (k <= 7247757314) write(28), putchar('\n');
        else write(29), putchar('\n');
    }
    

    return 0;
}