// 2023/11/01 14:10:14
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

pii arr[4] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int ans = 0;
    for (int k = 1; k < (1 << 4); k++)
    {
        vector<int> na, nb;
        for (int i = 0; i < 4; i++)
        {
            if ((k >> i) & 1)
            {
                auto [x, y] = arr[i];
                if (count(na.begin(), na.end(), x) == 0)
                {
                    na.push_back(x);
                }
                if (count(nb.begin(), nb.end(), y) == 0)
                {
                    nb.push_back(y);
                }
            }
        }
        sort(na.begin(), na.end());
        sort(nb.begin(), nb.end());
        if (na == a && nb == b)
        {
            ans++;
        }
    }

    cout << ans << '\n';
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