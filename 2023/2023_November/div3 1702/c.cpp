// 2023/11/21 16:40:34
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

void solve()
{
    int n, q;
    cin >> n >> q;
    map<int, int> fi, la;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (fi.count(x) == 0)
        {
            fi[x] = i;
        }
        la[x] = i;
    }

    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        bool flag;
        if (fi.count(l) == 0 || la.count(r) == 0)
        {
            flag = 0;
        }
        else
        {
            flag = fi[l] <= la[r];
        }
        cout << (flag ? "YES" : "NO") << '\n';
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
        solve();
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}