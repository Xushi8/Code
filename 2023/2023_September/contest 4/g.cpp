// 2023/09/12 16:03:32
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

int a[N], d[N];
vector<pii> rg[N];
int n;

bool check(int x)
{
    priority_queue<pii, vector<pii>, greater<pii>> que;
    for (int i = 0; i < n; i++)
    {
        for (auto [r, cnt] : rg[i])
        {
            if (cnt > 0)
                que.emplace(r, cnt);
        }
        int t = x;
        while (!que.empty() && t > 0)
        {
            auto [j, cnt] = que.top(); que.pop();
            if (j < i)
                return 0;
            int minus = min(cnt, t);
            cnt -= minus; t -= minus;
            if (cnt != 0)
            {
                que.emplace(j, cnt);
            }
        }
    }

    return que.empty();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
        int l = max(0, i - d[i]);
        int r = min(n - 1, i + d[i]);
        rg[l].emplace_back(r, a[i]);
    }

    int l = 0, r = (int)1e9;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << l << '\n';

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}