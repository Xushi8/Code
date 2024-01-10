// 2023/09/12 18:54:52
#ifndef LOCAL
#pragma GCC optimize(2)
#endif
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <iomanip>
#include <stack>
using namespace std;

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
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


typedef long long ll;
typedef pair<int, int> pii;
const int N = 1000005;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tt;
    tt = read();
    while (tt--)
    {
        int l, n;
        l = read(), n = read();
        int maxx = 0, minn = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            x = read();
            minn = max(minn, min(x, l - x));
            maxx = max(maxx, max(x, l - x));
        }
        cout << minn << ' ' << maxx << '\n';
    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}