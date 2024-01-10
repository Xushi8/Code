// 2023/10/04 14:44:51
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
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 1000005;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<pii> b(m);
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        b[i] = { x, i };
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<>());

    auto check = [&](int val) -> bool
        {
            int i = 0, j = val - 1;
            for (int begins = 0, tim = 0; begins < n + val; begins += k, tim++)
            {
                for (int cnt = 0; cnt < k && cnt + begins < n + val; cnt++)
                {
                    int use;
                    if (i == n)
                        use = b[j--].first;
                    else if (j == -1)
                        use = a[i++];
                    else if (a[i] < b[j].first)
                        use = a[i++];
                    else
                        use = b[j--].first;

                    if (use < tim)
                        return false;
                }
            }

            return true;
        };



    int l = 0, r = m;
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        if (check(mid + 1))
            l = mid + 1;
        else
            r = mid;
    }

    if (!check(0))
    {
        cout << -1 << endl;
        return 0;
    }

    cout << l << '\n';
    for (int i = 0; i < l; i++)
    {
        cout << b[i].second + 1 << ' ';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}