// 2023/11/24 20:53:40
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
constexpr int N = 10005;

set<int> st[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        while (m--)
        {
            int x;
            cin >> x;
            st[i].emplace(x);
        }
    }

    int q;
    cin >> q;
    cout << setprecision(1) << fixed;
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        size_t gong = 0;
        for (int x : st[a])
        {
            if (st[b].count(x) == 1)
            {
                gong++;
            }
        }

        size_t nt = st[a].size() + st[b].size() - gong;
        cout << 100. * gong / nt << '%' << '\n';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}