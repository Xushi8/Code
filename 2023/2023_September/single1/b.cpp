// 2023/09/30 16:09:00
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

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    int cnt = 0;
    int ans = 4;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cnt += s[i][j] == 'A';
        }
    }
    if (cnt == n * m)
        ans = 0;
    if (cnt == 0)
    {
        cout << "MORTAL\n";
        return;
    }

    cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cnt += s[i][0] == 'A';
    }
    if (cnt == n)
        ans = min(ans, 1);
    if (cnt > 0)
        ans = min(ans, 3);

    cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cnt += s[i][m - 1] == 'A';
    }
    if (cnt == n)
        ans = min(ans, 1);
    if (cnt > 0)
        ans = min(ans, 3);

    cnt = 0;
    for (int j = 0; j < m; j++)
    {
        cnt += s[0][j] == 'A';
    }
    if (cnt == m)
        ans = min(ans, 1);
    if (cnt > 0)
        ans = min(ans, 3);

    cnt = 0;
    for (int j = 0; j < m; j++)
    {
        cnt += s[n - 1][j] == 'A';
    }
    if (cnt == m)
        ans = min(ans, 1);
    if (cnt > 0)
        ans = min(ans, 3);

    if (s[0][0] == 'A' || s[n - 1][0] == 'A' || s[0][m - 1] == 'A' || s[n - 1][m - 1] == 'A')
        ans = min(ans, 2);

    for (int i = 0; i < n; i++)
    {
        cnt = 0;
        for (int j = 0; j < m; j++)
        {
            cnt += s[i][j] == 'A';
        }
        if (cnt == m)
            ans = min(ans, 2);
    }

    for (int j = 0; j < m; j++)
    {
        cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cnt += s[i][j] == 'A';
        }
        if (cnt == n)
        {
            ans = min(ans, 2);
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