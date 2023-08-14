// 2023/08/14 13:06:32
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

struct A
{
    A(int a_, int b_, int c_)
    {
        a = a_;
        b = b_;
        c = c_;
    }
    
    int a, b, c;
};
vector<A> ans;

void dfs(int n, int m, int beginx, int beginy, bool flag)
{
    if (n > m)
    {
        swap(n, m);
        swap(beginx, beginy);
        flag = !flag;
    }

    for (int i = 0; i < m; i += n)
    {
        int tx = beginx, ty = beginy;
        tx += 0;
        ty += i;
        if (flag)
        {
            // cout << ty << ' ' << tx << ' ' << n << '\n';
            ans.emplace_back(ty, tx, n);
        }
        else
        {
            // cout << tx << ' ' << ty << ' ' << n << '\n';
            ans.emplace_back(tx, ty, n);
        }
    }

    if (m % n != 0)
    {
        int tx = beginx;
        int ty = beginy + m / n * n;

        dfs(n, m % n, tx, ty, flag);
    }
}

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
        cout << "YES\n";
        if (n == m)
            cout << "0 0 " << n << '\n';
        else
        {
            dfs(n, m, 0, 0, false);
            cout << ans.size() << '\n';
            for (auto p : ans)
            {
                cout << p.a << ' ' << p.b << ' ' << p.c << '\n';
            }
        }
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}